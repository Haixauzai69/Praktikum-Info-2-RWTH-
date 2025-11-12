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
#include "Simulationsobjekt.h"

double dGlobaleZeit = 0.0;

std::string Simulationsobjekt::sGetName()
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




