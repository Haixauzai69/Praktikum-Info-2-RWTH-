/*
 * Kreuzung.h
 *
 *  Created on: Dec 13, 2025
 *      Author: HaiPH
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_
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

class Kreuzung : public Simulationsobjekt
{
	private:
	vertagt::VListe<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle; // tankreserve an einer kreuzung

	public:
	Kreuzung() = default;
	Kreuzung(const std::string name, double tank);
	Kreuzung(Kreuzung& kreuzung) = delete;
	virtual ~Kreuzung() = default;
	static void vVerbinde(std::string hin, std::string ruck, double laenge, enum Tempolimit tempo, bool Ueberhol, Kreuzung& startkreuzung, Kreuzung& zielkreuzung);
	void vTanken(Fahrzeug& fzg);
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start);
	void vSimulieren(double dTimeStep);
};




#endif /* KREUZUNG_H_ */
