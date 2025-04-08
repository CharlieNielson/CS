//#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class matrix {
        public:
    matrix(int r = 3, int c = 2, bool randomized = true) {
        row = r;
        colum = c;
        if (randomized) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < colum; j++) {
                    data[i][j] = (rand() % 11) - 5;
                }
            }
        }
    }
    void display() {
        cout << row << "X" << colum << " Matrix: " << endl;
        for (int i = 0; i < row; i++) {
            cout << "| " << data[i][0];
            for (int j = 1; j < colum; j++) {
                cout << ", " << data[i][j];
            }
            cout << " |" << endl;
        }
    }
    int getValue(int r, int c) {
        return data[r][c];
    }
    void setValue(int r, int c, int input) {
        data[r][c] = input;
    }
    int getVar(int bit) {//if bit is 1, returns row, otherwise returns colum
        if (bit == 1) {
            return row;
        }
        return colum;
    }
        private:
    int row, colum;
    int data[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

int evalSize(int c, int side) {//side is 1 for returning row size, anything else for returning column size
    if (side == 1) {
        if (c <= 2) {
            return 2;
        } else {
            return 3;
        }
    } else {
        if (c % 2 == 1) {
            return 2;
        } else {
            return 3;
        }
    }
}

int main() {
    srand(time(0));

    matrix m1(2, 2);
    matrix m2(2, 3);//Program: I am very fragile and altering
    matrix m3(3, 2);//these numbers will break me
    matrix m4(3, 3);
    cout << "1: ";
    m1.display();
    cout << "2: ";
    m2.display();
    cout << "3: ";
    m3.display();
    cout << "4: ";
    m4.display();

    int calc = -1;
    int choice1 = -1;
    int choice2 = -1;
    cout << "Which calculation will be done?\n1: Addition\n2: Multiplication\nSelect: ";
    while (calc > 2 || calc < 1) {
        cin >> calc;
        if (calc > 2 || calc < 1) {
            cout << "Input invalid: Please select 1 or 2: ";
        }
    }
    cout << "Which matrix will be first in the calculation(input number): ";
    while (choice1 > 4 || choice1 < 1) {
        cin >> choice1;
        if (choice1 > 4 || choice1 < 1) {
            cout << "Input invalid: Please select a number from 1 to 4: ";
        }
    }
    cout << "Which matrix will be second in the calculation(input number): ";
    while (choice2 > 4 || choice2 < 1) {
        cin >> choice2;
        if (choice2 > 4 || choice2 < 1) {
            cout << "Input invalid: Please select a number from 1 to 4: ";
        }
    }
    int x = 0;//x is a placeholder to put evaluated values into so I don't lose my mind with if shortcuts
    if (calc == 1) {
        matrix m5(evalSize(choice1, 1), evalSize(choice1, 2), false);
        for (int i = 0; i < evalSize(choice1, 1); i++) {//each row
            for (int j = 0; j < evalSize(choice2, 2); j++) {//each column
                int idk = choice1;
                for (int k = 0; k < 2; k++) {//puts the right values into x. loops twice
                    if (idk == 1) {
                        x += m1.getValue(i, j);
                    } else if (idk == 2) {
                        x += m2.getValue(i, j);
                    } else if (idk == 3) {
                        x += m3.getValue(i, j);
                    } else {
                        x += m4.getValue(i, j);
                    }
                    idk = choice2;
                }
                m5.setValue(i, j, x);
                x = 0;
            }
        }
        cout << "Matrix " << choice1 << " plus Matrix " << choice2 << " is: " << endl;
        m5.display();
    } else {
        matrix m5(evalSize(choice1, 1), evalSize(choice2, 2), false);
        int y = 1;//second placeholder for what we will put into x
        int num = evalSize(choice1, 2);//so i can just use a variable instead of that function. never changes.
        for (int i = 0; i < evalSize(choice1, 1); i++) {//each row
            for (int j = 0; j < evalSize(choice2, 2); j++) {//each column
                for (int k = 0; k < num; k++) {//puts all the numbers into x
                        if (choice1 == 1) {
                            y *= m1.getValue(i, k);
                        } else if (choice1 == 2) {
                            y *= m2.getValue(i, k);
                        } else if (choice1 == 3) {
                            y *= m3.getValue(i, k);
                        } else if (choice1 == 4) {
                            y *= m4.getValue(i, k);
                        }
                        if (choice2 == 1) {
                            y *= m1.getValue(k, j);
                        } else if (choice2 == 2) {
                            y *= m2.getValue(k, j);
                        } else if (choice2 == 3) {
                            y *= m3.getValue(k, j);
                        } else if (choice2 == 4) {
                            y *= m4.getValue(k, j);
                        }
                        x += y;
                        y = 1;
                }
                m5.setValue(i, j, x);
                x = 0;
            }
        }
        cout << "Matrix " << choice1 << " multiplied by Matrix " << choice2 << " is: " << endl;
        m5.display();
    }
    /*the exixtence of this comment lets me comment out all the code more easily.*/
    
    return 0;
}
