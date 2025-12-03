/*
 * Streckenende.h
 *
 *  Created on: Nov 20, 2025
 *      Author: HaiPH
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_
#include <iostream>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme
{
	public:
	Streckenende() = delete;
	Streckenende(Weg& weg, Fahrzeug& fahrzeug);
	virtual ~Streckenende() = default;

	virtual void vBearbeiten() override;
};




#endif /* STRECKENENDE_H_ */
