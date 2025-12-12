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
#include <stdlib.h>
#include <stdexcept>
#include <exception>
#include "Streckenende.h"

Fahren::Fahren(Weg& weg) : Verhalten(weg)
{
	std::cout << "new Fahren is defined" << std::endl;
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if((this->getWeg()).bGetUeberhol() == true)
	{
		std::cout << "Es gibt einen Ueberholverbot" << std::endl;
	}

	double strecke = (aFzg.dGeschwindigkeit())*dZeitIntervall;

	if(strecke + aFzg.getStreckenabschn() > p_rWeg.dGetVirtuelleSchranke()) // woah woah woah wtf magie digga
	{
		strecke = p_rWeg.dGetVirtuelleSchranke() - aFzg.getStreckenabschn();
	}

	double rest = p_rWeg.dGetLaenge() - aFzg.getStreckenabschn();

	if (strecke > rest)
	{
		std::cout << "Das Fahrzeug erreicht das Ende des Weges" << std::endl;
		strecke = rest;
		throw Streckenende(p_rWeg, aFzg);
	}

	return strecke;
}


