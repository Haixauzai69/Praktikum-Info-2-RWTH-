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

class Bike : public Fahrzeug
{
	public:
	Bike() = delete;
	virtual ~Bike() = default;
	double dGeschwindigkeit() const override;
};





#endif /* FAHRRAD_H_ */
