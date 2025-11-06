/*
 * TrainException.h
 *
 *  Created on: Nov 6, 2025
 *      Author: HaiPH
 */

#ifndef TRAINEXCEPTION_H_
#define TRAINEXCEPTION_H_
#include <iostream>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>
#include "Station.h"
#include "Train.h"

class TrainException : public std::exception
{
	private:
	std::shared_ptr<Station> p_pDestination;

	public:
	TrainException(std::shared_ptr<Station> destination);
	virtual ~TrainException() = default;

	void vExplain();
};

TrainException::TrainException(std::shared_ptr<Station> destination)
{
	p_pDestination = destination;
}

void TrainException::vExplain()
{
	std::cout << "There are no connections to this station :(" << std::endl;
}


#endif /* TRAINEXCEPTION_H_ */
