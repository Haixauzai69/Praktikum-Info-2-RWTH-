/*
 * PKW.h
 *
 *  Created on: Oct 24, 2025
 *      Author: HaiPH
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
#include <limits>
#include "Fahrzeug.h"
#include "Tempolimit.h"

class Car : public Fahrzeug
{
	public:
	Car() =  delete;
	Car(double verbrauch, double tankvolumen);
	virtual ~Car() = default;
	double dTanken (double dMenge = std::numeric_limits<double>::infinity()) override;
	void vSimulieren(double dTimeStep) override;
	void vAusgabe(std::ostream& ausgabe) const override;
	double dGeschwindigkeit() const override;
	double dGetTank();

	protected:
	double p_dVerbrauch; // liter pro 100km
	double p_dTankvolumen;
	double p_dTankinhalt = 0;  // liter
};



#endif /* CAR_H_ */
