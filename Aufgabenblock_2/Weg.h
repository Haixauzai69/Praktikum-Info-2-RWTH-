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

class Weg : public Simulationsobjekt
{
	private:
	const double p_dLaenge;
	const int p_eTempolimit; // later will turn into enum of something
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
};




#endif /* WEG_H_ */
