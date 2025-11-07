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
	 double dCurrentSpeed = dGeschwindigkeit();
	 p_dGesamtStrecke += dCurrentSpeed * dTimeStep;
}

void Fahrzeug::vKopf()
{
	std::cout << std::setiosflags(std::ios::left)
					<< std::setw(5) << "ID"
					<< std::setw(10) << "Name"
					<< std::setw(25) << "MaxGeschwindigkeit"
					<< std::setw(25) << "Gesamtstrecke"
					<< std::setw(25) << "Gesamtverbrauch"
					<< std::setw(25) << "Aktuelle Tankinhalt"
					<< std::setw(25) << "Aktuelle Geschwindigkeit"
					<< std::resetiosflags(std::ios::left) << std::endl
					<< std::string(140,'-') << std::endl;
}

void Fahrzeug::vAusgabe(std::ostream& ausgabe) const
{
	ausgabe << std::setiosflags(std::ios::left)
	              << std::setw(5)  << p_iID
	              << std::setw(10) << p_sName
	              << std::setw(25) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
	              << std::setw(25) << std::fixed << std::setprecision(2) << p_dGesamtStrecke
				  << std::setw(25) << "-"
				  << std::setw(25) << "-"
				  << std::setw(25) << std::fixed << std::setprecision(2) << dGeschwindigkeit()
				  << std::resetiosflags(std::ios::left) << std::endl;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const
{
    return this->p_dGesamtStrecke < other.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other)
{
    if (this != &other)
    {
        // Copy only “static” or initial attributes — not runtime values.
        // ID should NOT be copied!
        // The name might be allowed or not, depending on your design.

        // Example: don’t copy ID or current total distance
        // You can copy p_sName if it’s not const (if const, skip it)
        this->p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
        // Maybe reset some runtime stats here
        this->p_dGesamtStrecke = 0.0;
        this->p_dGesamtZeit = 0.0;
    }
    return *this;
}

