#include "Fahren.h"
#include "Fahrzeug.h"
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
	double tempStrecke = Verhalten::dStrecke(aFzg, dZeitIntervall);
	if (abs(tempStrecke) < 3 * std::numeric_limits<double>::min()) { std::cout << "(" << aFzg.getName() << ") Wegende erreicht" << std::endl; }
	return tempStrecke;
}
