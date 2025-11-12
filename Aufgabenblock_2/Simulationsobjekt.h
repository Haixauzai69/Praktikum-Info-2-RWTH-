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

class Simulationsobjekt
{
	private:
	std::string p_sName;
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;

	protected:
	double p_dLokaleZeit;

	public:
	Simulationsobjekt() = delete;
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual ~Simulationsobjekt() = default;

	bool operator==(const Simulationsobjekt& vergleich);

	virtual void vSimulieren(double dTimeStep) = 0;
	virtual void vAusgabe(std::ostream& ausgabe) const = 0;
	void vSetName(std::string something);
	std::string sGetName();
	int iGetID();
};
// upcoming tasks: keep working on vAusgabe, update fahrzeug, car,
//fahrrad especially vSimulieren, overload the operator<<


#endif /* SIMULATIONSOBJEKT_H_ */
