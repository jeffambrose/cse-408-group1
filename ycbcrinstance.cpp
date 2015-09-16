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
    return ColorVector();
}
