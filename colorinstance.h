#ifndef COLORINSTANCE_H
#define COLORINSTANCE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class ColorInstance
{
public:

    typedef std::vector<ColorInstance *> ColorVector;

    ColorInstance();

    virtual std::string getName() = 0;
    virtual void readInstance()  = 0;
    virtual ColorVector interpolate(ColorInstance *other, int partitions) = 0;

    virtual std::string toString() = 0;

    static ColorInstance *makeInstance(std::string type);

    static const std::string COLOR_RGB;
    static const std::string COLOR_XYZ;
    static const std::string COLOR_LAB;
    static const std::string COLOR_YUV;
    static const std::string COLOR_YCBCR;
    static const std::string COLOR_YIQ;
    static const std::string COLOR_HSL;

    static const std::string COLOR_SPACES[];
    static const int NUM_COLOR_SPACES;
};

#endif // COLORINSTANCE_H
