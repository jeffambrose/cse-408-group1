#include "yiqinstance.h"

YIQInstance::YIQInstance()
{
    _y = -1;
    _i = -1;
    _q = -1;
}

string YIQInstance::getName()
{
    return ColorInstance::COLOR_YIQ;
}

void YIQInstance::readInstance()
{
    cout << "Y [0, 1]: ";
    cin >> _y;

    cout << "I [-1, 1]: ";
    cin >> _i;

    cout << "Q [-1, 1]: ";
    cin >> _q;

    cout << "Read " << getName() << "(" << _y << "," << _i << "," << _q << ")" << endl;
}
