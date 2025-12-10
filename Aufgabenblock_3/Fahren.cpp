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
	double currentPos = aFzg.getStreckenabschn();
	double virtBarrier = p_rWeg.dGetVirtuelleSchranke();
	double speed = aFzg.dGeschwindigkeit();
	std::cout << "  Fahren::dStrecke for '" << aFzg.sGetName()
	          << "' pos=" << currentPos
	          << " virtBarrier=" << virtBarrier
	          << " speed=" << speed
	          << " dt=" << dZeitIntervall << "\n";

	if((this->getWeg()).bGetUeberhol() == true)
	{
		std::cout << "Es gibt einen Ueberholverbot" << std::endl;
	}

	double strecke = (aFzg.dGeschwindigkeit())*dZeitIntervall;

	double rest = p_rWeg.dGetVirtuelleSchranke() - aFzg.getStreckenabschn();

	if (strecke > rest)
	{
		std::cout << "Das Fahrzeug erreicht das Ende des Weges" << std::endl;
		strecke = rest;
		throw Streckenende(p_rWeg, aFzg);
	}

	std::cout << "   => computed strecke=" << strecke << ", rest=" << (virtBarrier - currentPos) << "\n";

	return strecke;
}


