#include "ycbcrinstance.h"

using namespace std;

YCbCrInstance::YCbCrInstance()
{
    _y = -1;
    _cb = -1;
    _cr = -1;
}

string YCbCrInstance::getName()
{
    return ColorInstance::COLOR_YCBCR;
}

void YCbCrInstance::readInstance()
{
    cout << "Y [0, 1]: ";
    cin >> _y;

    cout << "Cb [-1, 1]: ";
    cin >> _cb;

    cout << "Cr [-1, 1]: ";
    cin >> _cr;

    cout << "Read " << toString() << endl;
}

string YCbCrInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _y << "," << _cb << "," << _cr << ")";
    return ss.str();
}

ColorInstance::ColorVector YCbCrInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    YCbCrInstance *rother = (YCbCrInstance *)other;

    float ydist = rother->_y - _y;
    float cbdist = rother->_cb - _cb;
    float crdist = rother->_cr - _cr;

    float ystep = ydist / partitions;
    float cbstep = cbdist / partitions;
    float crstep = crdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new YCbCrInstance(
                _y + (ystep/2) + i*ystep,
                _cb + (cbstep/2) + i*cbstep,
                _cr + (crstep/2) + i*crstep
            );
    }

    return v;
}
