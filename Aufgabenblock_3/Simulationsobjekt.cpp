/*
 * Simulationsobjekt.cpp
 *
 *  Created on: Nov 9, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include "Simulationsobjekt.h"

double dGlobaleZeit = 0.0;

std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& obj)
{
	obj.vAusgabe(out);
	return out;
}

std::istream& operator>>(std::istream& in, Simulationsobjekt& obj)
{
	obj.vEinlesen(in);
	return in;
}

std::string Simulationsobjekt::sGetName() const
{
	return p_sName;
}

int Simulationsobjekt::iGetID()
{
	return p_iID;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& vergleich)
{
	if (this->p_iID == vergleich.p_iID)
	{
		return true;
	}
	return false;
}

void Simulationsobjekt::vSetName(std::string something)
{
	p_sName = something;
}

void Simulationsobjekt::vAusgabe(std::ostream& ausgabe) const
{
	ausgabe << std::setiosflags(std::ios::left)
	              << std::setw(5)  << p_iID
	              << std::setw(25) << p_sName;
}

void Simulationsobjekt::vEinlesen(std::istream& eingabe)
{
	if (p_sName != "")
	{
		throw std::runtime_error("Runtime error: Simulationsobjekt already initialized");
	}

	std::string name;

	if (!(eingabe >> name))
	{
	    throw std::runtime_error("Runtime error: Failed to read Simulationsobjekt name");
	}

	p_sName = name;
}



