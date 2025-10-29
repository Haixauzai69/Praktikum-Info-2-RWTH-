/*
 * main.cpp
 *
 *  Created on: Oct 6, 2025
 *      Author: HaiPH
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include <memory>
#include "Fahrzeug.h"
#include "PKW.h"

//void vKopf()
//{
//	std::cout << std::setiosflags(std::ios::left)
//				<< std::setw(5) << "ID"
//				<< std::setw(30) << "Name"
//				<< std::setw(20) << "MaxGeschwindigkeit"
//				<< std::setw(15) << "Gesamtstrecke"
//				<< std::setw(20) << "Gesamtverbrauch"
//				<< std::setw(20) << "Aktuelle Tankinhalt"
//				<< std::resetiosflags(std::ios::left) << std::endl;
//
//		std::cout << std::string(95, '-') << std::endl;
//}

//void vAusgabe(std::vector<std::unique_ptr<Fahrzeug>>& unique_stuff)
//{
//	vKopf();
//	for(auto& i : unique_stuff)
//	{
//		std::cout << std::setiosflags(std::ios::left)
//				  << std::setw(5) << i->getID()
//				  << std::setw(30) << i->getName()
//				  << std::setw(20) << i->getMaxGeschwindigkeit()
//				  << std::setw(15) << i->getGesamtStrecke()
//				  << std::resetiosflags(std::ios::left) << std::endl;
//		std::cout << " " << std::endl;
//	}
////	for(auto& i : shared_stuff)
////		{
////			std::cout << std::setiosflags(std::ios::left)
////					  << std::setw(5) << i->getID()
////					  << std::setw(30) << i->getName()
////					  << std::setw(20) << i->getMaxGeschwindigkeit()
////					  << std::setw(15) << i->getGesamtStrecke()
////					  << std::resetiosflags(std::ios::left) << std::endl;
////		}
//}

//void vAufgabe1()
//{
//	std::unique_ptr<Fahrzeug> bmw = std::make_unique<Fahrzeug>("BMW", 130.0);
//	std::unique_ptr<Fahrzeug> audi = std::make_unique<Fahrzeug>("Audi", 150.0);
//
//	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
//	fahrzeuge.push_back(std::move(bmw));
//	fahrzeuge.push_back(std::move(audi));
//
//	std::shared_ptr<Fahrzeug> bike1 = std::make_shared<Fahrzeug>("Mountain Bike", 20.0);
//
//	std::cout << bike1.use_count() << std::endl;
//
//	std::vector<std::shared_ptr<Fahrzeug>> fahrrad;
//	fahrrad.push_back(bike1);
//
//	std::cout << bike1.use_count() << std::endl;
//
//	vAusgabe(fahrzeuge, fahrrad);
//
//	for (int t = 0; t < 15; ++t)
//	{
//	    dGlobaleZeit++;
//
//	    for (auto& i : fahrzeuge)
//	        i->vSimulieren();
//
//	    for (auto& i : fahrrad)
//	        i->vSimulieren();
//	}
//
//	vAusgabe(fahrzeuge, fahrrad);
//
//	fahrzeuge.clear();
//	fahrrad.clear();
//}

void vAusgabe(std::vector<std::unique_ptr<Fahrzeug>>& vehicles)
{
    Fahrzeug::vKopf();
    for (auto& v : vehicles)
        v->vAusgabe();   // calls the correct override automatically
}

void vAufgabe1a()
{
	std::unique_ptr<Car> car = std::make_unique<Car>(5, 55);
	std::unique_ptr<Fahrzeug> bike = std::make_unique<Fahrzeug>("Bike", 20);
	std::unique_ptr<Fahrzeug> tram = std::make_unique<Fahrzeug>("Tram", 100);

	std::vector<std::unique_ptr<Fahrzeug>> vehicles;
	vehicles.push_back(std::move(car));
	vehicles.push_back(std::move(bike));
	vehicles.push_back(std::move(tram));

	vAusgabe(vehicles);

	for (int t = 0; t < 8; ++t) // after 16 hours
	{
		  dGlobaleZeit++;
		  for (auto& i : vehicles)
		  {
			  i->vSimulieren(0.5); // time step of one hour for each step
		  } // this loop iteration is 0.5 hour step for 16 hours. simulation runs for 16 hours
	}
// time step and number of hour for simulation are adjustable. Time step of 0.5 for 16 hours will be a simulation of 8 hours
	std::cout << " " << std::endl;
	vAusgabe(vehicles);
}

void vAufgabe_2()
{
	// mach weiter
}

int main()
{
	vAufgabe1a();
	return 0;
}


