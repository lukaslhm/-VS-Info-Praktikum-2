#pragma once

#include <limits>

typedef enum
{
	Innerorts = 50,
	Landstraße = 100,
	Autobahn = std::numeric_limits<int>::max()
} Tempolimit;
