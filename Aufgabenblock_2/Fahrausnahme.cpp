/*
 * Fahrausnahme.cpp
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

Fahrausnahme::Fahrausnahme(Weg& weg, Fahrzeug& fahrzeug) : p_rWeg(weg) , p_rFahrzeug(fahrzeug)
{
	std::cout << "Fahrausnahme erstellt" << std::endl;
}



