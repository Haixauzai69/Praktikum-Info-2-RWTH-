/*
 * Verhalten.h
 *
 *  Created on: Nov 12, 2025
 *      Author: HaiPH
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"

class Verhalten
{
	public:
	Verhalten() = delete;
	Verhalten(Weg& weg);
	virtual ~Verhalten() = default;

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
	Weg& getWeg() const;

	protected:
	Weg& p_rWeg;
};





#endif /* VERHALTEN_H_ */
