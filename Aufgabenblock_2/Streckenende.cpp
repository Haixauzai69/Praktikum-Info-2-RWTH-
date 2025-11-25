/*
 * Streckenende.cpp
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
#include "Streckenende.h"

Streckenende::Streckenende(Weg& weg, Fahrzeug& fahrzeug) : Fahrausnahme(weg , fahrzeug)
{
	std::cout << "Exception Handling type Streckenende" << std::endl;
}

void Streckenende::vBearbeiten()
{
	std::cout << "Fahrzeug erreicht das Ende des Weges (Exception) " << std::endl;
	std::cout << "Fahrzeug: " << p_rFahrzeug.sGetName() << " Strasse: " << p_rWeg.sGetName() << std::endl;

	std::unique_ptr<Fahrzeug> lokal = p_rWeg.pAbgabe(p_rFahrzeug);
	if(lokal == nullptr)
	{
		std::cout << "Streckenende working with nullptr" << std::endl;
	}
}



