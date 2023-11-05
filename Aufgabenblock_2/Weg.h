#pragma once

#include <list>
#include <string>

#include "Simulationsobjekt.h"
#include "Tempolimit.h"

class Fahrzeug;

class Weg : public Simulationsobjekt
{
public:
	Weg();
	Weg(std::string initName, double initLaenge);
	~Weg();

	double getTempolimit();

private:
	double p_dLaenge;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;
};

