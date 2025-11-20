/*
 * Fahrausnahme.h
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include <iostream>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"

class Fahrausnahme : public std::exception
{
	private:
	Weg& p_rStreet;
	Fahrzeug& p_rFahrzeug;

	public:
	Fahrausnahme() = default;
	Fahrausnahme(Weg& street, Fahrzeug& fahrzeug);
	virtual ~Fahrausnahme() = default;

	virtual void vBearbeiten() = 0;
};


#endif /* FAHRAUSNAHME_H_ */
