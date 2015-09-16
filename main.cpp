#include <iostream>
#include <cmath>

#include "colorinstance.h"
#include "rgbinstance.h"

using namespace std;

string getColorSpace()
{
    int selection = 0;

    cout << "Available color spaces:" << endl;

    for (int i = 0; i < ColorInstance::NUM_COLOR_SPACES; i++) {
        cout << "    " << (i+1) << ". " << ColorInstance::COLOR_SPACES[i] << endl;
    }

    cout << "Enter the number of the desired color space: ";
    cin >> selection;

    if (selection <= 0 || selection > ColorInstance::NUM_COLOR_SPACES) {
        cerr << "ERROR: Didn't select a valid color space." << endl;
        exit(-1);
    }

    return ColorInstance::COLOR_SPACES[selection - 1];
}

int main()
{
    ColorInstance *cBottom;
    ColorInstance *cZero;
    ColorInstance *cTop;

    int bits;
    int instances;

//    // Obtain the desired color space
//    string space = getColorSpace();

//    // Obtain the three colors
//    cout << endl << "Choose the bottom color instance:" << endl;
//    cBottom = ColorInstance::makeInstance(space);

//    cout << endl << "Choose the zero color instance:" << endl;
//    cZero = ColorInstance::makeInstance(space);

//    cout << endl << "Choose the top color instance:" << endl;
//    cTop = ColorInstance::makeInstance(space);

//    // Obtain the bits for the color map
//    cout << endl << "Number of bits: ";
//    cin >> bits;

    bits = 3;
    cBottom = new RGBInstance(0.1, 0.1, 0.1);
    cZero = new RGBInstance(0.4, 0.5, 0.6);
    cTop = new RGBInstance(0.6, 0.6, 0.6);

    instances = int(pow(2, bits));

    cout << "Instances: " << instances << endl;
    cout << "Cbottom: " << cBottom->toString() << endl;
    cout << "Czero: " << cZero->toString() << endl;

    ColorInstance::ColorVector firstHalf = cBottom->interpolate(cZero, instances / 2);
    ColorInstance::ColorVector secondHalf = cZero->interpolate(cTop, instances / 2);

    for (int i = 0; i < firstHalf.size(); i++) {
        cout << firstHalf[i]->toString() << endl;
    }

    for (int i = 0; i < secondHalf.size(); i++) {
        cout << secondHalf[i]->toString() << endl;
    }

    return 0;
}

