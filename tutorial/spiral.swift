#!/usr/bin/swift

func spiral(_ matrix: [[Int]]) -> [Int] {
    let (rows, cols) = (matrix.count, matrix[0].count)
    let falseRow = Array(repeating: false, count: cols)
    var visited = Array(repeating: falseRow, count: rows)
    let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    var (r, c, dir) = (0, 0, 0)
    var result = [Int]()
    for _ in 0..<(rows * cols) {
        result.append(matrix[r][c])
        visited[r][c] = true
        let (offsR, offsC) = directions[dir]
    }
    return [Int]()
}
