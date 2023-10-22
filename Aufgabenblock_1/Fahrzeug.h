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

extern double dGlobaleUhr;

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(std::string initName, double initMaxVelo = 0);
	Fahrzeug(const Fahrzeug&) = delete;
	virtual ~Fahrzeug();

	static void vKopf();
	virtual void vAusgeben(std::ostream& out) const;

	virtual void vSimulieren();

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

	virtual double dGeschwindigkeit() const;

	double getGesamtStrecke() const;

	bool operator<(const Fahrzeug& oprnd);
	Fahrzeug& operator=(const Fahrzeug& oprnd);

protected:
	double p_dMaxGeschwindigkeit;
	double p_dZeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;

private:
	std::string p_sName;
	const int p_iID;
	static int p_iIDCnt;

};

std::ostream& operator<<(std::ostream& out, const Fahrzeug& inst);
