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
// list is a version of vector but more flexible at adding elements at the end, middle, beginning.
// there is even a function that lets us add a range of elements into a list which is
//	void insert(iterator pos, const_iterator first, const_iterator last)
//	note: iterator is the pointer that points to a position of a list, thats why for loop always have int i that traverses the loop

	std::unique_ptr<PassengerTrain> aTrain;
	aTrain = std::make_unique<PassengerTrain>();

	auto bTrain = std::make_unique<FreightTrain>(2, "tons of wood");

	std::cout << std::endl << "Eigenschaften 'aTrain':" << std::endl;
	std::cout << *aTrain;

	std::cout << std::endl << "Eigenschaften 'bTrain':" << std::endl;
	std::cout << *bTrain;

	auto berlin = std::make_shared<Station>("Berlin");
	auto hamburg = std::make_shared<Station>("Hamburg");
	auto frankfurt = std::make_shared<Station>("Frankfurt");
	auto koeln = std::make_shared<Station>("Koeln");
	auto muenchen = std::make_shared<Station>("Muenchen");

	berlin->vAddNeighbor(hamburg);
	berlin->vAddNeighbor(frankfurt);

	hamburg->vAddNeighbor(berlin);
	hamburg->vAddNeighbor(koeln);

	// Strecke nur in eine Richtung
	koeln->vAddNeighbor(frankfurt);

	frankfurt->vAddNeighbor(koeln);
	frankfurt->vAddNeighbor(berlin);
	frankfurt->vAddNeighbor(muenchen);

	muenchen->vAddNeighbor(frankfurt);

	// Zeige Liste der bekannten Nachbarn
	std::cout << std::endl;

	berlin->vPrintNeighbors();
	std::cout << std::endl;

	hamburg->vPrintNeighbors();
	std::cout << std::endl;

	koeln->vPrintNeighbors();
	std::cout << std::endl;

	frankfurt->vPrintNeighbors();
	std::cout << std::endl;

	muenchen->vPrintNeighbors();
	std::cout << std::endl;

	std::cout<< "\n\n\nZuege fahren lassen: \n\n";
	aTrain->vGoTo(berlin);
	aTrain->vGoTo(hamburg);
	aTrain->vGoTo(koeln);
	aTrain->vGoTo(hamburg); // Fehlermeldung: keine Verbindung
	return 0;
}

