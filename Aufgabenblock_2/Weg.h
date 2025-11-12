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
#include "Fahrzeug.h"
#include <limits>
#include "Tempolimit.h"

class Weg : public Simulationsobjekt
{
	protected:
	double p_dLaenge;
	enum Tempolimit p_eTempolimit;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;

	public:
	Weg() = delete;
	Weg(const Weg&) = delete;
	Weg(std::string name, double laenge, enum Tempolimit tempolimit, std::unique_ptr<Fahrzeug> fahrzeug);
	virtual ~Weg() = default;
	void vAddFahrzeug(std::unique_ptr<Fahrzeug> vehicle);
	enum Tempolimit getTempolimit();
	void vSimulieren(double dTimeStep) override;
	void vKopf() const;
	void vAusgabe(std::ostream& ausgabe) const override;
};




#endif /* WEG_H_ */
