#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"

Parken::Parken(Weg& initWeg, double initStartZeit)
	: Verhalten(initWeg), p_dStartZeit(initStartZeit)
{
}

Parken::~Parken()
{
}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (dGlobaleZeit < p_dStartZeit) return 0.0;

	std::cout << '(' << aFzg.getName() << ") ist losgefahren!" << std::endl;

	return 0;
}
