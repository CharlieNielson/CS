#include <iostream>
using namespace std;

void show() {// Outputs the board.

}

void move(int start, int end, int blocks[], int size) {// Moves the pieces.
    bool notEnd = true;
    for (int i = 0; i < size && notEnd; i++) {
        if (blocks[i] == start) {
            blocks[i] = end;
            notEnd = false;
        }
    }
}

void solve(int start, int other, int end, int size, int blocks[]) {// Recursive function that solves a tower of hanoi of size size.
    if (size == 1) {
        move(start, end, size);
    }
}


int main() {
    int size;// The number of blocks.
    cout << "How large is the tower: ";
    cin >> size;
    int blocks[size];// Either one, two, or three, each element stores the location of a block.
    for (int i = 0; i < size; i++) {// Sets each blocks position to one. They will only ever be 1, 2, or 3;
        blocks[i] = 1;
    }
    solve(1, 2, 3, size, blocks[]);

    return 0;
}
