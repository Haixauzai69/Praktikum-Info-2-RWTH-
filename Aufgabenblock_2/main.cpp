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
#include <list>
#include <ios>
#include <algorithm>
#include <stdlib.h>
#include <iterator>
#include <stdexcept>
#include <exception>
#include <memory>
#include <cmath>
#include <random>
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Car.h"
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Fahrausnahme.h"
#include "Losfahren.h"
#include "Streckenende.h"
#include "SimuClient.h"
#include "vertagt_liste.h"
#include "vertagt_aktion.h"

std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& obj)
{
	obj.vAusgabe(out);
	return out;
}

void vAufgabe1()
{
	std::unique_ptr<Fahrzeug> bmw = std::make_unique<Fahrzeug>("BMW", 130.0);
	std::unique_ptr<Fahrzeug> audi = std::make_unique<Fahrzeug>("Audi", 150.0);

	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
	fahrzeuge.push_back(std::move(bmw));
	fahrzeuge.push_back(std::move(audi));

	std::shared_ptr<Fahrzeug> bike1 = std::make_shared<Fahrzeug>("Mountain_Bike", 20.0);

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
			  i->vSimulieren(0.5); // time step of one hour for each step
		  } // this loop iteration is 0.5 hour step for 1 hours. simulation runs for 1 hours
	}
// time step and number of hour for simulation are adjustable. Time step of 0.5 for 16 hours will be a simulation of 8 hours
	std::cout << " " << std::endl;

	Fahrzeug::vKopf();
	for (auto& fzg : vehicles)
		{
			    std::cout << *fzg << std::endl;  // polymorphic call
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
    Fahrzeug car1("Audi", 150.0);
    Fahrzeug car2("BMW", 130.0);

    car1.vSimulieren(2.0);  // 2 hours
    car2.vSimulieren(1.0);  // 1 hour

    std::cout << "\n--- Current Vehicle States ---\n";
    Fahrzeug::vKopf();
    std::cout << car1 << std::endl;
    std::cout << car2 << std::endl;

    if (car1 < car2)
        std::cout << car1.sGetName() << " has driven less than " << car2.sGetName() << "\n";
    else
        std::cout << car1.sGetName() << " has driven more than or equal to " << car2.sGetName() << "\n";


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
//}

void vAufgabe4() // testing << operator to print out a street
{
	std::unique_ptr<Fahrzeug> car1 = std::make_unique<Fahrzeug>("BMW", 210);
	std::unique_ptr<Weg> boxgraben = std::make_unique<Weg>("Boxgraben", 24, Tempolimit::Innerorts);

	std::unique_ptr<Fahrzeug> car2 = std::make_unique<Fahrzeug>("Audi", 240);
	boxgraben->vAnnahme(std::move(car2));
	boxgraben->vKopf();
	std::cout << *boxgraben << std::endl;
	std::cout << std::endl;
}

void vAufgabe_5()
{
	auto theaterstr = std::make_unique<Weg>("Theaterstr.", 50, Tempolimit::Innerorts);

	std::unique_ptr<Car> car1 = std::make_unique<Car>(8, 55);
	std::unique_ptr<Fahrrad> bike1 = std::make_unique<Fahrrad>("Mountain bike", 30);
	std::unique_ptr<Fahrzeug> tram16 = std::make_unique<Fahrzeug>("Tram 16", 70);

	theaterstr->vAnnahme(std::move(car1), 5.0); // startzeit hinzufügen bedeutet parken
	theaterstr->vAnnahme(std::move(bike1));
	theaterstr->vAnnahme(std::move(tram16));

	theaterstr->vKopf();
	std::cout << *theaterstr << std::endl;

	try
	{
		theaterstr->vSimulieren(2.0);
	}

	catch(Fahrausnahme& error)
	{
		error.vBearbeiten();
	}

	theaterstr->vKopf();
	std::cout << *theaterstr << std::endl;
}

void vAufgabe_6()
{
	auto junkerstrasse = std::make_unique<Weg>("Weg1", 500, Tempolimit::Innerorts);

	std::unique_ptr<Car> car1 = std::make_unique<Car>(8, 55);
	std::unique_ptr<Fahrrad> bike1 = std::make_unique<Fahrrad>("Mountain_bike", 30);

    int koordinaten[4] = {100, 250, 700, 250};

    bInitialisiereGrafik(800, 500);

    vSleep(500);

    bZeichneStrasse(junkerstrasse->sGetName() + "_hin", junkerstrasse->sGetName() + "_rueck", junkerstrasse->dGetLaenge(), 2, koordinaten);

	junkerstrasse->vAnnahme(std::move(car1), 4.0); // startzeit hinzufügen bedeutet parken
	junkerstrasse->vAnnahme(std::move(bike1));

	for(int i = 0; i < 20 ; i++)
	{
		try
		{
			junkerstrasse->vSimulieren(1.0);
		}
		catch(Fahrausnahme& error)
		{
		    error.vBearbeiten();
		}
		vSetzeZeit(dGlobaleZeit);
		for (auto& i : junkerstrasse->getFahrzeuge())
		{
		     i->vZeichen(*junkerstrasse);
		}
		vSleep(600);
	}
	vSleep(10000);
	vBeendeGrafik();
}

void vTest()
{
    int koordinaten[4] = {100, 250, 700, 250};

    bInitialisiereGrafik(800, 500);

    vSleep(500);

    bool ok = bZeichneStrasse("W1", "W2", 500, 2, koordinaten);
    std::cout << "Draw result = " << ok << std::endl;

    // Add a vehicle so the road must render:
    bZeichnePKW("Auto1", "W1", 0.0, 40.0, 20.0);

    vSetzeZeit(5.0);

    vSleep(10000);
    vBeendeGrafik();
}

void vAufgabe_6a() // to test the new vListe by generating random numbers
{
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);

	vertagt::VListe<int> liste;

	for (int i = 0; i < 10; i++)
	{
		liste.push_back(dist(device));
	}

	liste.vAktualisieren(); // if i make this line disappear, the push back will not happen yet and can only be queued

	std::cout << "Random list" << std::endl;
	for (vertagt::VListe<int>::iterator i = liste.begin() ; i != liste.end() ; ++i)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	for (vertagt::VListe<int>::iterator i = liste.begin() ; i != liste.end() ; ++i)
	{
		if (*i > 5)
		{
			liste.erase(i);
		}
	}

//	liste.vAktualisieren(); if this line appears the erase process will begin immediately and the numbers will be erased

	std::cout << "Random list after erase" << std::endl;
	for (vertagt::VListe<int>::iterator i = liste.begin() ; i != liste.end() ; ++i)
		{
			std::cout << *i << " ";
		}

	std::cout << std::endl;

	liste.vAktualisieren(); // all the actions can only be called when this calls

	std::cout << "Random list after vAktualisieren" << std::endl;
	for (vertagt::VListe<int>::iterator i = liste.begin() ; i != liste.end() ; ++i)
		{
			std::cout << *i << " ";
		}
	std::cout << std::endl;
}


int main()
{
//	vAufgabe1();
//	vAufgabe1a();
//	vAufgabe_2();
//	vAufgabe_3();
//	vAufgabe_Probe();
//	vAufgabe_AB1();
//	vAufgabe4();
//	vAufgabe_5();
	vAufgabe_6();
//	vTest();
//	vAufgabe_6a();
	std::cout << "Sucess" << std::endl;
	return 0;
}


