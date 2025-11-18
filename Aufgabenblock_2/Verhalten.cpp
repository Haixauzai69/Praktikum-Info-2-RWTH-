/*
 * Verhalten.cpp
 *
 *  Created on: Nov 12, 2025
 *      Author: HaiPH
 */

#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Verhalten.h"

Verhalten::Verhalten(Weg& weg) : p_rWeg(weg)
{
	std::cout << "new verhalten is defined lmao" << std::endl;
}

double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (aFzg.dGeschwindigkeit() > 50)
	{
		std::cout << "Strafe weil zu schnell" << std::endl;
	}

	double rest = p_rWeg.dGetLaenge() - aFzg.getStreckenabschn();

	double strecke = (aFzg.dGeschwindigkeit())*dZeitIntervall;

	if (strecke > rest)
	{
		std::cout << "Das Fahrzeug erreicht das Ende des Weges" << std::endl;
		strecke = rest;
	}
	return strecke;
}


