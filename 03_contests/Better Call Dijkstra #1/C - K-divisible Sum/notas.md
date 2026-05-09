# Notas: K-divisible Sum


Construimos los elementos del arreglo unidad por unidad de izquierda a derecha, siendo cada elemento la suma de los 1s en su columna. Esto se puede hacer así porque no estamos restringidos a un orden en particular y porque avanzar llenando niveles sin dejar nada garantiza encontrar un arreglo donde el máximo sea el menor posible como pide el problema.

Para justificar lo último, digamos que la solución correcta para un problema cualquiera tiene como máximo un $a_i$ que se diferencia en al menos dos unidades con otro elemento $a_j$: $a_i - a_j \ge 2$. Entonces, podemos construir otra solución donde en lugar de $a_i$ tenemos $a_i-1$ y en lugar de $a_j$ tenemos $a_j+1$. Si ese máximo era único, ahora el máximo del arreglo disminuyó en uno. Si había otros elementos que tenían el mismo valor que $a_i$, podemos seguir aplicando la misma operación hasta que ya no exista la relación $a_j$: $a_i - a_j \ge 2$ para ningún par de elementos del arreglo. Como la suma se conserva, esta es también solución del problema, y el máximo podría mantenerse o reducirse. Pero ya no se puede reducir más si todos los elementos mantienen una distancia de una unidad como máximo.

Así se vería:

```txt
        --n=4--  k=3
        1 1     
        1 1 1 1  --> 6|3
        -------
   a = [2 2 1 1] --> 2 máximo
```