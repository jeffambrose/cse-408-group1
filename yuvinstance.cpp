#include "yuvinstance.h"

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

    cout << "Read " << getName() << "(" << _y << "," << _u << "," << _v << ")" << endl;
}
