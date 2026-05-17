#include <bits/stdc++.h>
using namespace std;

void solve() {
    string numb_str;
    cin >> numb_str;
    vector<int> digits;

    for (char c : numb_str) {
        digits.push_back(c - '0');
    }
    
    for (size_t i = 0; i < digits.size()-1; i++) {
        for (size_t j = i+1; j < digits.size(); j++) {
            if (digits[i] > digits[j]) {
                swap(digits[i], digits[j]);
            }
        }
    }

    if (digits[0] == 0) {
        for (size_t i = 1; i < digits.size(); i++) {
            if (digits[i] == 0) continue;
            swap(digits[0], digits[i]);
            break;
        }
    }

    for (int d : digits) cout << d;
    cout << "\n";
}

void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; // Descomentar si hay múltiples casos de prueba
    while (t--) {
        solve();
    }
    return 0;
}
