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


