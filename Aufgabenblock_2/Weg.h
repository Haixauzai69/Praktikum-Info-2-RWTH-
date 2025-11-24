/*
 * Weg.cpp
 *
 *  Created on: Nov 9, 2025
 *      Author: HaiPH
 */

#ifndef WEG_H_
#define WEG_H_
#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include <list>
#include <limits>
#include "Tempolimit.h"

class Fahrzeug;

class Weg : public Simulationsobjekt
{
	protected:
	double p_dLaenge;
	enum Tempolimit p_eTempolimit;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;

	public:
	Weg() = delete;
	Weg(Weg& weg) = delete;
	Weg(std::string name, double laenge, enum Tempolimit tempolimit);
	virtual ~Weg() = default;

	enum Tempolimit getTempolimit();
	double dGetLaenge() const;
//	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

	void vSimulieren(double dTimeStep) override;
	void vKopf() const;
	void vAusgabe(std::ostream& ausgabe) const override;
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start);
};




#endif /* WEG_H_ */
