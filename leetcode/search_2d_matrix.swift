class Solution {  
  func search(_ matrix: [[Int]], _ target: Int) -> (Int, Int)? {
    for i in 0..<matrix.count {
      let submatrix = matrix[i]
      guard submatrix.count > 0 else {
          return nil
      }
      if target >= submatrix[0] {
        for j in 0..<submatrix.count {
          if submatrix[j] == target {
            return (i, j)
          }
        }
      }
    }

    return nil
  }

  
  func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
    return search(matrix, target) != nil
  }
}

// let matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
// let target = 20
var matrix = [[Int]]()
matrix.append([Int]())
let target = 1
// var matrix = [[1],[3]]
// let target = 3
let result = Solution().search(matrix, target)
print(result ?? "Not found")
