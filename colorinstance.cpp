#include "colorinstance.h"

#include "rgbinstance.h"
#include "xyzinstance.h"
#include "labinstance.h"
#include "yuvinstance.h"
#include "ycbcrinstance.h"
#include "yiqinstance.h"
#include "hslinstance.h"

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
        XYZInstance *instance = instance = new XYZInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_LAB.compare(type) == 0) {
        LABInstance *instance = instance = new LABInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YUV.compare(type) == 0) {
        YUVInstance *instance = instance = new YUVInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YCBCR.compare(type) == 0) {
        YCbCrInstance *instance = instance = new YCbCrInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_YIQ.compare(type) == 0) {
        YIQInstance *instance = instance = new YIQInstance;
        instance->readInstance();
        return instance;
    }
    else if (COLOR_HSL.compare(type) == 0) {
        HSLInstance *instance = instance = new HSLInstance;
        instance->readInstance();
        return instance;
    }
    else {
        return nullptr;
    }
}
