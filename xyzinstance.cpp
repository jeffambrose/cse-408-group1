#include "xyzinstance.h"

using namespace std;

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

    cout << "Read " << toString() << endl;
}

string XYZInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _x << "," << _y << "," << _z << ")";
    return ss.str();
}

ColorInstance::ColorVector XYZInstance::interpolate(ColorInstance *other, int partitions)
{
    return ColorVector();
}
