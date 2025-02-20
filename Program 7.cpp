#include <iostream>
using namespace std;

int factorial(int x) {
    int end = 1;
    for (int i = x; i > 0; i--) {
        //cout << i << endl;
        end *= i;

    }
    return end;
}

int combination(int N, int R) {
    return (factorial(N) / (factorial(N - R) * factorial(R)));
}

int main() {
    int n, r;
    cout << "Give a value n: ";
    cin >> n;
    cout <<  "Give a value r: ";
    cin >> r;
    cout << "With repeats(dice): " << endl;
    int end = n;
    for (int i = 1; i < r; i++) {
        end *= n;
    }
    cout << "  P(n, r): " << end << endl;
    cout << "  C(n, r): " << combination(n + r - 1, r) << endl;
    
    cout << "Without repeats(decks): " << endl;
    cout << "  P(n, r): " << factorial(n) / factorial(n - r) << endl;
    cout << "  C(n, r): " << combination(n, r) << endl;


    return 17;
}
