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

class Verhalten
{
	public:
	Verhalten() = delete;
	Verhalten(Weg&);
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall); // controls how far a vehicle can go before going to the end of the street
															// control: if too much time enough to pass through the end, minus it
															// and take the valid amount of time to assign

};





#endif /* VERHALTEN_H_ */
