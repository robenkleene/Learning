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