#include "xyzinstance.h"

XYZInstance::XYZInstance()
{
    _x = -1;
    _y = -1;
    _z = -1;
}

string XYZInstance::getName()
{
    return ColorInstance::COLOR_XYZ;
}

void XYZInstance::readInstance()
{
    cout << "X [0, 1]: ";
    cin >> _x;

    cout << "Y [0, 1]: ";
    cin >> _y;

    cout << "Z [0, 1]: ";
    cin >> _z;

    cout << "Read " << getName() << "(" << _x << "," << _y << "," << _z << ")" << endl;
}
