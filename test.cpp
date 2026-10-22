#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    cout << "=== Test C++ ===" << endl;

    // 1. Citire de la tastatura
    string nume;
    cout << "Cum te cheama? ";
    getline(cin, nume);
    cout << "Salut, " << nume << "!" << endl;

    // 2. Bucla si vector
    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i * i);
    }
    cout << "Patratele primelor 5 numere: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // 3. Functie
    cout << "5! = " << factorial(5) << endl;

    cout << "Totul functioneaza corect!" << endl;
    return 0;
}