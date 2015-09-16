#include "yiqinstance.h"

using namespace std;

YIQInstance::YIQInstance()
{
    _y = -1;
    _i = -1;
    _q = -1;
}

string YIQInstance::getName()
{
    return ColorInstance::COLOR_YIQ;
}

void YIQInstance::readInstance()
{
    cout << "Y [0, 1]: ";
    cin >> _y;

    cout << "I [-1, 1]: ";
    cin >> _i;

    cout << "Q [-1, 1]: ";
    cin >> _q;

    cout << "Read " << toString() << endl;
}

string YIQInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _y << "," << _i << "," << _q << ")";
    return ss.str();
}

ColorInstance::ColorVector YIQInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    YIQInstance *rother = (YIQInstance *)other;

    float ydist = rother->_y - _y;
    float idist = rother->_i - _i;
    float qdist = rother->_q - _q;

    float ystep = ydist / partitions;
    float istep = idist / partitions;
    float qstep = qdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new YIQInstance(
                _y + (ystep/2) + i*ystep,
                _i + (istep/2) + i*istep,
                _q + (qstep/2) + i*qstep
            );
    }

    return v;
}
