# Resuelto??

import sys

# Optimización de I/O para lectura rápida por líneas
input = lambda: sys.stdin.readline().rstrip()

def solve():
    p, h, t = [int(a) for a in input().split()]
    printed = t // p
    if p == h:
        hangued = (t - p) // h
        hangued = min(printed, hangued)
    elif p > h:
        hangued = printed
        if t // p * p + h > t:
            hangued -= 1
    else:
        hangued = (t - p) // h
    print(max(hangued, 0))

def main():
    t = 1
    # t = int(input()) # Descomentar si hay múltiples casos de prueba
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()
