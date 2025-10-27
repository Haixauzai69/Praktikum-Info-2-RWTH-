/*
 * Station.h
 *
 *  Created on: Oct 22, 2025
 *      Author: HaiPH
 */

#ifndef STATION_H_
#define STATION_H_
#include <iostream>
#include <memory>
#include <string>
#include "Train.h"

class Station
{
	private:
	const std::string p_sName;
	std::shared_ptr<Station> p_pDestination;

	public:
	Station(const std::string name);

	void vSetDestination(std::shared_ptr<Station> destination);
	std::shared_ptr<Station> getDestination() const;
	std::string getName() const;
};

Station::Station(const std::string name) : p_sName(name)
{
}

std::string Station::getName() const
{
	return p_sName;
}

std::shared_ptr<Station> Station::getDestination() const
{
	return p_pDestination;
}

void Station::vSetDestination(std::shared_ptr<Station> destination)
{
	p_pDestination = destination;
}

#endif /* STATION_H_ */
