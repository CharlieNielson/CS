#include <iostream>
using namespace std;

string iterate(int n) {
    string end = "";
    for (int i = 0; i < n; i++) {
        end = end + "a";
    }
    for (int i = 0; i < n; i++) {
        end = end + "b";
    }
    return end;
    // I originaly meant for this function to call itself, but I 
    // realized that without if statements, it would loop forever.
}


int main() {

    for (int i = 5; i > 0; i--) {
        cout << iterate(i);
    }
    cout << endl;

    return 17;
}
