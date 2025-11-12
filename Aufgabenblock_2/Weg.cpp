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

Weg::Weg(std::string name, double laenge, enum Tempolimit tempolimit)
{
	Simulationsobjekt::vSetName(name); // nice
	p_dLaenge = laenge;
	p_eTempolimit = tempolimit;
}

double Weg::getTempolimit()
{
	return p_eTempolimit; // problematic because function returns double, but tempolimit is int
}

void Weg::vSimulieren() const
{
	// init a list of unique pointers fahrzeuge
	// for (auto i : fahrzeuge)
	// Fahrzeug::vsimulieren for all

	std::list<std::unique_ptr<Fahrzeug>> fahrzeuge;
	std::unique_ptr<Fahrzeug> car1 = std::make_unique<Car>(8, 55);
	fahrzeuge.push_back(car1);
	for (auto i : fahrzeuge)
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

void Weg::vAusgabe() const
{
	std::cout << std::setiosflags(std::ios::left)
			<< std::setw(5) << Simulationsobjekt::sGetName()
			<< std::setw(25) << Simulationsobjekt::iGetID()
			<< std::setw(25) << p_dLaenge
			<< std::setw(25) << // list fahrzeuge
			do (i->sGetName())
			while (auto i < p_pFahrzeuge)
			<< std::resetiosflags(std::ios::left) << std::endl
			<< std::string(100,'-') << std::endl;
}



