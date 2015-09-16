#include "colorinstance.h"

#include "rgbinstance.h"
#include "xyzinstance.h"
#include "labinstance.h"
#include "yuvinstance.h"
#include "ycbcrinstance.h"
#include "yiqinstance.h"
#include "hslinstance.h"

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

ColorInstance::ColorInstance()
{

}

ColorInstance *ColorInstance::makeInstance(string type)
{
    if (COLOR_RGB.compare(type) == 0) {
        RGBInstance *instance = new RGBInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_XYZ.compare(type) == 0) {
        XYZInstance *instance = new XYZInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_LAB.compare(type) == 0) {
        LABInstance *instance = new LABInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YUV.compare(type) == 0) {
        YUVInstance *instance  = new YUVInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YCBCR.compare(type) == 0) {
        YCbCrInstance *instance = new YCbCrInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YIQ.compare(type) == 0) {
        YIQInstance *instance = new YIQInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_HSL.compare(type) == 0) {
        HSLInstance *instance = new HSLInstance;
        instance->readInstance();
        return instance;
    }
    else {
        return nullptr;
    }
}
