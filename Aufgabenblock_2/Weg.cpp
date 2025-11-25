/*
 * Weg.cpp
 *
 *  Created on: Nov 11, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include <ios>
#include <list>
#include <iterator>
#include "Weg.h"
#include "Tempolimit.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Car.h"

Weg::Weg(std::string name, double laenge, Tempolimit tempolimit)
{
	Simulationsobjekt::vSetName(name); // nice
	p_dLaenge = laenge;
	p_eTempolimit = tempolimit;
}

enum Tempolimit Weg::getTempolimit()
{
	return p_eTempolimit; // problematic because function returns double, but tempolimit is int
}

void Weg::vSimulieren(double dTimeStep)
{
	for (auto& i : p_pFahrzeuge)
	{
		i->vSimulieren(dTimeStep);
	}
	p_pFahrzeuge.vAktualisieren();
}

void Weg::vKopf() const
{
	std::cout << std::setiosflags(std::ios::left)
		<< std::setw(5) << "ID"
		<< std::setw(25) << "Name"
		<< std::setw(25) << "Laenge"
		<< std::setw(25) << "Fahrzeuge"
		<< std::resetiosflags(std::ios::left) << std::endl
		<< std::string(100,'-') << std::endl;
}

void Weg::vAusgabe(std::ostream& ausgabe) const
{
	Simulationsobjekt::vAusgabe(ausgabe);
	ausgabe << std::setw(20) << p_dLaenge
	<< std::setw(9);
	std::cout << std::setiosflags(std::ios::right) << std::setw(20);
	for (auto& i : p_pFahrzeuge)
	{
		std::cout << i->sGetName() << ", ";
	}
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug)
{
	std::cout << fahrzeug->sGetName() << " befindet sich auf " << Weg::sGetName() << std::endl;

	fahrzeug->vNeueStrecke(*this);

	p_pFahrzeuge.push_back(std::move(fahrzeug));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start)
{
	std::cout << fahrzeug->sGetName() << " parkt auf " << Weg::sGetName() << std::endl;

	fahrzeug->vNeueStrecke(*this, start);

	p_pFahrzeuge.push_front(std::move(fahrzeug));
}

double Weg::dGetLaenge() const
{
	return p_dLaenge;
}

const vertagt::VListe<std::unique_ptr<Fahrzeug>>& Weg::getFahrzeuge() const
{
	return p_pFahrzeuge;
}

std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fahrzeug)
{
	for(auto i = p_pFahrzeuge.begin(); i != p_pFahrzeuge.end(); ++i)
	{
		if (**i == fahrzeug)
		{
			std::unique_ptr<Fahrzeug> save = std::move(*i);
			p_pFahrzeuge.erase(i);
			p_pFahrzeuge.vAktualisieren();
			return save;
		}
	}
	std::cout << "Weg::pAbgabe returns nullptr" << std::endl;
	return nullptr;
}

