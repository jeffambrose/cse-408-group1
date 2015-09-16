#include "rgbinstance.h"

using namespace std;

RGBInstance::RGBInstance()
{
    _r = -1;
    _g = -1;
    _b = -1;
}

string RGBInstance::getName()
{
    return ColorInstance::COLOR_RGB;
}

void RGBInstance::readInstance()
{
    cout << "R [0, 1]: ";
    cin >> _r;

    cout << "G [0, 1]: ";
    cin >> _g;

    cout << "B [0, 1]: ";
    cin >> _b;

    cout << "Read " << toString() << endl;
}

string RGBInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _r << "," << _g << "," << _b << ")";
    return ss.str();
}

ColorInstance::ColorVector RGBInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getName().compare(ColorInstance::COLOR_RGB) != 0)
        return ColorVector();

    ColorVector v(partitions);
    RGBInstance *rother = (RGBInstance *)other;

    float rdist = rother->_r - _r;
    float gdist = rother->_g - _g;
    float bdist = rother->_b - _b;

    float rstep = rdist / partitions;
    float gstep = gdist / partitions;
    float bstep = bdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new RGBInstance(
                _r + (rstep/2) + i*rstep,
                _g + (gstep/2) + i*gstep,
                _b + (bstep/2) + i*bstep
            );
    }

    return v;
}
