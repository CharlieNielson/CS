#include <iostream>
using namespace std;


int main() {
    cout << "a b c d e | (( c V ~d ) A b ) A ~( d V a A e )" << endl;
    cout << "----------------------------------------------" << endl;
    int end;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    for (int e = 0; e < 2; e++) {
                        if ((((c == 1) || (d == 0)) && (b == 1)) && (((d == 1) || (a == 1) && (e == 1)) == false)) {
                            end = 1;
                        } else {
                            end = 0;
                        }
                        cout << a << " "  << b << " "  << c << " "  << d << " "  << e << " |                   " << end << endl;
                    }
                }
            }
        }
    }

    return 17;
}
