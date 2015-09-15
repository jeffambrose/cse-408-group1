#ifndef YCBCRINSTANCE_H
#define YCBCRINSTANCE_H

#include "colorinstance.h"

class YCbCrInstance : public ColorInstance
{
public:
    YCbCrInstance();

    string getName();
    void readInstance();

private:
    float _y;
    float _cb;
    float _cr;
};

#endif // YCBCRINSTANCE_H
