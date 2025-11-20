/*
 * main.cpp
 *
 *  Created on: Oct 10, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Train.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "Station.h"
#include <exception>
#include "TrainException.h"
#include <stdlib.h>
#include <stdexcept>

std::ostream& operator<<(std::ostream& out, const Train& train)
{
	train.vPrintProperties(out);
	return out;
}

int main()
{
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
//	koeln->vAddNeighbor(hamburg);

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


	try
	{
		std::cout<< "\n\n\nZuege fahren lassen: \n\n";
		aTrain->vGoTo(berlin);
		aTrain->vGoTo(hamburg);
		aTrain->vGoTo(koeln);
		aTrain->vGoTo(hamburg); 	// Fehlermeldung: keine Verbindung
	}

	catch(TrainException &fehler)
	{
		fehler.vExplain();
	}

//	std::cout<< "\n\n\nZuege fahren lassen: \n\n";
//	aTrain->vGoTo(berlin);
//	aTrain->vGoTo(hamburg);
//	aTrain->vGoTo(koeln);
//	aTrain->vGoTo(hamburg); 	// Fehlermeldung: window will throw the problem itself
	return 0;
}

