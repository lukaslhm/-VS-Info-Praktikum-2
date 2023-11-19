#pragma once

extern double dGlobaleZeit;

class Weg;
class Fahrzeug;

class Verhalten
{
public:
	Verhalten(Weg& initWeg);
	virtual ~Verhalten();

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;

private:
	Weg& p_pWeg;
};

