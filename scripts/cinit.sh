#!/bin/bash

# Verificar que se pasó un nombre para el problema
if [ -z "$1" ]; then
    echo "Uso: cpc-init <nombre_del_problema>"
    exit 1
fi

DIR_NAME="$1"

# Crear la carpeta y entrar en ella
mkdir -p "$DIR_NAME"
cd "$DIR_NAME" || exit

# Crear notas.md
echo "# Notas: $DIR_NAME" > notas.md

# Crear archivos in/out vacíos
for i in {1..3}; do
    touch "in${i}.txt"
    touch "out${i}.txt"
done

# Copiar tu plantilla base (o crear una por defecto si no existe)
# Ajusta la ruta a donde guardes tu plantilla real
TEMPLATE_FILE="../../plantillas/base.cpp"

if [ -f "$TEMPLATE_FILE" ]; then
    cp "$TEMPLATE_FILE" main.cpp
else
    # Plantilla de rescate en caso de que no exista el archivo
    cat << 'EOF' > main.cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Tu lógica aquí
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
EOF
fi

echo "✅ Estructura creada en ./$DIR_NAME"