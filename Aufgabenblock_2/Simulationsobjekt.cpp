#include "Simulationsobjekt.h"
int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt(std::string initName)
	: p_sName(initName), p_iID(p_iMaxID++), p_dZeit(0)
{
	std::cout << "Simulationsobjekt generated: " << p_sName << " - " << p_iID << std::endl;
}

Simulationsobjekt::~Simulationsobjekt()
{
	std::cout << "Simulationsobjekt deleted: " << p_sName << " - " << p_iID << std::endl;
}

void Simulationsobjekt::vAusgeben(std::ostream& out) const
{
	auto oldWidth = out.width();
	auto oldPrec = out.precision();

	out << std::setw(3) << p_iID;
	out << std::setw(1) << ' ';
	out << std::setw(10) << std::setiosflags(std::ios::left) << p_sName << std::resetiosflags(std::ios::left);
	
	out << std::setw(oldWidth) << std::setprecision(oldPrec);
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& oprnd) const
{
	return p_iID == oprnd.p_iID;
}

std::string Simulationsobjekt::getName()
{
	return p_sName;
}

std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& inst)
{
	inst.vAusgeben(out);
	return out;
}
