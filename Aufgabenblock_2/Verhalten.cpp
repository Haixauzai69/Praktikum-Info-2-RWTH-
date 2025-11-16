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

Verhalten::Verhalten(Weg& weg, std::string zustand)
{
	std::cout << "new verhalten is defined lmao" << std::endl;
	fahren = zustand;
}

double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (aFzg.dGeschwindigkeit() > 50)
	{
		std::cout << "Strafe weil zu schnell" << std::endl;
	}

	double strecke = 0;

	while(strecke < p_dLaenge)
	{
		strecke += aFzg.dGeschwindigkeit()*dZeitIntervall;
		aFzg.vAddStrecke(strecke);
	}
	std::cout << "Das Fahrzeug erreicht das Ende des Weges" << std::endl;
	strecke = p_dLaenge;
	return strecke;
}


