#ifndef XYZINSTANCE_H
#define XYZINSTANCE_H

#include "colorinstance.h"

class XYZInstance : public ColorInstance
{
public:
    XYZInstance();

    string getName();
    void readInstance();

private:
    float _x;
    float _y;
    float _z;
};

#endif // XYZINSTANCE_H
