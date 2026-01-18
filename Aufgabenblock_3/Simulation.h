/*
 * Simulation.h
 *
 *  Created on: Jan 18, 2026
 *      Author: HaiPH
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_
#include <iostream>
#include <string>

class Simulationsobjekt;

class Simulation
{
	public:
	Simulation() = default;
	virtual ~Simulation() = default;
	void vEinlesen(std::istream& ein);
	void vSimulieren();
};




#endif /* SIMULATION_H_ */
