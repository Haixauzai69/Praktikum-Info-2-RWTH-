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
#include "Kreuzung.h"
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

	p_rWeg.pGetZielKreuzung()->vTanken(p_rFahrzeug);

	std::shared_ptr<Weg> pNeuerWeg = p_rWeg.pGetZielKreuzung()->pZufaelligerWeg(p_rWeg);
	pNeuerWeg->vAnnahme(p_rWeg.pAbgabe(p_rFahrzeug));

	std::cout << "ZEIT      :" << dGlobaleZeit << std::endl;
	std::cout << "KREUZUNG  :" << p_rWeg.pGetZielKreuzung()->sGetName() << " " << p_rWeg.pGetZielKreuzung()->dGetTank() << std::endl;
	std::cout << "WECHSEL   :" << p_rWeg.sGetName() << " -> " << pNeuerWeg->sGetName() << std::endl;
	std::cout << "FAHRZEUG  :" << p_rFahrzeug << std::endl;
}



