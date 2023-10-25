#include <vector>
#include <memory>

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

double dGlobaleZeit = 0;

void vAufgabe_1()
{
	Fahrzeug F1;
	Fahrzeug* F2 = new Fahrzeug("PKW");
	delete F2; // destruction of F2

	std::unique_ptr<Fahrzeug> p1 = std::make_unique<Fahrzeug>();
	std::unique_ptr<Fahrzeug> p2 = std::make_unique<Fahrzeug>("PKW");
	std::shared_ptr<Fahrzeug> p3 = std::make_shared<Fahrzeug>();
	std::shared_ptr<Fahrzeug> p4 = std::make_shared<Fahrzeug>("PKW");

	std::cout << "p3.use_count: " << p3.use_count() << std::endl;
	std::shared_ptr<std::shared_ptr<Fahrzeug>> p5 = std::make_shared<std::shared_ptr<Fahrzeug>>(p3);
	std::cout << "p3.use_count: " << p3.use_count() << std::endl;

	std::cout << std::endl << "Vector: " << std::endl;

	std::vector<std::unique_ptr<Fahrzeug>> vec;

	vec.push_back(move(p1));
	vec.push_back(move(p2));

	vec.clear(); //destruct p1, p2

	std::cout << std::endl << "2nd Vector" << std::endl;

	std::cout << "use_counts: " << "p3: " << p3.use_count() << " p4: " << p4.use_count() << std::endl;

	std::vector<std::shared_ptr<Fahrzeug>> vec2;
	vec2.push_back(p3);
	vec2.push_back(move(p4));

	std::cout << "use_counts: " << "p3: " << vec2.at(0).use_count() << " p4: " << vec2.at(1).use_count() << std::endl;

	std::cout << std::endl << "Finish function" << std::endl;
} // destruction of everything else

void vAufgabe_1a()
{
	std::vector<std::unique_ptr<Fahrzeug>> vec;
	vec.push_back(move(std::make_unique<PKW>("PKW1", 30, 8.9)));
	vec.push_back(move(std::make_unique<Fahrzeug>("Auto2", 50)));
	vec.push_back(move(std::make_unique<Fahrzeug>("Auto3", 70)));
	vec.push_back(move(std::make_unique<Fahrrad>("Rad1", 20)));

	double takt = 0.125;

	for (int i = 0; i < 16; i++)
	{
		dGlobaleZeit += takt;
		Fahrzeug::vKopf();
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			it->get()->vSimulieren();
			it->get()->vAusgeben(std::cout);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Finishing up!" << std::endl;
	Fahrzeug::vKopf();
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		it->get()->vAusgeben(std::cout);
		std::cout << std::endl;
	}
}

void vAufgabe_2()
{
	std::vector<std::unique_ptr<Fahrzeug>> vec;
	vec.push_back(move(std::make_unique<PKW>("PKW1", 30, 8.9)));
	vec.push_back(move(std::make_unique<PKW>("PKW2", 50, 7)));
	vec.push_back(move(std::make_unique<Fahrrad>("Rad1", 20)));
	vec.push_back(move(std::make_unique<Fahrrad>("Rad2", 25)));

	double takt = 0.01;

	bool getankt = false;

	for (int i = 0; i < 6/takt; i++)
	{
		dGlobaleZeit += takt;

		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			it->get()->vSimulieren();
		}

		if (dGlobaleZeit > 3 and !(getankt))
		{
			getankt = true;

			for (auto it = vec.begin(); it != vec.end(); it++)
			{
				it->get()->dTanken();
			}
		}

		if (!(i%50))
		{
			std::cout << "Time: " << dGlobaleZeit << std::endl;
			Fahrzeug::vKopf();
			for (auto it = vec.begin(); it != vec.end(); it++)
			{
				it->get()->vAusgeben(std::cout);
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

void vAufgabe_3()
{
	std::vector<std::unique_ptr<Fahrzeug>> vec;
	vec.push_back(move(std::make_unique<PKW>("PKW1", 30, 8.9)));
	vec.push_back(move(std::make_unique<PKW>("PKW2", 50, 7)));
	vec.push_back(move(std::make_unique<Fahrrad>("Rad1", 20)));
	vec.push_back(move(std::make_unique<Fahrrad>("Rad2", 25)));

	dGlobaleZeit += 1;

	std::cout << std::endl;

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		it->get()->vSimulieren();
	}

	Fahrzeug::vKopf();
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it->get() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "PKW1 < PKW2: " << (vec.at(0) < vec.at(1)) << std::endl;
	std::cout << "PKW2 < PKW1: " << (vec.at(1) < vec.at(0)) << std::endl << std::endl;

	std::cout << "PKW1 = PKW2" << std::endl;
	*vec.at(0).get() = *vec.at(1).get();

	Fahrzeug::vKopf();
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it->get() << std::endl;
	}
	std::cout << std::endl << "FINISH!" << std::endl << std::endl;
}

int main()
{
	vAufgabe_3();
	return 0;
}
