/*
 * Losfahren.cpp
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Fahrausnahme.h"
#include "Losfahren.h"

Losfahren::Losfahren(Weg& weg, Fahrzeug& fahrzeug) : Fahrausnahme(weg , fahrzeug)
{
	std::cout << "Exception Handling type Losfahren" << std::endl;
}

void Losfahren::vBearbeiten()
{
	std::cout << "Parkendes Fahrzeug fährt ab" << std::endl;
	std::cout << "Fahrzeug: " << p_rFahrzeug.sGetName() << " Strasse: " << p_rWeg.sGetName() << std::endl;

	p_rFahrzeug.vNeueStrecke(p_rWeg);
}



