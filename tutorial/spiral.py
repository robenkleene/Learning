#!/usr/bin/env python3

def spiral(matrix):
    ROWS, COLS = len(matrix), len(matrix[0])
    visited = [[False] * COLS for _ in matrix]
    DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    r = c = dir = 0
    result = []
    for _ in range(ROWS * COLS):
        result.append(matrix[r][c])
        visited[r][c] = True
        offs_r, offs_c = DIRS[dir]
        next_r, next_c = r + offs_r, c + offs_c
        if 0 <= next_r < ROWS and 0 <= next_c < COLS and not visited[next_r][next_c]:
            r, c = next_r, next_c
        else:
            dir = (dir + 1) % 4
            offs_r, offs_c = DIRS[dir]
            next_r, next_c = r + offs_r, c + offs_c
            r, c = next_r, next_c
    return result

def main():
    """
    main
    """
    input = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    result = spiral(input)
    print("result =", result)

main()
