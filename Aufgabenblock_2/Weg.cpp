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
#include "Weg.h"
#include "Tempolimit.h"
#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Car.h"

Weg::Weg(std::string name, double laenge, enum Tempolimit tempolimit, std::unique_ptr<Fahrzeug> fahrzeug)
{
	Simulationsobjekt::vSetName(name); // nice
	p_dLaenge = laenge;
	p_eTempolimit = tempolimit;
	p_pFahrzeuge.push_back(std::move(fahrzeug));
}

enum Tempolimit Weg::getTempolimit()
{
	return p_eTempolimit; // problematic because function returns double, but tempolimit is int
}

void Weg::vAddFahrzeug(std::unique_ptr<Fahrzeug> vehicle)
{
	p_pFahrzeuge.push_back(std::move(vehicle));
}

void Weg::vSimulieren(double dTimeStep)
{
	// init a list of unique pointers fahrzeuge
	// for (auto i : fahrzeuge)
	// Fahrzeug::vsimulieren for all
	for (auto& i : p_pFahrzeuge)
	{
		i->vSimulieren(0.5);
	}
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
	std::cout << std::setiosflags(std::ios::right);
	for (auto& i : p_pFahrzeuge)
	{
		std::cout << i->sGetName() << " ";
	}
}



