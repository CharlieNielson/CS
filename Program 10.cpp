#include <iostream>
#include <vector>
using namespace std;

bool exists(int dr, int max, int n, vector<vector<int>> pairs) {//checks whether a number exists in the vector up to a ceirtain point.
    for (int i = 0; i < max; i++) {
        if (pairs[i][dr] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "How many pairs would you like to input: ";
    int num;
    cin >> num;

    vector<vector<int>> pairs;
    int data1;
    int data2;
    for (int i = 0; i < num; i++) {
        cout << "What is the first nunmber in this pair(input): ";
        cin >> data1;
        cout << "The second(output): ";
        cin >> data2;
        pairs.push_back({data1, data2});
    }

    cout << "Domain: {" << pairs[0][0];
    for (int i = 1; i < num; i++) {
        if (!exists(0, i - 1, pairs[i][0], pairs)) {
            cout << ", " << pairs[i][0];
        }
    }
    cout << "}" << endl;

    cout << "Range: {" << pairs[0][1];
    for (int i = 1; i < num; i++) {
        if (!exists(1, i - 1, pairs[i][1], pairs)) {
            cout << ", " << pairs[i][1];
        }
    }
    cout << "}" << endl;


    return 0;
}
