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
#include <list>
#include "Tempolimit.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Car.h"
#include "Fahrrad.h"
#include "Kreuzung.h"

Kreuzung::Kreuzung(const std::string name, double tank)
{
	vSetName(name);
	p_dTankstelle = tank;
}

void Kreuzung::vVerbinde(std::string hin, std::string ruck, double laenge, enum Tempolimit tempo, bool Ueberhol, Kreuzung& startkreuzung, Kreuzung& zielkreuzung)
{

}

void Kreuzung::vTanken(Fahrzeug& fzg)
{
//	dtanken for the fahrzeug, minus the tankinhalt of the kreuzung
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start) // parkend auf anderen weg geben und fahrzeug auftanken
{
	// tanken, streckenende, abnahme, annahme auf parkend
}

void Kreuzung::vSimulieren(double dTimeStep)
{
//	vertagt::VListe<std::shared_ptr<Weg>> p_pWege simulieren
}


