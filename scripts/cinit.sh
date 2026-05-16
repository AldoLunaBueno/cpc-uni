#!/bin/bash

if [ -z "$1" ]; then
    echo "Uso: cinit <nombre_del_problema> [cpp|py]"
    exit 1
fi

DIR_NAME="$1"
LANG="${2:-cpp}" # Si no se envía el segundo argumento, por defecto es cpp

mkdir -p "$DIR_NAME"
cd "$DIR_NAME" || exit

echo "# Notas: $DIR_NAME" > notas.md

for i in {1..3}; do
    touch "in${i}.txt"
    touch "out${i}.txt"
done

if [ "$LANG" = "py" ]; then
    # Plantilla base para Python con optimización de I/O
    cat << 'EOF' > main.py
import sys

# Optimización de I/O para lectura rápida por líneas
input = lambda: sys.stdin.readline().rstrip()

def solve():
    # Tu lógica aquí
    pass

def main():
    t = 1
    # t = int(input()) # Descomentar si hay múltiples casos de prueba
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()
EOF
    echo "✅ Estructura Python creada en ./$DIR_NAME (main.py)"
else
    # Plantilla base para C++
    TEMPLATE_FILE="../../plantillas/base.cpp"
    if [ -f "$TEMPLATE_FILE" ]; then
        cp "$TEMPLATE_FILE" main.cpp
    else
        cat << 'EOF' > main.cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Tu lógica aquí
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
EOF
    fi
    echo "✅ Estructura C++ creada en ./$DIR_NAME (main.cpp)"
fi