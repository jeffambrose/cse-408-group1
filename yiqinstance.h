#ifndef YIQINSTANCE_H
#define YIQINSTANCE_H

#include "colorinstance.h"

class YIQInstance : public ColorInstance
{
public:
    YIQInstance();
    YIQInstance(float y, float i, float q) {
        _y = y;
        _i = i;
        _q = q;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _y;
    float _i;
    float _q;
};

#endif // YIQINSTANCE_H
