#!/usr/bin/swift

func spiral(_ matrix: [[Int]]) -> [Int] {
    let (rows, cols) = (matrix.count, matrix[0].count)
    let falseRow = Array(repeating: false, count: cols)
    var visited = [Array(repeating: [falseRow], count: rows)]
    return [Int]()
}
