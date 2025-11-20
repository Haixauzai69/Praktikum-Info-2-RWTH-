/*
 * Parken.h
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Verhalten.h"

class Parken : public Verhalten
{
	public:
	Parken() = delete;
	Parken(Weg& weg, double dStartZeit);
	virtual ~Parken() = default;

	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;

	private:
	double p_dStartZeitPunkt;
};



#endif /* PARKEN_H_ */
