#!/usr/bin/swift

import Foundation

class Solution {
    func exist(_ board: [[Character]], _ word: String) -> Bool {
        guard word.count > 0 else {
            return true
        }
        let firstChars = findFirstCharacter(board, word[word.startIndex])
        guard word.count > 1 else {
            return firstChars.count > 0
        }

        for loc in firstChars {
            let result = findWord(board, word, loc)
            if result {
                return true
            }
        }
        return false
    }

    func findWord(_ board: [[Character]], _ restWord: String, _ loc: (Int, Int)) -> Bool {
        guard restWord.count > 0 else {
            return true
        }
        for char in restWord {
            let adjs = findAdjacent(board, loc, char)
            guard adjs.count > 0 else {
                return false
            }
            let subWord = String(restWord.dropFirst())
            for adj in adjs {
                if findWord(board, subWord, adj) {
                    return true
                }
            }
        }
        return false
    }

    func findFirstCharacter(_ board: [[Character]], _ char: Character) -> [(Int, Int)] {
        var found = [(Int, Int)]()
        for hIndex in 0 ..< board.count {
            for vIndex in 0 ..< board[hIndex].count {
                if board[hIndex][vIndex] == char {
                    found.append((hIndex, vIndex))
                }
            }
        }
        return found
    }

    func findAdjacent(_ board: [[Character]], _ loc: (Int, Int), _ char: Character) -> [(Int, Int)] {
        var found = [(Int, Int)]()
        let (hIndex, vIndex) = loc
        let options = [(hIndex - 1, vIndex - 1),
                       (hIndex - 1, vIndex),
                       (hIndex - 1, vIndex + 1),
                       (hIndex, vIndex - 1),
                       (hIndex, vIndex),
                       (hIndex, vIndex + 1)]
        for option in options {
            if option.0 > 0, option.0 < board.count {
                if option.1 > 0, option.1 < board[option.0].count {
                    if board[option.0][option.1] == char {
                        found.append((option.0, option.1))
                    }
                }
            }
        }
        return found
    }
}

let board: [[Character]] = [["A","B","C","E"],
             ["S","F","C","S"],
             ["A","D","E","E"]]
let word = "ABCCED"
let result = Solution().exist(board, word)
NSLog("result = \(result)")
