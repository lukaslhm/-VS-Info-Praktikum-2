#include "Weg.h"
#include "Fahrzeug.h"

Weg::Weg(std::string initName, double initLaenge, Tempolimit initTempolimit)
	: Simulationsobjekt(initName), p_dLaenge(initLaenge), p_eTempolimit(initTempolimit)
{
}

Weg::~Weg()
{
}

void Weg::vKopf()
{
	auto oldWidth = std::cout.width();
	auto oldFill = std::cout.fill();

	std::cout << std::setiosflags(std::ios::left);

	std::cout << std::setw(2) << "ID";
	std::cout << std::setw(1) << '|';
	std::cout << std::setw(10) << "Name";
	std::cout << std::setw(1) << '|';
	std::cout << std::setw(8) << "Laenge";
	std::cout << std::setw(1) << '|';
	std::cout << std::setw(22) << "Fahrzeuge";
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(2 + 1 + 10 + 1 + 8 + 1 + 22) << '-';
	std::cout << std::endl;

	std::cout << std::resetiosflags(std::ios::left);
	std::cout << std::setw(oldWidth) << std::setfill(oldFill);
}

void Weg::vSimulieren()
{
	for (auto& it : p_pFahrzeuge)
	{
		it->vSimulieren();
	}
}

void Weg::vAusgeben(std::ostream& out) const
{
	auto oldWidth = out.width();
	auto oldPrec = out.precision();

	Simulationsobjekt::vAusgeben(out);

	out << std::setw(1) << ' ';
	out << std::setw(8) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << p_dLaenge;
	out << std::setw(1) << ' ';
	out << std::setw(1) << '(';
	int fahrzeugAmount = p_pFahrzeuge.size();
	for (auto& it : p_pFahrzeuge)
	{
		out << std::setw(10) << it->getName();
		if (--fahrzeugAmount > 0)
			out << std::setw(1) << ',';
	}
	out << std::setw(1) << ')';

	out << std::setw(oldWidth) << std::setprecision(oldPrec);
}

double Weg::getTempolimit()
{
	return (double) p_eTempolimit;
}
