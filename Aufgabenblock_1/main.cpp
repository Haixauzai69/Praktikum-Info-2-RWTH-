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
#include <cmath>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

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

//void vAusgabe(std::vector<std::unique_ptr<Fahrzeug>>& vehicles)
//{
//    Fahrzeug::vKopf();
//    for (auto& v : vehicles)
//        v->vAusgabe();   // calls the correct override automatically
//}

//void vAufgabe1a()
//{
//	std::unique_ptr<Car> car = std::make_unique<Car>(5, 55);
//	std::unique_ptr<Fahrzeug> bike = std::make_unique<Fahrzeug>("Bike", 20);
//	std::unique_ptr<Fahrzeug> tram = std::make_unique<Fahrzeug>("Tram", 100);
//
//	std::vector<std::unique_ptr<Fahrzeug>> vehicles;
//	vehicles.push_back(std::move(car));
//	vehicles.push_back(std::move(bike));
//	vehicles.push_back(std::move(tram));
//
//	vAusgabe(vehicles);
//
//	for (int t = 0; t < 8; ++t) // after 16 hours
//	{
//		  dGlobaleZeit++;
//		  for (auto& i : vehicles)
//		  {
//			  i->vSimulieren(0.5); // time step of one hour for each step
//		  } // this loop iteration is 0.5 hour step for 16 hours. simulation runs for 16 hours
//	}
//// time step and number of hour for simulation are adjustable. Time step of 0.5 for 16 hours will be a simulation of 8 hours
//	std::cout << " " << std::endl;
//	vAusgabe(vehicles);
//}
std::ostream& operator<<(std::ostream& out, const Fahrzeug& fahrzeug)
{
	fahrzeug.vAusgabe(out);
	return out;
}

void vAufgabe_2()
{
	    int numCars = 0;
	    int numBikes = 0;
	    std::cout << "Enter number of cars: ";
	    std::cin >> numCars;
	    std::cout << "Enter number of bikes: ";
	    std::cin >> numBikes;

	    std::vector<std::unique_ptr<Fahrzeug>> vehicles;

	    // Create PKWs
	    for (int i = 0; i < numCars; ++i)
	    {
	        std::string name = "Car_" + std::to_string(i + 1);
	        double verbrauch = 5 + i;          // example consumption
	        double tankvolumen = 55;           // default tank size
	        vehicles.push_back(std::make_unique<Car>(verbrauch, tankvolumen));
	    }

	    // Create Fahrräder
	    for (int i = 0; i < numBikes; ++i)
	    {
	        std::string name = "Bike_" + std::to_string(i + 1);
	        double maxSpeed = 25 + 2 * i;
	        vehicles.push_back(std::make_unique<Fahrrad>(name, maxSpeed));
	    }

	    // Simulation loop
	    double dTimeStep = 0.5; // 0.5 hours
	    double dTotalTime = 0.0;
	    double epsilon = 1e-6;

	    while (dTotalTime < 6.0) // simulate 6 hours
	    {
	        dGlobaleZeit += dTimeStep;
	        dTotalTime += dTimeStep;

	        for (auto& fzg : vehicles)
	            fzg->vSimulieren(dTimeStep);

	        // After exactly 3 hours: refuel cars
	        if (std::fabs(dTotalTime - 3.0) < epsilon)
	        {
	            for (auto& fzg : vehicles)
	                fzg->dTanken(); // only PKWs do something
	        }

	        // Output after each step
	        std::cout << "\nAfter " << dTotalTime << " hours:\n";
	        Fahrzeug::vKopf();
	        for (auto& fzg : vehicles)
	        {
	            std::cout << *fzg << std::endl;  // polymorphic call
	        }
	    }
}

void vAufgabe_3()
{
    std::cout << "\n===== Aufgabe 3: Operator Tests =====\n";

    // 1️⃣ Create some vehicles
    Fahrzeug car1("Audi", 150.0);
    Fahrzeug car2("BMW", 130.0);

    // 2️⃣ Simulate for different times
    car1.vSimulieren(2.0);  // 2 hours
    car2.vSimulieren(1.0);  // 1 hour

    // 3️⃣ Test the output operator <<
    std::cout << "\n--- Current Vehicle States ---\n";
    Fahrzeug::vKopf();
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;

    // 4️⃣ Test operator<
    if (car1 < car2)
        std::cout << car1.getName() << " has driven less than " << car2.getName() << "\n";
    else
        std::cout << car1.getName() << " has driven more than or equal to " << car2.getName() << "\n";

    // 5️⃣ Test copy constructor (should fail if you uncomment)
    // Fahrzeug copy = car1; // ❌ error: copy constructor is deleted

    // 6️⃣ Test assignment operator
    Fahrzeug car3("Mercedes", 200.0);
    std::cout << "\nBefore assignment:\n" << car3 << std::endl;
    car3 = car1; // uses operator=
    std::cout << "After assignment (car3 = car1):\n" << car3 << std::endl;

    std::cout << "\n===== End of Aufgabe 3 =====\n";
}

double dEpsilon = 0.001;

void vAufgabe_Probe() {
    Fahrzeug* pF1 = new Car(8, 55);
    dGlobaleZeit = 0.0;
    Fahrzeug::vKopf();
    dGlobaleZeit = 3.0;
    std::cout << std::endl << "Globalezeit = " << dGlobaleZeit << std::endl;
    pF1->vSimulieren(3.0);
    std::cout << *pF1 << std::endl;
    delete pF1;
    char c;
    std::cin >> c;
}


int main()
{
//	vAufgabe_2();
//	vAufgabe_3();
	vAufgabe_Probe();
	return 0;
}


