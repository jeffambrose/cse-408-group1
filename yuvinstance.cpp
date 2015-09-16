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
    return ColorVector();
}
