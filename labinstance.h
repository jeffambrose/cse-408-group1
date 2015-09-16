#ifndef LABINSTANCE_H
#define LABINSTANCE_H

#include "colorinstance.h"

class LABInstance : public ColorInstance
{
public:
    LABInstance();
    LABInstance(float l, float a, float b) {
        _l = l;
        _a = a;
        _b = b;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _l;
    float _a;
    float _b;
};


#endif // LABINSTANCE_H
