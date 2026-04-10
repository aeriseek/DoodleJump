#pragma once
#include "Velocity.h"

struct Position
{
	float x{};
	float y{};

	void operator+=(Velocity v)
	{
		x += v.x;
		y += v.y;
	};
};
