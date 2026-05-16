# No resuelto

import sys
from math import sqrt
# Optimización de I/O para lectura rápida por líneas
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    coords = []
    for i in range(n):
        pair = [int(a) for a in input().split()]
        coords.append(pair)

    coords.sort(key=lambda x: x[0])
    acum_dist_x = 0
    for i in range(1, n):
        x1, y1 = coords[i-1]
        x2, y2 = coords[i]
        acum_dist_x += sqrt((x2-x1)**2 + (y2-y1)**2)

    coords.sort(key=lambda x: x[1])
    acum_dist_y = 0
    for i in range(1, n):
        x1, y1 = coords[i-1]
        x2, y2 = coords[i]
        acum_dist_y += sqrt((x2-x1)**2 + (y2-y1)**2)
    

    print(min(acum_dist_x, acum_dist_y))

def main():
    t = 1
    # t = int(input()) # Descomentar si hay múltiples casos de prueba
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()
