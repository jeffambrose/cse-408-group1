#include "rgbinstance.h"

RGBInstance::RGBInstance()
{
    _r = -1;
    _g = -1;
    _b = -1;
}

string RGBInstance::getName()
{
    return "RGB";
}

void RGBInstance::readInstance()
{
    cout << "R [0, 1]: ";
    cin >> _r;

    cout << "G [0, 1]: ";
    cin >> _g;

    cout << "B [0, 1]: ";
    cin >> _b;

    cout << "Read " << getName() << "(" << _r << "," << _g << "," << _b << ")" << endl;
}
