#ifndef COLORINSTANCE_H
#define COLORINSTANCE_H

#include <iostream>

using namespace std;


class ColorInstance
{
public:
    ColorInstance();

    string getName() { return 0; }
    void readInstance() { }

    static ColorInstance *makeInstance(string type);

    static const string COLOR_RGB;
    static const string COLOR_XYZ;
    static const string COLOR_LAB;
    static const string COLOR_YUV;
    static const string COLOR_YCBCR;
    static const string COLOR_YIQ;
    static const string COLOR_HSL;

    static const string COLOR_SPACES[];
    static const int NUM_COLOR_SPACES;
};

#endif // COLORINSTANCE_H
