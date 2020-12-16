#!/usr/bin/swift

import Foundation

class Solution {
    func numTrees(_ n: Int) -> Int {
        // The array `G` uses dynamic programming  to store the solution for
        // its subscript.
        var G = Array(repeating: 0, count: n + 1)
        // For values of `n` `0` or `1`, the answer is `1`, either a tree with
        // a single item, or the empty tree.
        switch n {
            case 0:
                return 1
            case 1:
                return 1
            default:
                break
        }
        (G[0], G[1]) = (1, 1)
        // Start `i` from `2` because `0` and `1` have already been populated.
        for i in 2...n {
            // Start from `1` to avoid counting the empty tree.
            for j in 1...i {
                G[i] += G[j - 1] * G[i - j]
            }
        }
        return G[n]
    }
}

let result = Solution().numTrees(3)
print("result = \(result)")
