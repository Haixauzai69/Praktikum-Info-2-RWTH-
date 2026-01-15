/*
 * Simulationsobjekt.h
 *
 *  Created on: Nov 9, 2025
 *      Author: HaiPH
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <stdlib.h>
#include <stdexcept>

extern double dGlobaleZeit;

class Simulationsobjekt
{
	private:
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;
//	double p_dZeit = 0;
//	double p_dLetzteAktualisierung = 0;

	protected:
	double p_dLokaleZeit = 0.0;
	std::string p_sName;

	public:
	Simulationsobjekt() = default;
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual ~Simulationsobjekt() = default;
	std::string sGetName() const;
	int iGetID();
	bool operator==(const Simulationsobjekt& vergleich);
	virtual void vSimulieren(double dTimeStep) = 0;
	virtual void vAusgabe(std::ostream& ausgabe) const;
	void vSetName(std::string something);
	virtual void vEinlesen(std::istream& eingabe);
};

std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& obj);
std::istream& operator>>(std::istream& in, Simulationsobjekt& obj);

#endif /* SIMULATIONSOBJEKT_H_ */
