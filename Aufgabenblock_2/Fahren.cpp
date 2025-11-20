/*
 * Fahren.cpp
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"

Fahren::Fahren(Weg& weg) : Verhalten(weg)
{
	std::cout << "new Fahren is defined" << std::endl;
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (aFzg.dGeschwindigkeit() > 50)
	{
		std::cout << "Strafe weil zu schnell" << std::endl;
	}

	double rest = p_rWeg.dGetLaenge() - aFzg.getStreckenabschn();

	double strecke = (aFzg.dGeschwindigkeit())*dZeitIntervall;

	if (strecke > rest)
	{
		std::cout << "Das Fahrzeug erreicht das Ende des Weges" << std::endl; //streckenende
		strecke = rest;
	}
	return strecke;
}


