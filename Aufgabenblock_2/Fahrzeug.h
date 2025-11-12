/*
 * Fahrzeug.h
 *
 *  Created on: Oct 6, 2025
 *      Author: HaiPH
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <vector>
#include "Simulationsobjekt.h"

class Fahrzeug : public Simulationsobjekt
{
	protected:
		double p_dGesamtStrecke = 0;
		double p_dGesamtZeit = 0;
		double p_dMaxGeschwindigkeit;

	public:
		Fahrzeug(const std::string name, double max_geschwindigkeit);
		virtual ~Fahrzeug();

		double getMaxGeschwindigkeit() const;
		double getGesamtStrecke() const;

		virtual void vSimulieren(double dTimeStep);
		virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity())
		{
			return 0.0;
		}
		static void vKopf();
		virtual void vAusgabe(std::ostream& ausgabe) const;
		virtual double dGeschwindigkeit() const;
		bool operator<(const Fahrzeug& other) const;
		Fahrzeug& operator=(const Fahrzeug& other);
};

#endif /* FAHRZEUG_H_ */
