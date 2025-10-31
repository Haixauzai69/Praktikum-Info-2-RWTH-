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

class Fahrrad : public Fahrzeug
{
	public:
	Fahrrad() = delete;
	Fahrrad(const std::string& name, double maxSpeed);
	virtual ~Fahrrad() = default;
	double dGeschwindigkeit() const override;
};





#endif /* FAHRRAD_H_ */
