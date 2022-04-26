#pragma once

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : DestroyableGroundObject
{
private:
	TankAdaptee tank;
public:

	void Draw() const override { tank.Paint(); }
	bool __fastcall isInside(double x1, double x2) const override
	{
		return tank.isInRange(x1, x2);
	}

	inline uint16_t GetScore() const override { return tank.GetScore(); }

	inline void SetPos(double nx, double ny) override { tank.SetPos(nx, ny); }

	inline double GetY() const override { return tank.GetY(); }

	inline double GetX() const { return tank.GetX(); }

	inline void SetWidth(uint16_t widthN) override { tank.SetWidth(widthN); }

	inline uint16_t GetWidth() const { return tank.GetWidth(); }
};
