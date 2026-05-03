#include <iostream>
#include <fstream> // file operations
#include <random> // solo para la semilla

using namespace std;

int main() {
    int n_bits = 1000000;
    long long p = 998551, q = 997307;
    if (p % 4 != 3) {
        cout << "p no cumplen resto 3 módulo 4";
        return -1;
    }
    if (q % 4 != 3) {
        cout << "q no cumplen resto 3 módulo 4";
        return -1;
    }
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> distr(1, 1000000);
    long long s = distr(gen);
    long long m = p*q;
    long long x = s*s % m; // x0 (no se toma su bit)
    ofstream myFile("output.txt");
    if (myFile.is_open()) {
        x = (long long) ((__int128) x*x % m); // x1 (primer bit tomado)
        myFile << x % 2;
        for (int i = 1; i < n_bits; i++) {
            x = (long long) ((__int128) x*x % m);
            myFile << ", " << x % 2;
        }
    }
    return 0;
}