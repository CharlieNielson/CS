#include <iostream>
using namespace std;


int main() {
    cout << "p q | ~p A q" << endl;

    int end;
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            if ((p == 0) && (q == 1)) {
                end = 1;
            } else {
                end = 0;
            }
            cout << p << " " << q << " |    " << end << endl;
        }
    }

    return 17;
}
