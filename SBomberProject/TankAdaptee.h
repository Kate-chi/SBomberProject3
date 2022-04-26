#pragma once

#include <stdint.h>

class TankAdaptee {
public:
	TankAdaptee() : x(0.0), y(0.0), width(0) { }

	void Paint() const;
	bool __fastcall isInRange(double x1, double x2) const;

	inline uint16_t GetScore() const { return score; }

	inline void SetPos(double nx, double ny) { x = nx; y = ny; }
	inline double GetY() const { return y; }
	inline double GetX() const { return x; }

	inline void SetWidth(uint16_t widthN) { width = widthN; }
	inline uint16_t GetWidth() const { return width; }

protected:
	double x, y;
	uint16_t width;
	const uint16_t score = 30;
};
