#include <iostream>
using namespace std;

void move(int &take, int &place, int size, int &peg1, int &peg2, int &peg3) {//Moves the pieces.
    int piece = 0;
    string end;

    int i = 0;
    for (i = 0; i < size; i++) {
        if (take[i] != 0) {
            piece = take[i];
        }
    }
    take[i] = 0;
    
    i = 0;
    for (i; i < size; i++) {
        if (place[i] == 0) {
            place [i] = piece;
            break;
        }
    }

    for (i = 0; i < size; i++) {
        end += peg1[i] + " " + peg2[i] + " " + peg3[i] + "\n";
    }

    cout << end;
}

void solve(int start, int end, int n) {//Recursive function that solves a tower of hanoi of size n from start peg to end peg.

}

int main() {
    int size;
    cout << "How large is the tower: ";
    cin >> size;
    cout << endl;
    int peg1[size];
    int peg2[size];
    int peg3[size];
    for (int i = 0; i < size; i++) {
        peg1[i] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        peg2[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        peg3[i] = 0;
    }


    return 17;
}
