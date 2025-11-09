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

void Simulationsobjekt::vAusgabe() const
{

}


