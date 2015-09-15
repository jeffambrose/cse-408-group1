#include "ycbcrinstance.h"

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

    cout << "Read " << getName() << "(" << _y << "," << _cb << "," << _cr << ")" << endl;
}
