#include "colorinstance.h"

using namespace std;

const string ColorInstance::COLOR_RGB = "RGB";
const string ColorInstance::COLOR_XYZ = "XYZ";
const string ColorInstance::COLOR_LAB = "Lab";
const string ColorInstance::COLOR_YUV = "YUV";
const string ColorInstance::COLOR_YCBCR = "YCbCr";
const string ColorInstance::COLOR_YIQ = "YIQ";
const string ColorInstance::COLOR_HSL = "HSL";

const string ColorInstance::COLOR_SPACES[] = { COLOR_RGB, COLOR_XYZ, COLOR_LAB, COLOR_YUV, COLOR_YCBCR, COLOR_YIQ, COLOR_HSL };
const int ColorInstance::NUM_COLOR_SPACES = sizeof(COLOR_SPACES) / sizeof(string);

string ColorInstance::getType()
{
    return _type;
}

void ColorInstance::readInstance()
{
    char c1name, c2name, c3name;
    int c1low, c2low, c3low;
    int c1high, c2high, c3high;

    if (_type.compare(COLOR_RGB) == 0) {
        c1name = 'R'; c1low = 0; c1high = 1;
        c2name = 'G'; c2low = 0; c2high = 1;
        c3name = 'B'; c3low = 0; c3high = 1;
    }
    else if (_type.compare(COLOR_XYZ) == 0) {
        c1name = 'X'; c1low = 0; c1high = 1;
        c2name = 'Y'; c2low = 0; c2high = 1;
        c3name = 'Z'; c3low = 0; c3high = 1;
    }
    else if (_type.compare(COLOR_LAB) == 0) {
        c1name = 'L'; c1low = 0; c1high = 100;
        c2name = 'a'; c2low = -1; c2high = 1;
        c3name = 'b'; c3low = -1; c3high = 1;
    }
    else if (_type.compare(COLOR_YUV) == 0) {
        c1name = 'Y'; c1low = 0; c1high = 1;
        c2name = 'U'; c2low = -1; c2high = 1;
        c3name = 'V'; c3low = -1; c3high = 1;
    }
    else if (_type.compare(COLOR_YCBCR) == 0) {
        c1name = 'Y'; c1low = 0; c1high = 1;
        c2name = 'Cb'; c2low = -1; c2high = 1;
        c3name = 'Cr'; c3low = -1; c3high = 1;
    }
    else if (_type.compare(COLOR_YIQ) == 0) {
        c1name = 'Y'; c1low = 0; c1high = 1;
        c2name = 'I'; c2low = -1; c2high = 1;
        c3name = 'Q'; c3low = -1; c3high = 1;
    }
    else if (_type.compare(COLOR_HSL) == 0) {
        c1name = 'H'; c1low = 0; c1high = 360;
        c2name = 'S'; c2low = 0; c2high = 1;
        c3name = 'L'; c3low = 0; c3high = 1;
    }

    cout << c1name << " [" << c1low << ", " << c1high << "]: ";
    cin >> _c1;

    cout << c2name << " [" << c2low << ", " << c2high << "]: ";
    cin >> _c2;

    cout << c3name << " [" << c3low << ", " << c3high << "]: ";
    cin >> _c3;

    cout << "Read " << toString() << endl;
}

string ColorInstance::toString()
{
    stringstream ss;
    ss << getType() << "(" << _c1 << "," << _c2 << "," << _c3 << ")";
    return ss.str();
}

ColorInstance::ColorVector ColorInstance::interpolate(ColorInstance *other, int partitions)
{
    if (other->getType().compare(getType()) != 0)
        return ColorVector();

    ColorVector v(partitions);

    float c1dist = other->_c1 - _c1;
    float c2dist = other->_c2 - _c2;
    float c3dist = other->_c3 - _c3;

    float c1step = c1dist / partitions;
    float c2step = c2dist / partitions;
    float c3step = c3dist / partitions;

    for (int i = 0; i < partitions; i++) {
        v[i] = new ColorInstance(
                getType(),
                _c1 + (c1step/2) + i*c1step,
                _c2 + (c2step/2) + i*c2step,
                _c3 + (c3step/2) + i*c3step
            );
    }

    return v;
}

ColorInstance *ColorInstance::makeInstance(string type)
{
    ColorInstance *instance = new ColorInstance(type);
    instance->readInstance();
    return instance;
}
