#!/bin/bash

# Detectar de forma automática el lenguaje del problema actual
if [ -f "main.cpp" ]; then
    MODE="C++"
    echo "🔨 Compilando C++..."
    g++ -O2 -Wall -Wextra -std=c++17 main.cpp -o main.out
    if [ $? -ne 0 ]; then
        echo "❌ Error de compilación."
        exit 1
    fi
    RUN_CMD="./main.out"
elif [ -f "main.py" ]; then
    MODE="Python"
    RUN_CMD="python3 main.py"
else
    echo "❌ No se encontró main.cpp ni main.py en este directorio."
    exit 1
fi

echo "🚀 Ejecutando pruebas locales ($MODE)..."
for in_file in in*.txt; do
    if [ ! -e "$in_file" ]; then
        echo "⚠️ No se encontraron archivos de entrada (in*.txt)."
        break
    fi

    num=$(echo "$in_file" | sed 's/[^0-9]//g')
    out_file="out${num}.txt"
    
    if [ ! -f "$out_file" ]; then
        echo "⚠️ Se encontró $in_file pero falta $out_file. Saltando..."
        continue
    fi

    # Ejecutar la solución inyectando el caso de prueba
    $RUN_CMD < "$in_file" > "temp_out.txt"
    
    if diff -w -q "temp_out.txt" "$out_file" > /dev/null; then
        echo "✅ Test $num: AC (Accepted)"
    else
        echo "❌ Test $num: WA (Wrong Answer)"
        echo "   --- Esperado ---"
        cat "$out_file"
        echo "   --- Obtenido ---"
        cat "temp_out.txt"
        echo "-------------------"
    fi
done

# Limpieza de temporales
rm -f temp_out.txt main.out