/*
 * Kreuzung.cpp
 *
 *  Created on: Dec 13, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string.h>
#include "Simulationsobjekt.h"
#include "vertagt_liste.h"
#include "vertagt_aktion.h"
#include <memory>
#include "Tempolimit.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Car.h"
#include "Fahrrad.h"
#include "Kreuzung.h"

Kreuzung::Kreuzung(Weg& weg, double tank)
{
	p_pWege.push_back(weg);
	p_dTankstelle = tank;
}



