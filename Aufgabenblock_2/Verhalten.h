/*
 * Verhalten.h
 *
 *  Created on: Nov 12, 2025
 *      Author: HaiPH
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"

class Verhalten
{
	public:
	Verhalten() = delete; // entweder parken oder bewegen
	Verhalten(Weg& weg, std::string zustand);
	virtual ~Verhalten() = default;

	private:
	std::string parken = "Parken";
	std::string fahren = "Fahren";

//	protected: fahrzeug
//			double p_dGesamtStrecke = 0;
//			double p_dGesamtZeit = 0;
//			double p_dMaxGeschwindigkeit;
//			std::shared_ptr<Verhalten> p_pVerhalten;
//			double p_dAbschnittStrecke = 0; // strecke on one street
//	Fahrzeug(const std::string name, double max_geschwindigkeit);
//
//	void Fahrzeug::vNeueStrecke(Weg&)
//	{
//		std::shared_ptr<Verhalten> fahren = std::make_shared<Verhalten>(karlsgraben&);
//		p_pVerhalten = fahren;
//	}
//

};





#endif /* VERHALTEN_H_ */
