#include <iostream>
using namespace std;

int main() {//Calculates c for an ISBN number. I only had to calculate about four of these, but read the title of the program if you wonder why.
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
