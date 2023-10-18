/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2023
 *      Author: llohm
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iIDCnt = 0;

Fahrzeug::Fahrzeug()
	: p_sName(""), p_iID(p_iIDCnt++), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0), p_dGesamtZeit(0), p_dZeit(0)
{
	std::cout << "New Fahrzeug generated: " << p_sName << " - " << p_iID << std::endl;

}

Fahrzeug::Fahrzeug(std::string initName)
	: p_sName(initName), p_iID(p_iIDCnt++), p_dMaxGeschwindigkeit(0), p_dGesamtStrecke(0), p_dGesamtZeit(0), p_dZeit(0)
{
	std::cout << "New Fahrzeug generated: " << p_sName << " - " << p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string initName, double initMaxVelo)
	: p_sName(initName), p_iID(p_iIDCnt++), p_dMaxGeschwindigkeit(initMaxVelo), p_dGesamtStrecke(0), p_dGesamtZeit(0), p_dZeit(0)
{
	std::cout << "New Fahrzeug generated: " << p_sName << " - " << p_iID << std::endl;
}

Fahrzeug::~Fahrzeug()
{
	std::cout << "Fahrzeug deleted: " << p_sName << " - " << p_iID << std::endl;
}

void Fahrzeug::vKopf()
{
	auto oldWidth = std::cout.width();
	auto oldFill = std::cout.fill();

	std::cout << std::setiosflags(std::ios::left);

	std::cout << std::setw(2) << "ID";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(5) << "Name";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(18) << "MaxGeschwindigkeit";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(13) << "GesamtStrecke";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(15) << "GesamtVerbrauch";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(10) << "Tankinhalt";
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(41 + 27) << '-';
	std::cout << std::endl;

	std::cout << std::resetiosflags(std::ios::left);
	std::cout << std::setw(oldWidth) << std::setfill(oldFill);
}

void Fahrzeug::vAusgeben() const
{
	auto oldWidth = std::cout.width();
	auto oldPrec = std::cout.precision();

	std::cout << std::setw(2) << p_iID;
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(5) << std::setiosflags(std::ios::left) << p_sName << std::resetiosflags(std::ios::left);
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(18) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << p_dMaxGeschwindigkeit;
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(13) << p_dGesamtStrecke << std::resetiosflags(std::ios::fixed);

	std::cout << std::setw(oldWidth) << std::setprecision(oldPrec);
}

void Fahrzeug::vSimulieren()
{
	double dt = dGlobaleUhr - p_dZeit;
	if (abs(dt) < 3 * std::numeric_limits<double>::min()) { std::cout << "Fahrzeug doppelt simuliert: (" << p_sName << ', ' << p_iID << ')' << std::endl; return; }
	p_dZeit = dGlobaleUhr;
	p_dGesamtZeit += dt;
	p_dGesamtStrecke += p_dMaxGeschwindigkeit * dt;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}


