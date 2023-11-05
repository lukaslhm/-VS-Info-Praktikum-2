/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2023
 *      Author: llohm
 */

#include "Fahrzeug.h"

Fahrzeug::Fahrzeug(std::string initName, double initMaxVelo)
	: Simulationsobjekt(initName), p_dMaxGeschwindigkeit(initMaxVelo), p_dGesamtStrecke(0), p_dGesamtZeit(0)
{
}

Fahrzeug::~Fahrzeug()
{
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
	std::cout << std::setw(15) << "Geschwindigkeit";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(15) << "GesamtVerbrauch";
	std::cout << std::setw(1) << ' ';
	std::cout << std::setw(10) << "Tankinhalt";
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(41 + 27 + 16) << '-';
	std::cout << std::endl;

	std::cout << std::resetiosflags(std::ios::left);
	std::cout << std::setw(oldWidth) << std::setfill(oldFill);
}

void Fahrzeug::vAusgeben(std::ostream& out) const
{
	auto oldWidth = out.width();
	auto oldPrec = out.precision();

	Simulationsobjekt::vAusgeben(out);

	out << std::setw(1) << ' ';
	out << std::setw(18) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << p_dMaxGeschwindigkeit;
	out << std::setw(1) << ' ';
	out << std::setw(13) << p_dGesamtStrecke;
	out << std::setw(1) << ' ';
	out << std::setw(15) << dGeschwindigkeit() << std::resetiosflags(std::ios::fixed);

	out << std::setw(oldWidth) << std::setprecision(oldPrec);
}

void Fahrzeug::vSimulieren()
{
	double dt = dGlobaleZeit - p_dZeit;
	if (abs(dt) < 3 * std::numeric_limits<double>::min()) { std::cout << "Fahrzeug doppelt simuliert: (" << p_sName << ', ' << p_iID << ')' << std::endl; return; }
	p_dZeit = dGlobaleZeit;
	p_dGesamtZeit += dt;
	p_dGesamtStrecke += dGeschwindigkeit() * dt;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::getGesamtStrecke() const
{
	return p_dGesamtStrecke;
}

bool Fahrzeug::operator<(const Fahrzeug& oprnd)
{
	return p_dGesamtStrecke < oprnd.getGesamtStrecke();
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& oprnd)
{
	if (this == &oprnd) return *this;
	p_sName = oprnd.p_sName;
	p_dMaxGeschwindigkeit = oprnd.p_dMaxGeschwindigkeit;
	return *this;
}
