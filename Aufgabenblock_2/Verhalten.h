#pragma once

class Weg;
class Fahrzeug;

class Verhalten
{
public:
	Verhalten(Weg& initWeg);
	~Verhalten();

	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

private:
	Weg& p_pWeg;
};

