/*
 * Fahrzeug.cpp
 *
 *  Created on: Oct 23, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include "Fahrzeug.h"

double dGlobaleZeit = 0.0;

Fahrzeug::~Fahrzeug()
{
	std::cout << "Name des gelöschten: " << p_sName << std::endl;
	std::cout << "ID des gelöschten: " << p_iID << std::endl;
}

Fahrzeug::Fahrzeug(const std::string name, double max_geschwindigkeit)
{
	p_sName = name;
	p_dMaxGeschwindigkeit = (max_geschwindigkeit < 0) ? 0 : max_geschwindigkeit;
}

std::string Fahrzeug::getName() const
{
	return p_sName;
}

int Fahrzeug::getID() const
{
	return p_iID;
}

double Fahrzeug::getMaxGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::getGesamtStrecke() const
{
	return p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren(double dTimeStep)
{
	 p_dGesamtStrecke += p_dMaxGeschwindigkeit*dTimeStep;
}

void Fahrzeug::vKopf()
{
	std::cout << std::setiosflags(std::ios::left)
					<< std::setw(5) << "ID"
					<< std::setw(30) << "Name"
					<< std::setw(20) << "MaxGeschwindigkeit"
					<< std::setw(15) << "Gesamtstrecke"
					<< std::setw(20) << "Gesamtverbrauch"
					<< std::setw(20) << "Aktuelle Tankinhalt"
					<< std::resetiosflags(std::ios::left) << std::endl;

	std::cout << std::string(120, '-') << std::endl;
}

void Fahrzeug::vAusgabe() const
{
	std::cout << std::setiosflags(std::ios::left)
	              << std::setw(5)  << p_iID
	              << std::setw(30) << p_sName
	              << std::setw(20) << p_dMaxGeschwindigkeit
	              << std::setw(15) << p_dGesamtStrecke;
}

