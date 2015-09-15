#include <iostream>

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

    string space = getColorSpace();


    cout << endl << "Choose the bottom color instance:" << endl;
    cBottom = ColorInstance::makeInstance(space);

    cout << endl << "Choose the zero color instance:" << endl;
    cZero = ColorInstance::makeInstance(space);

    cout << endl << "Choose the top color instance:" << endl;
    cTop = ColorInstance::makeInstance(space);

    cout << endl << "Number of bits: ";
    cin >> bits;

    return 0;
}

