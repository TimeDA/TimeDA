from random import randint as rnd

def solve(cs):
    w = 5
    h = 5
    cells = set()

    cnt = 0
    while len(cells) < w * h:
        for i in range(2, h):
            for j in range(2, w):
                need = False
                for dx in [-1, 0, 1]:
                    for dy in [-1, 0, 1]:
                        if (dx, dy) not in cells:
                            need = True
                if need:
                    #x = rnd(j - 1, j + 1)
                    #y = rnd(i - 1, i + 1)
                    print i, j
                    x, y = map(int, raw_input().split())
                    if x == -1 and y == -1:
                        exit(0);
                    cells.add((x, y))
                    cnt += 1
        #print cnt, len(cells)
    #print cnt

T = int(raw_input())
for i in range(T):
    solve(i + 1)
