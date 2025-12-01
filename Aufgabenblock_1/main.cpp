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
#include <algorithm>
#include <memory>
#include <cmath>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

std::ostream& operator<<(std::ostream& out, const Fahrzeug& fahrzeug)
{
	fahrzeug.vAusgabe(out);
	return out;
}

void vAufgabe1()
{
	std::unique_ptr<Fahrzeug> bmw = std::make_unique<Fahrzeug>("BMW", 130.0);
	std::unique_ptr<Fahrzeug> audi = std::make_unique<Fahrzeug>("Audi", 150.0);

	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
	fahrzeuge.push_back(std::move(bmw));
	fahrzeuge.push_back(std::move(audi));

	std::shared_ptr<Fahrzeug> bike1 = std::make_shared<Fahrzeug>("Mountain Bike", 20.0);

	std::cout << bike1.use_count() << std::endl;

	std::vector<std::shared_ptr<Fahrzeug>> fahrrad;
	fahrrad.push_back(bike1);

	std::cout << bike1.use_count() << std::endl;

	std::shared_ptr<Fahrzeug> bike3;
	bike3 = bike1;

	std::cout << bike1.use_count() << std::endl;

	fahrrad.push_back(std::move(bike3));

	std::cout << bike1.use_count() << std::endl;

	fahrzeuge.clear();
	fahrrad.clear();

//	Fahrzeug::vAusgabe(fahrzeuge, fahrrad);
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

//	vAusgabe(vehicles);
	Fahrzeug::vKopf();
	for (auto& fzg : vehicles)
		{
		     std::cout << *fzg << std::endl;  // polymorphic call
		}

	for (int t = 0; t < 2; ++t) // after 1 hour
	{
		  dGlobaleZeit++;
		  for (auto& i : vehicles)
		  {
			  i->vSimulieren(0.5);
		  }
	}

	std::cout << " " << std::endl;
//	vAusgabe(vehicles);
	Fahrzeug::vKopf();
	for (auto& fzg : vehicles)
		{
			    std::cout << *fzg << std::endl;
		}
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


	    for (int i = 0; i < numCars; ++i)
	    {
	        std::string name = "Car_" + std::to_string(i + 1);
	        double verbrauch = 5 + i;
	        double tankvolumen = 55;
	        vehicles.push_back(std::make_unique<Car>(verbrauch, tankvolumen));
	    }


	    for (int i = 0; i < numBikes; ++i)
	    {
	        std::string name = "Bike_" + std::to_string(i + 1);
	        double maxSpeed = 25 + 2 * i;
	        vehicles.push_back(std::make_unique<Fahrrad>(name, maxSpeed));
	    }


	    double dTimeStep = 0.5;
	    double dTotalTime = 0.0;
	    double epsilon = 1e-6;

	    while (dTotalTime < 6.0)
	    {
	        dGlobaleZeit += dTimeStep;
	        dTotalTime += dTimeStep;

	        for (auto& fzg : vehicles)
	            fzg->vSimulieren(dTimeStep);


	        if (std::fabs(dTotalTime - 3.0) < epsilon)
	        {
	            for (auto& fzg : vehicles)
	                fzg->dTanken();
	        }

	        // Output after each step
	        std::cout << "\nAfter " << dTotalTime << " hours:\n";
	        Fahrzeug::vKopf();
	        for (auto& fzg : vehicles)
	        {
	            std::cout << *fzg << std::endl;
	        }
	    }
}

void vAufgabe_3()
{
    Fahrzeug car1("Audi", 150.0);
    Fahrzeug car2("BMW", 130.0);


    car1.vSimulieren(2.0);
    car2.vSimulieren(1.0);

    Fahrzeug::vKopf();
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;


    if (car1 < car2)
        std::cout << car1.getName() << " has driven less than " << car2.getName() << "\n";
    else
        std::cout << car1.getName() << " has driven more than or equal to " << car2.getName() << "\n";


    Fahrzeug car3("Mercedes", 200.0);
    std::cout << "\nBefore assignment:\n" << car3 << std::endl;
    car3 = car1;
    std::cout << "After assignment (car3 = car1):\n" << car3 << std::endl;
}

//double dEpsilon = 0.001;
//
//void vAufgabe_Probe() {
//    Car* pF1 = new Car(8, 55);
//    dGlobaleZeit = 0.0;
//    Fahrzeug::vKopf();
//    dGlobaleZeit = 3.0;
//    std::cout << std::endl << "Globalezeit = " << dGlobaleZeit << std::endl;
//    pF1->vSimulieren(3.0);
//    std::cout << *pF1 << std::endl;
//    delete pF1;
//    char c;
//    std::cin >> c;
//}

//double dEpsilon = 0.001;
//
//void vAufgabe_AB1() {
//
//    int l = 0; // Laufindex für gezielte AUsgabe
//    vector<int> ausgabe{15};
//    double dTakt = 0.3;
//
//    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
//    vecFahrzeuge.push_back(make_unique<Car>(10.7, 55.0));
//    vecFahrzeuge.push_back(make_unique<Fahrrad>("BMX", 21.4));
//    for (dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
//    {
//        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
//        if (itL != ausgabe.end()) {
//            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
//            Fahrzeug::vKopf();
//        }
//
//        for (int i = 0; i < vecFahrzeuge.size(); i++)
//        {
//            vecFahrzeuge[i]->vSimulieren(0.3);
//            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
//            {
//                vecFahrzeuge[i]->dTanken(55.0);
//            }
//            if (itL != ausgabe.end()) {
//                std::cout << *vecFahrzeuge[i] << endl;
//            }
//        }
//        l++;
//    }
//    char c;
//    std::cin >> c;
//}


int main()
{
//	vAufgabe1();
//	vAufgabe1a();
//	vAufgabe_2();
//	vAufgabe_3();
//	vAufgabe_Probe();
//	vAufgabe_AB1();
	return 0;
}


