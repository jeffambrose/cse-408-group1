#ifndef XYZINSTANCE_H
#define XYZINSTANCE_H

#include "colorinstance.h"

class XYZInstance : public ColorInstance
{
public:
    XYZInstance();
    XYZInstance(float x, float y, float z) {
        _x = x;
        _y = y;
        _z = z;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _x;
    float _y;
    float _z;
};

#endif // XYZINSTANCE_H
