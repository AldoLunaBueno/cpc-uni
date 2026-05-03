#include <iostream>
#include <fstream>
#include <cstdint>
#include <fstream>

using namespace std;

// Constantes del estado
static const int N = 624;
static const int M = 397;

// Constantes de templado
static const uint32_t U = 11, D = 0xFFFFFFFF;
static const uint32_t S = 7, B = 0x9D2C5680;
static const uint32_t T = 15, C = 0xEFC60000;
static const uint32_t L = 18;

// Constantes de la máscara
static const uint32_t F = 1812433253;
static const uint32_t A = 0x9908B0DF;
static const uint32_t UPPER_MASK = 0x80000000;
static const uint32_t LOWER_MASK = 0x7FFFFFFF;

// Inicialización -> Torsión -> Templado
class MersenneTwister {
private:
    uint32_t state[N];
    int index = N;

public:
    // Inicialización del estado interno
    MersenneTwister(uint32_t seed) {
        state[0] = seed;
        for (int i = 1; i < N; i++) {
            state[i] = F * (state[i-1] ^ (state[i-1] >> 30)) + i;
        }

        twist();
    }

    uint32_t getNext() {
        return temper();
    }


private:
    // Torsión
    void twist() {
        for (int i = 0; i < N; i++) {
            uint32_t upper = state[i] & UPPER_MASK;
            uint32_t lower = state[(i+1) % N] & LOWER_MASK;
            uint32_t y = upper | lower;
            if (y % 2 == 0) {
                state[i] = state[(i + M) % N] ^ (y >> 1);
            } else {
                state[i] = state[(i + M) % N] ^ (y >> 1);
                state[i] ^= A;
            }
        }
        index = 0;        
    }

    // Templado
    uint32_t temper() {
        if (index >= N) {
            twist();
        }

        uint32_t y = state[index];
        index += 1;

        y = y ^ ((y >> U) & D);
        y = y ^ ((y << S) & B);
        y = y ^ ((y << T) & C);
        y = y ^ (y >> L);

        return y;
    }
};

int main() {
    int n_bits = 1000000;
    uint32_t seed = 1998;
    ofstream myFile("output.txt");
    MersenneTwister mt = MersenneTwister(seed);
    if (myFile.is_open()) {
        uint32_t rnd_numb = mt.getNext();
        int b = rnd_numb & 1;
        rnd_numb >>= 1;
        myFile << b;
        for (int j = 1; j < 32; j++) {
                int b = rnd_numb & 1;
                rnd_numb >>= 1;
                myFile << ", " << b;
        }
        for (int i = 1; i < n_bits / 32; i++) {            
            rnd_numb = mt.getNext();
            for (int j = 0; j < 32; j++) {
                int b = rnd_numb & 1 ;
                rnd_numb >>= 1;
                myFile << ", " << b;
            }
        }
    }

    return 0;
}