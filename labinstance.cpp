#include "labinstance.h"

LABInstance::LABInstance()
{
    _l = -1;
    _a = -1;
    _b = -1;
}

string LABInstance::getName()
{
    return ColorInstance::COLOR_LAB;
}

void LABInstance::readInstance()
{
    cout << "L [0, 100]: ";
    cin >> _l;

    cout << "A [-1, 1]: ";
    cin >> _a;

    cout << "B [-1, 1]: ";
    cin >> _b;

    cout << "Read " << getName() << "(" << _l << "," << _a << "," << _b << ")" << endl;
}
