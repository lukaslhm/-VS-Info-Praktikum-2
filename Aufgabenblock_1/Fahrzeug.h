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
	virtual ~Fahrzeug();

	static void vKopf();
	virtual void vAusgeben() const;

	virtual void vSimulieren();

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

	virtual double dGeschwindigkeit() const;

protected:
	const double p_dMaxGeschwindigkeit;
	double p_dZeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;

private:
	const std::string p_sName;
	const int p_iID;
	static int p_iIDCnt;

};
