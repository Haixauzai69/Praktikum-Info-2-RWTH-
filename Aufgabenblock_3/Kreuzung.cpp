/*
 * Kreuzung.cpp
 *
 *  Created on: Dec 13, 2025
 *      Author: HaiPH
 */
#include <iostream>
#include <string.h>
#include "Simulationsobjekt.h"
#include "vertagt_liste.h"
#include "vertagt_aktion.h"
#include <memory>
#include <list>
#include <random>
#include "Tempolimit.h"
#include <limits>
#include "Weg.h"
#include "Fahrzeug.h"
#include "Car.h"
#include "Fahrrad.h"
#include "Kreuzung.h"

Kreuzung::Kreuzung(const std::string name, double tank)
{
	vSetName(name);
	p_dTankstelle = tank;
}

void Kreuzung::vVerbinde(std::string hin, std::string ruck, double laenge, enum Tempolimit tempo, bool Ueberhol,
						std::shared_ptr<Kreuzung> startkreuzung, std::shared_ptr<Kreuzung> zielkreuzung)
{
	std::shared_ptr<Weg> weghin = std::make_shared<Weg>(hin, laenge, tempo, Ueberhol, zielkreuzung);
	std::shared_ptr<Weg> wegrueck = std::make_shared<Weg>(ruck, laenge, tempo, Ueberhol, startkreuzung);

	weghin->setRueckweg(wegrueck);
	wegrueck->setRueckweg(weghin);

	startkreuzung->p_pWege.push_back(weghin);
	zielkreuzung->p_pWege.push_back(wegrueck);

	startkreuzung->p_pWege.vAktualisieren();
	zielkreuzung->p_pWege.vAktualisieren();
}

void Kreuzung::vTanken(Fahrzeug& fzg)
{
	if(p_dTankstelle > 0)
	{
		double menge = fzg.dTanken(std::numeric_limits<double>::infinity());
		p_dTankstelle -= menge;
	}
	else
	{
		std::cout << "Tankstelle ist leer" << std::endl;
	}
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start) // parkend auf anderen weg geben und fahrzeug auftanken
{
	if (fahrzeug != nullptr && !p_pWege.empty())
	{
		this->vTanken(*fahrzeug);
		(*p_pWege.begin())->vAnnahme(std::move(fahrzeug), start);
	}
	else
	{
		std::cout << "Kreuzung nicht verbunden" << std::endl;
	}
}

void Kreuzung::vSimulieren(double dTimeStep)
{
	for(auto& i : p_pWege)
	{
		i->vSimulieren(dTimeStep);
	}
	p_pWege.vAktualisieren();
}

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& ankunftsWeg)
{
	if (p_pWege.size() == 1)
	{
		return *p_pWege.begin(); // sackgasse
	}

	else if (p_pWege.size() > 1)
	{
		int seed = 1;
		static std::mt19937 device(seed);
		std::uniform_int_distribution<int> dist(0, p_pWege.size() - 2);
		int iRanNum = dist(device);
		int iCounter = 0;

		for (auto it = p_pWege.begin(); it != p_pWege.end(); it++)
		{
			if (*it != ankunftsWeg.pGetRueckweg())
			{
				if (iCounter == iRanNum)
				{
					return *it;
				}
				iCounter++;
			}
		}
	}
	else return nullptr;
}

double Kreuzung::dGetTank()
{
	return p_dTankstelle;
}





