/*
 * Fahrrad.cpp
 *
 *  Created on: Oct 29, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Fahrzeug.h"
#include "Fahrrad.h"

Fahrrad::Fahrrad(const std::string& name, double maxSpeed) : Fahrzeug(name, maxSpeed)
{

}
double Fahrrad::dGeschwindigkeit() const
{
	double reduction_factor = std::pow(0.9, p_dGesamtStrecke / 20.0);
	double currentSpeed = p_dMaxGeschwindigkeit*reduction_factor;
	return std::max(12.0, currentSpeed);
}


