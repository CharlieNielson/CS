#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void convert(int ten, int base) {
    int display;
    int holder;
    //string end = "";

    for (int i = log2(ten) / log2(base); i >= 0; i--) {
        //cout << endl << "debug two " << i;
        //cout << endl << "debug " << (base ^ i) << endl;
        display = 1;
        for (int j = 0; j < i; j++) {
            display *= base;
        }
        holder = display;
        //cout << endl << "debug ten " << ten << endl << "debug display " << display << endl;
        display = (ten / display);
        if (display < 10) {
            cout << display;
        } else if (display == 10) {
            cout << "A";
        } else if (display == 11) {
            cout << "B";
        } else if (display == 12) {
            cout << "C";
        } else if (display == 13) {
            cout << "D";
        } else if (display == 14) {
            cout << "E";
        } else if (display == 15) {
            cout << "F";
        }
        ten -= holder * display;
    }

    //return end;
}


int main() {
    int base10;
    cout << "Input a base ten number to be converted to bases 2, 8, and 16: ";
    cin >> base10;
    //cout << endl;


    cout << "Base 2: ";
    convert(base10, 2);
    cout << endl << "Base 8: ";
    convert(base10, 8);
    cout << endl << "Base 16: ";
    convert(base10, 16);
    cout << endl;


    /*base10 = log10(99);
    cout << base10 << endl;// debug/test
    cout << log10(99);*/




    return 17;
}
