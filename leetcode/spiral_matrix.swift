import Foundation

class Solution {
  func generateMatrix(_ n: Int) -> [[Int]] {
    var matrix = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
    var counter = 0
    var i = 0

    // 0, 0: 1
    // 0, 1: 2
    // 0, 2: 3
    // 1, 2: 4
    // 2, 2: 5
    // 2, 1: 6
    // 2, 0: 7
    // 1, 0: 8
    // 1, 1: 9
    while true {
      
    }
    
    for i in 0..<n {
      for j in 0..<n {
        matrix[i][j] = counter
        counter += 1
        let _ = "\(i) \(j) \(matrix)"
      }
    }

    return matrix
  }
}

let result = Solution().generateMatrix(5)
print(result)
