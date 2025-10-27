/*
 * main.cpp
 *
 *  Created on: Oct 10, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include <memory>
#include "Train.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "Station.h"

std::ostream& operator<<(std::ostream& out, const Train& train)
{
	train.vPrintProperties(out);
	return out;
}


int main()
{
	std::unique_ptr<PassengerTrain> aTrain = std::make_unique<PassengerTrain>(20);

	auto bTrain = std::make_unique<FreightTrain>(2, "tons of wood");

	std::cout << "Eigenschaften aTrain: " << std::endl;
	std::cout << *aTrain << std::endl;


	std::cout << "Eigenschaften bTrain: " << std::endl;
	std::cout << *bTrain << std::endl;

	auto berlin = std::make_shared<Station>("Berlin");
	auto hamburg = std::make_shared<Station>("Hamburg");
	auto koeln = std::make_shared<Station>("Koeln");

	hamburg->vSetDestination(koeln);
	koeln->vSetDestination(berlin);
	berlin->vSetDestination(hamburg);

	std::cout << "Sehr geehrte Fahrgäste, wir erreichen in wenigen Minuten Köln Hbf" << std::endl;
	aTrain->vGoTo(koeln);
	std::cout << "Sehr geehrte Fahrgäste, wir erreichen in wenigen Minuten Berlin Hbf" << std::endl;
	aTrain->vGoTo(berlin);
	aTrain->vGoTo(berlin);
	return 0;
}

