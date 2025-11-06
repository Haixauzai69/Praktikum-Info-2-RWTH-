/*
 * PassengerTrain.h
 *
 *  Created on: Oct 9, 2025
 *      Author: HaiPH
 */

#ifndef PASSENGERTRAIN_H_
#define PASSENGERTRAIN_H_

#include <iostream>
#include "Train.h"
#include "Station.h"
#include <memory>

class PassengerTrain : public Train
{
	public:
		PassengerTrain() = default;
		PassengerTrain(int passengers);
		virtual ~PassengerTrain() = default;

		void vPrintProperties(std::ostream& ausgabe) const;
		float fStation(int passengersIn, int passengersOut);
	private:
		int p_iPassengerCounter = 0;
};

PassengerTrain::PassengerTrain(int passengers)
{
	p_iPassengerCounter = passengers;
	std::cout << "Nicht-Standardkonstruktor" << std::endl;
}

void PassengerTrain::vPrintProperties(std::ostream& ausgabe) const
{
	ausgabe << "Passenger Train" << std::endl;
	Train::vPrintProperties(ausgabe);
	ausgabe << "Number of passengers: " << p_iPassengerCounter << std::endl;
}

float PassengerTrain::fStation(int passengersIn, int passengersOut)
{
	if ((p_iPassengerCounter + passengersIn) < passengersOut) // hell yeah i debugged this shit myself
	{
		std::cout << "Mehr aussteigende Personnen als Passagiere im Zug" << std::endl;
		return 0;
	}

	p_iPassengerCounter = p_iPassengerCounter + passengersIn - passengersOut;

	float minutesChange = (120 - passengersIn * 10 - passengersOut * 5)/60;
	p_fDelay = ((minutesChange < 0) ? p_fDelay - minutesChange : 0);
	return minutesChange;
}

#endif /* PASSENGERTRAIN_H_ */
