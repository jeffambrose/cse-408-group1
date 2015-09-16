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
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    HSLInstance *rother = (HSLInstance *)other;

    float hdist = rother->_h - _h;
    float sdist = rother->_s - _s;
    float ldist = rother->_l - _l;

    float hstep = hdist / partitions;
    float sstep = sdist / partitions;
    float lstep = ldist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new HSLInstance(
                _h + (hstep/2) + i*hstep,
                _s + (sstep/2) + i*sstep,
                _l + (lstep/2) + i*lstep
            );
    }

    return v;
}
