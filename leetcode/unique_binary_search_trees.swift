#!/usr/bin/swift

import Foundation

class Solution {
    func numTrees(_ n: Int) -> Int {
        var G = Array(repeating: 0, count: n + 1)
        (G[0], G[1]) = (1, 1)
        for i in 2..<n + 1 {
            for j in 1..<i + 1 {
                G[i] += G[j - 1] * G[i - j]
            }
        }
        return G[n]
    }
}

let result = Solution().numTrees(3)
print("result = \(result)")
