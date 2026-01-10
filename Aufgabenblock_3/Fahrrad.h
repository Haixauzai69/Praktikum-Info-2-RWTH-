/*
 * Fahrrad.h
 *
 *  Created on: Oct 24, 2025
 *      Author: HaiPH
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include "Fahrzeug.h"
#include "SimuClient.h"

class Fahrrad : public Fahrzeug
{
	public:
	Fahrrad();
	Fahrrad(const std::string& name, double maxSpeed);
	virtual ~Fahrrad() = default;
	double dGeschwindigkeit() const override;
//	void vSimulieren(double dTimeStep) override;
//	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
	void vAusgabe(std::ostream& ausgabe) const override;
	bool bIstLeer() const override;
	void vEinlesen(std::istream& eingabe) override;

	void vZeichen(const Weg& weg) override;
};





#endif /* FAHRRAD_H_ */
