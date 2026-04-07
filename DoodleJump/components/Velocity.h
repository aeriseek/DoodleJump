#pragma once
struct Velocity
{
	float x;
	float y;

	Velocity& operator*(float value)
	{
		x *= value;
		y *= value;
		return *this;
	};
};