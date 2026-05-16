# Resuelto!

import sys

# Optimización de I/O para lectura rápida por líneas
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    national_max = 0
    limit = 0
    limit_max = 0
    curr_vel = 0
    for i in range(n):
        sign = input()
        if sign == "/":
            if limit_max % 10 != 0:
                national_max = max((limit_max // 10) * 10 + 10, national_max)
            else:
                national_max = limit_max + 10
            curr_vel = national_max
        else:
            limit = int(sign)
            limit_max = max(limit, limit_max)
            curr_vel = limit
        print(curr_vel)
        

    pass

def main():
    t = 1
    # t = int(input()) # Descomentar si hay múltiples casos de prueba
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()
