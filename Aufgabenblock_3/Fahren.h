/*
 * Fahren.h
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Verhalten.h"

class Fahren : public Verhalten
{
	public:
	Fahren() = delete;
	Fahren(Weg& weg);
	virtual ~Fahren() = default;

	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};


#endif /* FAHREN_H_ */
