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
#include <vector>
#include <iterator>
#include "Train.h"

class Station
{
	private:
	const std::string p_sName;
	std::vector<std::shared_ptr<Station>> p_pNeighbors;

	public:
	Station(const std::string name);

	std::string getName() const;
	void vAddNeighbor(std::shared_ptr<Station> station);
	void vPrintNeighbors() const;
	bool bIsNeighbor(std::shared_ptr<Station> request) const;
};

Station::Station(const std::string name) : p_sName(name)
{
}

std::string Station::getName() const
{
	return p_sName;
}

void Station::vAddNeighbor(std::shared_ptr<Station> station)
{
	// syntax: Koln.vAddNeighbor(Dusseldorf);
	p_pNeighbors.push_back(station);
}

void Station::vPrintNeighbors() const
{
	// syntax: koln.vPrintNeighbors();
	for (auto i : p_pNeighbors)
	{
		std::cout << i->getName() << std::endl;
	}
}

bool Station::bIsNeighbor(std::shared_ptr<Station> request) const
{
	// search for the given station within the vector. if found, returns true
	for (auto it : p_pNeighbors)
	{
		if (it == request)
		{
			return 1;
		}
	}
	return 0;
}

#endif /* STATION_H_ */
