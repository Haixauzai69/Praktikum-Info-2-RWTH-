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

extern double dGlobaleZeit;

class Fahrzeug
{
	private:
		std::string p_sName;
		static inline int p_iMaxID = 0;
		const int p_iID = p_iMaxID++;

	protected:
		double p_dGesamtStrecke = 0;
		double p_dGesamtZeit = 0;
		double p_dMaxGeschwindigkeit;

	public:
		Fahrzeug() = delete;
		Fahrzeug(const std::string name, double max_geschwindigkeit);
		virtual ~Fahrzeug();

		std::string getName() const;
		int getID() const;
		double getMaxGeschwindigkeit() const;
		double getGesamtStrecke() const;

		virtual void vSimulieren(double dTimeStep);
		virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity())
		{
			return 0.0;
		}
		static void vKopf();
		virtual void vAusgabe() const;
		virtual double dGeschwindigkeit() const;
};

#endif /* FAHRZEUG_H_ */
