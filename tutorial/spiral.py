#!/usr/bin/env python3

def spiral(matrix):
    if not matrix: return []
    ROWS, COLS = len(matrix), len(matrix[0])
    visited = [[False] * COLS for _ in matrix]
    result = []
    DR = [0, 1, 0, -1]
    DC = [1, 0, -1, 0]
    r = c = dir = 0
    for _ in range(ROWS * COLS):
        result.append(matrix[r][c])
        visited[r][c] = True
        cr, cc = r + DR[dir], c + DC[dir]
        if 0 <= cr < ROWS and 0 <= cc < COLS and not visited[cr][cc]:
            r, c = cr, cc
        else:
            dir = (dir + 1) % 4
            r, c = r + DR[dir], c + DC[dir]
    return result

input = [[1,2,3],[4,5,6],[7,8,9]]
result = spiral(input)
print("result =", result)
