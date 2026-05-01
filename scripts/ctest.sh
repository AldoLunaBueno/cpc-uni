#!/bin/bash

if [ ! -f "main.cpp" ]; then
    echo "❌ No se encontró main.cpp en el directorio actual."
    exit 1
fi

echo "🔨 Compilando..."
# Flags recomendadas para programación competitiva
g++ -O2 -Wall -Wextra -std=c++17 main.cpp -o main.out

if [ $? -ne 0 ]; then
    echo "❌ Error de compilación."
    exit 1
fi

echo "🚀 Ejecutando pruebas..."
# Iterar sobre cualquier archivo que empiece con 'in' y termine en '.txt'
for in_file in in*.txt; do
    # Validar si no existen archivos (evita que el for falle)
    if [ ! -e "$in_file" ]; then
        echo "⚠️ No se encontraron archivos de entrada (in*.txt)."
        break
    fi

    # Extraer el número del archivo (ej. saca el '2' de 'in2.txt')
    num=$(echo "$in_file" | sed 's/[^0-9]//g')
    out_file="out${num}.txt"
    
    if [ ! -f "$out_file" ]; then
        echo "⚠️ Se encontró $in_file pero falta $out_file. Saltando..."
        continue
    fi

    # Ejecutar guardando la salida en un archivo temporal
    ./main.out < "$in_file" > "temp_out.txt"
    
    # Ignorar espacios en blanco al final de la línea/archivo con -w
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

# Limpieza
rm -f temp_out.txt main.out