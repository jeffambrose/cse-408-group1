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
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    XYZInstance *rother = (XYZInstance *)other;

    float xdist = rother->_x - _x;
    float ydist = rother->_y - _y;
    float zdist = rother->_z - _z;

    float xstep = xdist / partitions;
    float ystep = ydist / partitions;
    float zstep = zdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new XYZInstance(
                _x + (xstep/2) + i*xstep,
                _y + (ystep/2) + i*ystep,
                _z + (zstep/2) + i*zstep
            );
    }

    return v;
}
