#include "labinstance.h"

using namespace std;

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

    cout << "Read " << toString() << endl;
}

string LABInstance::toString()
{
    stringstream ss;
    ss << getName() << "(" << _l << "," << _a << "," << _b << ")";
    return ss.str();
}

ColorInstance::ColorVector LABInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getName().compare(getName()) != 0)
        return ColorVector();

    ColorVector v(partitions);
    LABInstance *rother = (LABInstance *)other;

    float ldist = rother->_l - _l;
    float adist = rother->_a - _a;
    float bdist = rother->_b - _b;

    float lstep = ldist / partitions;
    float astep = adist / partitions;
    float bstep = bdist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new LABInstance(
                _l + (lstep/2) + i*lstep,
                _a + (astep/2) + i*astep,
                _b + (bstep/2) + i*bstep
            );
    }

    return v;
}
