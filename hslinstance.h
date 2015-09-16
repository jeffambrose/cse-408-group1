#ifndef HSLINSTANCE_H
#define HSLINSTANCE_H

#include "colorinstance.h"

class HSLInstance : public ColorInstance
{
public:
    HSLInstance();
    HSLInstance(float h, float s, float l) {
        _h = h;
        _s = s;
        _l = l;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _h;
    float _s;
    float _l;
};


#endif // HSLINSTANCE_H
