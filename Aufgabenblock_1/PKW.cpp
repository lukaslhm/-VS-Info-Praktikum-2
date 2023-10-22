#include "PKW.h"

PKW::PKW(std::string initName, double initMaxVelo, double initVerbrauch, double initTankvolumen)
	: Fahrzeug(initName, initMaxVelo), p_dVerbrauch(initVerbrauch), p_dTankvolumen(initTankvolumen), p_dTankinhalt(p_dTankvolumen/2)
{
}

PKW::~PKW()
{
}

double PKW::dTanken(double dMenge)
{
	if (dMenge < 0) return 0;
	if (dMenge > p_dTankvolumen - p_dTankinhalt)
	{
		double dGetankt = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dGetankt;
	}
	
	p_dTankinhalt += dMenge;

	return dMenge;
}

void PKW::vSimulieren()
{
	if (p_dTankinhalt > 0)
	{
		double ds = p_dGesamtStrecke;
		Fahrzeug::vSimulieren();
		ds = p_dGesamtStrecke - ds;
		p_dTankinhalt -= ds * p_dVerbrauch / 100;
	}
	else
	{
		p_dZeit = dGlobaleUhr;
	}
}

void PKW::vAusgeben(std::ostream& out) const
{
	Fahrzeug::vAusgeben(out);
	out << std::setw(1) << ' ';
	out << std::setw(15) << p_dGesamtStrecke * p_dVerbrauch / 100;
	out << std::setw(1) << ' ';
	out << std::setw(10) << p_dTankinhalt;
}
