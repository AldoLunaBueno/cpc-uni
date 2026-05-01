#!/bin/bash

# Compilar y ejecutar rápidamente un solo archivo cpp

if [ -z "$1" ]; then
    echo "Uso: crun <archivo.cpp>"
    return 1
fi

# echo "🔨 Compilando $1..."
g++ -O2 -Wall -std=c++17 "$1" -o "${base_name}.out"

if [ $? -eq 0 ]; then
    # echo "🚀 Ejecutando:"
    # echo "-------------------"
    ./"${base_name}.out"
    # echo -e "\n-------------------"
    # Limpiar el ejecutable al terminar
    rm "${base_name}.out"
else
    echo "❌ Error de compilación."
fi