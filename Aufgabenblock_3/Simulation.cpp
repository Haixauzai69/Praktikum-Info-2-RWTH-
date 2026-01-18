/*
 * Simulation.cpp
 *
 *  Created on: Jan 18, 2026
 *      Author: HaiPH
 */

#include <iostream>
#include <string>
#include "Simulation.h"
#include "Kreuzung.h"
#include "Simulationsobjekt.h"

void Simulation::vEinlesen(std::istream& eingabe)
{
	std::string key;
	int zeile = 0;

	if (key == "KREUZUNG")
	{
		Kreuzung kreuzung;
		kreuzung.vEinlesen(eingabe);
		zeile++;
	}

	if (key == "STRASSE")
	{
		Weg weg;
		eingabe >> >> >> ;
		zeile++;
	}

	if (key == "PKW")
	{
		Car car;
		car.vEinlesen(eingabe);
		zeile++;
	}

	if (key == "FAHRRAD")
	{
		Fahrrad fahrrad;
		fahrrad.vEinlesen(eingabe);
		zeile++;
	}
}


