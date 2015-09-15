#ifndef RGBINSTANCE_H
#define RGBINSTANCE_H

#include "colorinstance.h"

class RGBInstance : public ColorInstance
{
public:
    RGBInstance();

    string getName();
    void readInstance();

private:
    float _r;
    float _g;
    float _b;
};

#endif // RGBINSTANCE_H
