#!/usr/bin/env python3

def spiral(matrix):
    if not matrix: return []
    ROWS, COLS = len(matrix), len(matrix[0])
    visited = [[False] * COLS for _ in matrix]
    result = []
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]
    r = c = di = 0
    for _ in range(ROWS * COLS):
        result.append(matrix[r][c])
        visited[r][c] = True
        cr, cc = r + dr[di], c + dc[di]
        if 0 <= cr < ROWS and 0 <= cc < COLS and not visited[cr][cc]:
            r, c = cr, cc
        else:
            di = (di + 1) % 4
            r, c = r + dr[di], c + dc[di]
    return result

input = [[1,2,3],[4,5,6],[7,8,9]]
result = spiral(input)
print("result =", result)
