#include <iostream>
using namespace std;

int thing(string s) {
    string thing1 = " ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    string thing2 = " abcdefghijklmnopqrstuvwxyz ";
    int end = 0;
    int j;
    for (j = 0; s[j]; j++);//I totaly stole this line off the internet.
    //It tells me how long s is.

    for (int i = 0; i < j; i++) {
        for (int k = 1; k < 28; k++) {
            if (s[i] == thing1[k] || s[i] == thing2[k]) {
                end = end + k;
            }
        }
    }


    return end % 31;
}

int main() {
    cout << "Hash 31 program start." << endl;
    bool stillGoing = true;
    int cont;
    string holder;
    while(true) {
        cout << "\nPlease enter a sentence using only letters and spaces: \n";
        getline(cin, holder);
        //cin >> holder;
        cout << thing(holder) << endl << endl;
    }

    return 17;
}
