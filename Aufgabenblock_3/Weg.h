/*
 * Weg.cpp
 *
 *  Created on: Nov 9, 2025
 *      Author: HaiPH
 */

#ifndef WEG_H_
#define WEG_H_
#include <iostream>
#include <string>
#include <memory>
#include "Simulationsobjekt.h"
#include <list>
#include <limits>
#include "Tempolimit.h"
#include "vertagt_liste.h"
#include "vertagt_aktion.h"

class Fahrzeug;

class Weg : public Simulationsobjekt
{
	protected:
	double p_dLaenge;
	enum Tempolimit p_eTempolimit;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	bool p_bUeberholverbot = true;
	double p_dVirtuelleSchranke;
	Fahrzeug* p_pVorherFzg = nullptr;

	public:
	Weg() = delete;
	Weg(Weg& weg) = delete;
	Weg(std::string name, double laenge, enum Tempolimit tempolimit, bool ueberholen);
	virtual ~Weg() = default;

	enum Tempolimit getTempolimit();
	double dGetLaenge() const;
	const vertagt::VListe<std::unique_ptr<Fahrzeug>>& getFahrzeuge() const;
	bool bGetUeberhol();
	double dGetVirtuelleSchranke() const;

	void vSimulieren(double dTimeStep) override;
	void vKopf() const;
	void vAusgabe(std::ostream& ausgabe) const override;
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double start);

	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug&);
};




#endif /* WEG_H_ */
