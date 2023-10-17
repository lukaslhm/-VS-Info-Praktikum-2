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
	Fahrzeug(std::string initName);
	Fahrzeug(std::string initName, double initMaxVelo);
	virtual ~Fahrzeug();

	static void vKopf();
	void vAusgeben();

	void vSimulieren();


private:
	std::string p_sName;
	const int p_iID;
	static int p_iIDCnt;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;

};
