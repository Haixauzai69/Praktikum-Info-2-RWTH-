/*
 * PKW.cpp
 *
 *  Created on: Oct 24, 2025
 *      Author: HaiPH
 */

#include <iostream>
#include <string>
#include "Fahrzeug.h"
#include "PKW.h"
#include <limits>
#include <iomanip>
#include <ios>
#include <algorithm>

Car::Car(double verbrauch, double tankvolumen) : Fahrzeug("Auto", 180.0)
{
	p_dVerbrauch = verbrauch;
	p_dTankvolumen = tankvolumen;
	p_dTankinhalt = tankvolumen/2;
}

double Car::dTanken(double dMenge)
{
	double vorher = p_dTankinhalt;
	if (dMenge == std::numeric_limits<double>::infinity())
	{
		p_dTankinhalt = p_dTankvolumen;
	}
	else
	{
		p_dTankinhalt = std::min(p_dTankvolumen, p_dTankinhalt + dMenge);
	}

	if (p_dTankinhalt > 0)
	{
		p_bEmpty = false;
	}
	return p_dTankinhalt - vorher;
}

void Car::vSimulieren(double dTimeStep) // how to make the car be fueled after being empty
{
	if (p_bEmpty == true)
	{
		std::cout << "Car is out of fuel" << std::endl;
		return;
	}

	double dVerbrauch = p_dVerbrauch * dTimeStep;
	double dStrecke = p_dMaxGeschwindigkeit * dTimeStep;

	if (p_dTankinhalt > dVerbrauch)
	{
		// enough fuel
		p_dTankinhalt -= dVerbrauch;
		p_dGesamtStrecke += dStrecke;
	}
	else
	{
		double dZeitbisleer = p_dTankinhalt / p_dVerbrauch;
		p_dGesamtStrecke += p_dMaxGeschwindigkeit * dZeitbisleer;
		p_dTankinhalt = 0.0;
		p_bEmpty = true;
		std::cout << "Car ran out of fuel" << std::endl;
	}
}

void Car::vAusgabe() const
{
//	Fahrzeug::vAusgabe();
	double dGesamtverbrauch = (p_dGesamtStrecke / 100.0) * p_dVerbrauch;

	    std::cout << std::setiosflags(std::ios::left)
				  << std::setw(5)  << Fahrzeug::getID()
				  << std::setw(15) << "Car_" << Fahrzeug::getID()
				  << std::setw(15) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
				  << std::setw(15) << std::fixed << std::setprecision(2) << p_dGesamtStrecke
				  << std::setw(15) << std::fixed << std::setprecision(2) << dGesamtverbrauch
				  << std::setw(15) << std::fixed << std::setprecision(2) << p_dTankinhalt
				  << std::setw(15) << std::fixed << std::setprecision(2) << dGeschwindigkeit()
				  << std::resetiosflags(std::ios::left) << std::endl;
}

