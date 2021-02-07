#!/usr/bin/swift

func spiral(_ matrix: [[Int]]) -> [Int] {
    let (rows, cols) = (matrix.count, matrix[0].count)
    let falseRow = Array(repeating: false, count: cols)
    var visited = Array(repeating: falseRow, count: rows)
    let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    var (r, c, dir) = (0, 0, 0)
    var result = [Int]()
    let rangeR = 0..<rows
    let rangeC = 0..<cols
    for _ in 0..<(rows * cols) {
        result.append(matrix[r][c])
        visited[r][c] = true
        let (offsR, offsC) = directions[dir]
        let (nextR, nextC) = (r + offsR, c + offsC)
        if rangeR ~= nextR && rangeC ~= nextC, !visited[nextR][nextC] {
            (r, c) = (nextR, nextC)
        } else {
            dir = (dir + 1) % 4
            let (offsR, offsC) = directions[dir]
            let (nextR, nextC) = (r + offsR, c + offsC)
            (r, c) = (nextR, nextC)
        }
    }
    return result
}


let input = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
let result = spiral(input)
print("result = ", result)
