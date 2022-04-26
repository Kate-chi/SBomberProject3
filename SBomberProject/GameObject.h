#pragma once

class GameObject {
public:

    GameObject() : x(0.0), y(0.0), width(0) { }

    virtual void Draw() const = 0;

    inline virtual void SetPos(double nx, double ny) { x = nx; y = ny; }

    inline virtual double GetY() const { return y; }
    inline virtual double GetX() const { return x; }

    inline virtual void SetWidth(uint16_t widthN) { width = widthN; }
    inline virtual uint16_t GetWidth() const { return width; }

protected:

    double x, y;
    uint16_t width;
};