import sys
import os

with open('in100.txt', 'w') as f:
    print("1000001", file=f)
    print("A"*100000 + "B" + "A"*100000, file=f)

with open('out100.txt', 'w') as f:
    print(10000000000, file=f)