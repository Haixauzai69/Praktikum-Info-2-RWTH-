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
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual ~Simulationsobjekt() = default;
	bool operator==(const Simulationsobjekt& vergleich);
	virtual void vSimulieren() = 0;
	virtual void vAusgabe() const;
};



#endif /* SIMULATIONSOBJEKT_H_ */
