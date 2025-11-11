/*
 * Tempolimit.h
 *
 *  Created on: Nov 11, 2025
 *      Author: HaiPH
 */

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_
#include <iostream>
#include <string>
#include "Simulationsobjekt.h"
#include <limits>

enum class Tempolimit
{
	Innerorts = 50,
	Ausserorts = 100,
	Autobahn = std::numeric_limits<int>::max()
};

#endif /* TEMPOLIMIT_H_ */
