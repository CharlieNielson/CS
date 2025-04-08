#include <iostream>
using namespace std;

int test(int thing[]) {
    int end = 0;
    while ((thing[end] > 0) && end < 18) {
        cout << thing[end] << endl;
        end++;
    }
    cout << thing[end] << endl;
    return end;
}

void undup(int list[], int len) {
    int end[10] = {};
    int length = 0;
    bool hasNoRep = true;
    for (int i = 0; i < len; i++) {
        hasNoRep = true;
        for (int j = 0; j < length; j++) {
            if (list[i] == end[j] || list[i] == -50) {
                hasNoRep = false;
            }
        }
        if (hasNoRep && list[i] != -50) {
            end[length] = list[i];
            length++;
        }
    }
    //cout << length << endl;

    cout << "{";
    for (int i = 0; i < length; i++) {
        cout << end[i];
        if (i < length - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void unite(int a[], int b[]) {
    int end[10] = {};
    for (int i = 0; i < 5; i++) {
        end[i] = a[i];
    }
    for (int i = 0; i < 5; i++) {
        end[i + 5] = b[i];
    }
    undup(end, 10);
}

void intersect(int a[], int b[]) {
    int end[25] = {};
    int len = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[j] == b[i]) {
                end[len] = a[j];
                len++;
            }
        }
    }

    //undup(end);

    cout << "{";
    for (int i = 0; i < len; i++) {
        cout << end[i];
        if (i < len - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void subtract(int a[], int b[]) {//It should be noted that this function does a - b.
    int end[6] = {a[0], a[1], a[2], a[3], a[4], -50};
    int length = 7;


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i] == b[j]) {
                a[i] = -50;
                length--;
                //cout << "debug\n";
            }
        }
    }
    
    undup(a, length);
}

int main() {
    int A[5] = {1, 3, 5, 6, 8};
    int B[5] = {2, 3, 4, 7, 9};

    int t = A[3];
    cout << t << endl;

    unite(A, B);
    
    intersect(A, B);

    subtract(A, B);

    return 17;
}
