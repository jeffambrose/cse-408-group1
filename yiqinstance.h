#ifndef YIQINSTANCE_H
#define YIQINSTANCE_H

#include "colorinstance.h"

class YIQInstance : public ColorInstance
{
public:
    YIQInstance();

    string getName();
    void readInstance();

private:
    float _y;
    float _i;
    float _q;
};

#endif // YIQINSTANCE_H
