#ifndef YCBCRINSTANCE_H
#define YCBCRINSTANCE_H

#include "colorinstance.h"

class YCbCrInstance : public ColorInstance
{
public:
    YCbCrInstance();
    YCbCrInstance(float y, float cb, float cr) {
        _y = y;
        _cb = cb;
        _cr = cr;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _y;
    float _cb;
    float _cr;
};

#endif // YCBCRINSTANCE_H
