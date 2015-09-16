#include "hslinstance.h"

using namespace std;

HSLInstance::HSLInstance()
{
    _h = -1;
    _s = -1;
    _l = -1;
}

string HSLInstance::getName()
{
    return ColorInstance::COLOR_HSL;
}

void HSLInstance::readInstance()
{
    cout << "H [0, 360]: ";
    cin >> _h;

    cout << "S [0, 1]: ";
    cin >> _s;

    cout << "L [0, 1]: ";
    cin >> _l;

    cout << "Read " << toString() << endl;
}

string HSLInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _h << "," << _s << "," << _l << ")";
    return ss.str();
}

ColorInstance::ColorVector HSLInstance::interpolate(ColorInstance *other, int partitions)
{
    return ColorVector();
}
