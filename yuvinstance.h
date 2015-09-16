#ifndef YUVINSTANCE_H
#define YUVINSTANCE_H

#include "colorinstance.h"

class YUVInstance : public ColorInstance
{
public:
    YUVInstance();
    YUVInstance(float y, float u, float v) {
        _y = y;
        _u = u;
        _v = v;
    }

    std::string getName();
    void readInstance();
    ColorVector interpolate(ColorInstance *other, int partitions);
    std::string toString();

private:
    float _y;
    float _u;
    float _v;
};

#endif // YUVINSTANCE_H
