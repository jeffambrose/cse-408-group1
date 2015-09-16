#include "yiqinstance.h"

using namespace std;

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

    cout << "Read " << toString() << endl;
}

string YIQInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _y << "," << _i << "," << _q << ")";
    return ss.str();
}

ColorInstance::ColorVector YIQInstance::interpolate(ColorInstance *other, int partitions)
{
    return ColorVector();
}
