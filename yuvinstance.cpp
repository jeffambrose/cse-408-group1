#include "yuvinstance.h"

using namespace std;

YUVInstance::YUVInstance()
{
    _y = -1;
    _u = -1;
    _v = -1;
}

string YUVInstance::getName()
{
    return ColorInstance::COLOR_YUV;
}

void YUVInstance::readInstance()
{
    cout << "Y [0, 1]: ";
    cin >> _y;

    cout << "U [-0.5, 0.5]: ";
    cin >> _u;

    cout << "V [-0.5, 0.5]: ";
    cin >> _v;

    cout << "Read " << toString() << endl;
}

string YUVInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _y << "," << _u << "," << _v << ")";
    return ss.str();
}

ColorInstance::ColorVector YUVInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    YUVInstance *rother = (YUVInstance *)other;

    float ydist = rother->_y - _y;
    float udist = rother->_u - _u;
    float vdist = rother->_v - _v;

    float ystep = ydist / partitions;
    float ustep = udist / partitions;
    float vstep = vdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new YUVInstance(
                _y + (ystep/2) + i*ystep,
                _u + (ustep/2) + i*ustep,
                _v + (vstep/2) + i*vstep
            );
    }

    return v;
}
