#ifndef RGBINSTANCE_H
#define RGBINSTANCE_H

#include "colorinstance.h"

class RGBInstance : public ColorInstance
{
public:
    RGBInstance();
    RGBInstance(float r, float g, float b) {
        _r = r;
        _g = g;
        _b = b;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _r;
    float _g;
    float _b;
};

#endif // RGBINSTANCE_H
