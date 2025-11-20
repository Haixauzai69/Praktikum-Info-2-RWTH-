/*
 * Parken.cpp
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
#include "Parken.h"

Parken::Parken(Weg& weg, double dStartZeit) : Verhalten(weg)
{
	p_dStartZeitPunkt = dStartZeit;
}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (dGlobaleZeit < p_dStartZeitPunkt)
	{
		return 0.0;
	}
	std::cout << "Startpunkt erreicht" << std::endl; // losfahren

	return (aFzg.dGeschwindigkeit())*dZeitIntervall;
}


