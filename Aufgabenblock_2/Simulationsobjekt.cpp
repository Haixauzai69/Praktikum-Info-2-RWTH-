/*
 * Simulationsobjekt.cpp
 *
 *  Created on: Nov 9, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include "Simulationsobjekt.h"

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

std::string Simulationsobjekt::sGetName()
{
	return p_sName;
}

int Simulationsobjekt::iGetID()
{
	return p_iID;
}


