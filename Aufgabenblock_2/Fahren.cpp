#include "Fahren.h"
#include "Weg.h"

Fahren::Fahren(Weg& initWeg)
	: Verhalten(initWeg)
{
}

Fahren::~Fahren()
{
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	return Verhalten::dStrecke(aFzg, dZeitIntervall);
}
