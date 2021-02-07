#!/usr/bin/env python3

def spiral(matrix):
    ROWS, COLS = len(matrix), len(matrix[0])
    visited = [[False] * COLS for _ in matrix]
    DR = [0, 1, 0, -1]
    DC = [1, 0, -1, 0]
    r = c = dir = 0
    result = []
    for _ in range(ROWS * COLS):
        result.append(matrix[r][c])
        visited[r][c] = True
        # Create a potential move
        cr, cc = r + DR[dir], c + DC[dir] # Move in dir
        # Check if an edge, or visited cell, has been hit
        if 0 <= cr < ROWS and 0 <= cc < COLS and not visited[cr][cc]:
            # Continue moving in that dir
            r, c = cr, cc
        else:
            # Or turn
            dir = (dir + 1) % 4
            r, c = r + DR[dir], c + DC[dir]
    return result

input = [[1,2,3],[4,5,6],[7,8,9]]
result = spiral(input)
print("result =", result)
