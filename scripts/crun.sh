#!/bin/bash

if [ -z "$1" ]; then
    echo "Uso: crun <archivo.cpp o archivo.py>"
    exit 1
fi

FILE="$1"
EXT="${FILE##*.}" # Extrae la extensión del archivo
BASE="${FILE%.*}" # Extrae el nombre sin extensión

if [ "$EXT" = "py" ]; then
    echo "🚀 Ejecutando script de Python..."
    echo "-------------------"
    python3 "$FILE"
    echo -e "\n-------------------"
elif [ "$EXT" = "cpp" ]; then
    echo "🔨 Compilando $FILE..."
    g++ -O2 -Wall -std=c++17 "$FILE" -o "${BASE}.out"
    
    if [ $? -eq 0 ]; then
        echo "🚀 Ejecutando binario C++..."
        echo "-------------------"
        ./"${BASE}.out"
        echo -e "\n-------------------"
        rm "${BASE}.out"
    else
        echo "❌ Error de compilación C++."
    fi
else
    echo "❌ Extensión .$EXT no soportada por crun."
    exit 1
fi