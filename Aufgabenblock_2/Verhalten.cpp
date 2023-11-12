#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

Verhalten::Verhalten(Weg& initWeg)
	: p_pWeg(initWeg)
{
}

Verhalten::~Verhalten()
{
}

double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (p_pWeg.getLaenge() - aFzg.getAbschnittStrecke() > aFzg.dGeschwindigkeit() * dZeitIntervall)
	{
		return aFzg.dGeschwindigkeit() * dZeitIntervall;
	}
	else
	{
		return p_pWeg.getLaenge() - aFzg.getAbschnittStrecke();
	}
}
