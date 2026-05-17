#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > a) swap(a, b);
    if (c > a) swap(a, c);
    if (c > b) swap(b, c);
    cout << a << b << c << "\n";
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
