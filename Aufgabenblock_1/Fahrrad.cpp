#include "Fahrrad.h"

Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(std::string initName, double initMaxVelo)
	: Fahrzeug(initName, initMaxVelo)
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dGeschwindigkeit() const
{
	if (p_dMaxGeschwindigkeit < 12) return p_dMaxGeschwindigkeit;

	double result = p_dMaxGeschwindigkeit * std::pow(0.9, p_dGesamtStrecke/20);

	if (result < 12) return 12;
	else return result;
}


