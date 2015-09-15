#ifndef YUVINSTANCE_H
#define YUVINSTANCE_H

#include "colorinstance.h"

class YUVInstance : public ColorInstance
{
public:
    YUVInstance();

    string getName();
    void readInstance();

private:
    float _y;
    float _u;
    float _v;
};

#endif // YUVINSTANCE_H
