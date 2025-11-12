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

extern double dGlobaleZeit;

class Simulationsobjekt
{
	private:
	std::string p_sName = " ";
	static inline int p_iMaxID = 0;
	const int p_iID = p_iMaxID++;

	protected:
	double p_dLokaleZeit = 0.0;

	public:
	Simulationsobjekt() = default;
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual ~Simulationsobjekt() = default;
	std::string sGetName();
	int iGetID();
	bool operator==(const Simulationsobjekt& vergleich);
	virtual void vSimulieren(double dTimeStep) = 0;
	virtual void vAusgabe(std::ostream& ausgabe) const;
	void vSetName(std::string something);

};
// upcoming tasks: keep working on vSimulieren


#endif /* SIMULATIONSOBJEKT_H_ */
