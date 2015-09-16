#include <iostream>
#include <cmath>

#include "colorinstance.h"

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

    // Obtain the desired color space
    string space = getColorSpace();
    cout << "Chose " << space << " color space" << endl;

    // Obtain the three colors
    cout << endl << "Choose the bottom color instance:" << endl;
    cBottom = ColorInstance::makeInstance(space);

    cout << endl << "Choose the zero color instance:" << endl;
    cZero = ColorInstance::makeInstance(space);

    cout << endl << "Choose the top color instance:" << endl;
    cTop = ColorInstance::makeInstance(space);

    // Obtain the bits for the color map
    cout << endl << "Number of bits: ";
    cin >> bits;

    instances = int(pow(2, bits));
    cout << endl << "Color map will contain " << instances << " color instances" << endl;

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

