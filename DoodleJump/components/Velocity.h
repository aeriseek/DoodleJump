#pragma once

struct Velocity
{
	float x{};
	float y{};

	Velocity operator*(float value)
	{
		return Velocity(x * value, y * value);
	};
};