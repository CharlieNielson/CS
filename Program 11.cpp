#include <iostream>
#include <ctime>
using namespace std;

class matrix {
        public:
    matrix(int x) {
        specifcMatrix = x;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (rand() % 3 == 0) {
                    data[i][j] = 1;
                }
            }
        }
    }
    void display() {
        cout << "Matrix " << specifcMatrix << endl;
        for (int i = 0; i < 4; i++) {
            cout << "| " << data[i][0];
            for (int j = 1; j < 4; j++) {
                cout << ", " << data[i][j];
            }
            cout << " |" << endl;
        }
    }
    int getValue(int row, int column) {
        return data[row][column];
    }
    int getName() {
        return specifcMatrix;
    }

        private:
    int data[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int specifcMatrix;
};

void addEnd(string add, string& end) {
    if (end != "") {
        end += ", ";
    }
    end += add;
    //cout << end << endl;
}

void evaluate(matrix m) {
    string end = "";

    int reflexiveCounter = 0;
    int irreflexiveCounter = 0;
    for (int i = 0; i < 4; i++) {
        if (m.getValue(i, i) == 1) {
            reflexiveCounter++;
        } else if (m.getValue(i, i) == 0) {
            irreflexiveCounter++;
        } else {break;}
    }
    bool isIrreflexive = false;
    if (reflexiveCounter == 4) {
        addEnd("Reflexive", end);
    } else if (irreflexiveCounter == 4) {
        addEnd("Irreflexive", end);
        isIrreflexive = true;
    }

    bool isSymetric = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {continue;}
            if (!(m.getValue(i, j) == m.getValue(j, i))) {
                isSymetric = false;
            }
        }
    }
    if (isSymetric) {
        addEnd("Symetric", end);
    }

    bool isAntisymetric = true;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {continue;}
            count = 0;
            if (m.getValue(i, j) == 1) {
                count++;
            }
            if (m.getValue(j, i) == 1) {
                count++;
            }
            if (count >= 2) {
                isAntisymetric = false;
            }
        }
    }
    if (isAntisymetric) {
        addEnd("Antisymetric", end);
        //cout << "debug" << endl;
    }

    if (isIrreflexive && isAntisymetric) {
        addEnd("Asymetrtic", end);
    }

    if (end == "") {
        end = "None";
    }
    cout << "Matrix " << m.getName() << " is " << end << "." << endl;
}

int main() {
    srand(time(0));
    matrix m1(1);
    matrix m2(2);
    matrix m3(3);
    matrix m4(4);

    m1.display();
    m2.display();
    m3.display();
    m4.display();

    evaluate(m1);
    evaluate(m2);
    evaluate(m3);
    evaluate(m4);

    return 0;
}
