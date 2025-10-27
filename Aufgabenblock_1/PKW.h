/*
 * PKW.h
 *
 *  Created on: Oct 24, 2025
 *      Author: HaiPH
 */

#ifndef PKW_H_
#define PKW_H_

#include <iostream>
#include <string>
#include <limits>
#include "Fahrzeug.h"

class Car : public Fahrzeug
{
	public:
	Car() =  delete;
	Car(double verbrauch, double tankvolumen);
	virtual ~Car() = default;
	double dTanken (double dMenge = std::numeric_limits<double>::infinity()) override;
	void vSimulieren(double dTimeStep) override;
	void vAusgabe() const override;

	protected:
	double p_dVerbrauch; // liter pro 100km
	double p_dTankvolumen;
	double p_dTankinhalt;  // liter
	bool p_bEmpty = false;
};



#endif /* PKW_H_ */
