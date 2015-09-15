#ifndef HSLINSTANCE_H
#define HSLINSTANCE_H

#include "colorinstance.h"

class HSLInstance : public ColorInstance
{
public:
    HSLInstance();

    string getName();
    void readInstance();

private:
    float _h;
    float _s;
    float _l;
};


#endif // HSLINSTANCE_H
