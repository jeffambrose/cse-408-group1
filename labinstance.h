#ifndef LABINSTANCE_H
#define LABINSTANCE_H

#include "colorinstance.h"

class LABInstance : public ColorInstance
{
public:
    LABInstance();

    string getName();
    void readInstance();

private:
    float _l;
    float _a;
    float _b;
};


#endif // LABINSTANCE_H
