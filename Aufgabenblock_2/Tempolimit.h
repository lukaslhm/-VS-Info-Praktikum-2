#pragma once

#include <limits>

enum class Tempolimit
{
	Innerorts = 50,
	Landstraße = 100,
	Autobahn = std::numeric_limits<int>::max()
};
