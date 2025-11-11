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
	private:
	const double p_dLaenge;
	const enum Tempolimit p_eTempolimit;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;

	public:
	Weg() = default;
	Weg(std::string name, double laenge, enum Tempolimit tempolimit);
	virtual ~Weg() = default;
	double getTempolimit();
	void vSimulieren() const override;
	void vKopf() const;
	void vAusgabe() const;
};




#endif /* WEG_H_ */
