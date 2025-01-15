#include <iostream>
using namespace std;

int main() {//Calculates c for an ISBN number. I don't think I will ever use this again, but I lazy.
    int calc = 0;
    int end = 0;
    cout << "Put in the ISBN: ";
    cin >> calc;
    int len = 9;
    for (int i = 1; i <= len; i++) {
        end += (calc % 10) * (len + 1 - i);
        calc -= (calc % 10);
        calc = calc / 10;
    }
    end = end % 11;
    cout << "C: " << end << endl;

    return 17;
}
