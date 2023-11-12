/*
 * Fahrzeug.h
 *
 *  Created on: 15.10.2023
 *      Author: llohm
 */
#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>

#include "Simulationsobjekt.h"

extern double dGlobaleZeit;

class Weg;

class Fahrzeug : public Simulationsobjekt {
public:
	Fahrzeug(std::string initName = "", double initMaxVelo = 0);
	Fahrzeug(const Fahrzeug&) = delete;
	virtual ~Fahrzeug();

	static void vKopf();
	virtual void vAusgeben(std::ostream& out) const override;

	virtual void vSimulieren() override;

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

	virtual double dGeschwindigkeit() const;

	void vNeueStrecke(Weg& neuerWeg);

	double getGesamtStrecke() const;
	double getAbschnittStrecke() const;

	bool operator<(const Fahrzeug& oprnd);
	Fahrzeug& operator=(const Fahrzeug& oprnd);

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;

private:
	double p_dAbschnittStrecke;
	std::unique_ptr<Verhalten> p_pVerhalten;

};
