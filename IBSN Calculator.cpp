#include <iostream>
using namespace std;

int main() {//Calculates c for an ISBN number. I don't think I will ever use this again, but I lazy, so deal with it.
    int calc = 0;
    int end = 0;
    cout << "Put in the ISBN: ";
    cin >> calc;
    for (int i = 1; i <= 9; i++) {
        end += (calc % 10) * (10 - i);
        calc -= (calc % 10);
        calc = calc / 10;
    }
    end = end % 11;
    cout << endl << "C: " << end << endl;

    return 17;
}
