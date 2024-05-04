# Task 04 - Tower of Hanoi Puzzle with Four Pegs

## 1. Problem Description:

The Tower of Hanoi puzzle with four pegs is an extension of the classic Tower of Hanoi problem, where the goal is to move a stack of disks from one peg to another, following certain rules. In this variant, there are four pegs instead of the traditional three, which adds complexity to the problem. The objective remains the same: transfer all the disks from the source peg to the destination peg, using the other two pegs as auxiliary, while adhering to the rules.

## 2. Algorithm:

The algorithm used to solve the Tower of Hanoi puzzle with four pegs is based on a modified form of the traditional Tower of Hanoi algorithm. It involves recursive division and conquer, as well as the application of the traditional three-peg Tower of Hanoi algorithm.

## 3. Pseudocode:

```lua
-- Global variable to track the number of moves
moveCount = 0

-- Function to move disks between pegs using traditional Tower of Hanoi algorithm
function traditionalThreePeg(n, source, destination, auxiliary, startDisk, endDisk)
    if n == 1 then
        print("Move disk " .. startDisk .. " from rod " .. source .. " to rod " .. destination)
        moveCount = moveCount + 1
        return
    end
    traditionalThreePeg(n - 1, source, auxiliary, destination, startDisk, endDisk - 1)
    print("Move disk " .. endDisk .. " from rod " .. source .. " to rod " .. destination)
    moveCount = moveCount + 1
    traditionalThreePeg(n - 1, auxiliary, destination, source, startDisk, endDisk - 1)
end

-- Function to solve Tower of Hanoi with four pegs
function fourPegAlgorithm(n, source, destination, auxiliary1, auxiliary2)
    if n == 0 then
        return
    end
    if n == 1 then
        print("Move disk 1 from rod " .. source .. " to rod " .. destination)
        moveCount = moveCount + 1
        return
    end
    local k = largestK(n)
    fourPegAlgorithm(n - k, source, auxiliary1, auxiliary2, destination)
    traditionalThreePeg(k, source, destination, auxiliary2, n - k + 1, n)
    fourPegAlgorithm(n - k, auxiliary1, destination, auxiliary2, source)
end

-- Main function
function main(argc, argv)
    if argc ~= 2 then
        print("Usage: " .. argv[0] .. " <number of disks>")
        return 1
    end
    local n = tonumber(argv[1]) -- Number of disks
    fourPegAlgorithm(n, 'A', 'D', 'B', 'C')
    print("Total moves made: " .. moveCount)
    return 0
end
```

## 4. Complexity Analysis:

The time complexity of the Tower of Hanoi puzzle with four pegs depends on the number of disks (n). The recursive algorithm exhibits exponential time complexity, O(2^n), as the number of moves required grows exponentially with the number of disks.

The space complexity of the Tower of Hanoi puzzle with four pegs is also exponential, O(2^n), primarily due to the recursive calls made during the execution of the algorithm. Each recursive call adds a new stack frame to the call stack, consuming memory proportional to the number of recursive calls. Additionally, the space complexity includes the space required to store the input parameters and any auxiliary variables used during the execution of the algorithm. However, these requirements are minimal compared to the recursive calls and do not significantly impact the overall space complexity. Therefore, the space complexity is dominated by the recursive calls and remains exponential, O(2^n), where n is the number of disks.


## 5. The Used Algorithm

The algorithm used to solve the Tower of Hanoi puzzle with four pegs is a combination of recursive division and conquer, along with the traditional three-peg Tower of Hanoi algorithm. It ensures the optimal solution for transferring all the disks from the source peg to the destination peg while following the rules of the puzzle.

## 6. Simple Output
**Input:** 4

**Output**
```
Optimal value of k for n = 4: 2
------------------------------------------------
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 4 from rod A to rod D
Move disk 3 from rod C to rod D
Move disk 1 from rod B to rod C
Move disk 2 from rod B to rod D
Move disk 1 from rod C to rod D
------------------------------------------------
Total moves made: 9
```

**Input:** 8

**Output**
```
Optimal value of k for n = 8: 3
------------------------------------------------
Move disk 1 from rod A to rod D
Move disk 2 from rod A to rod B
Move disk 3 from rod A to rod C
Move disk 2 from rod B to rod C
Move disk 1 from rod D to rod C
Move disk 4 from rod A to rod D
Move disk 5 from rod A to rod B
Move disk 4 from rod D to rod B
Move disk 1 from rod C to rod D
Move disk 2 from rod C to rod A
Move disk 3 from rod C to rod B
Move disk 2 from rod A to rod B
Move disk 1 from rod D to rod B
Move disk 6 from rod A to rod D
Move disk 7 from rod A to rod C
Move disk 6 from rod D to rod C
Move disk 8 from rod A to rod D
Move disk 6 from rod C to rod A
Move disk 7 from rod C to rod D
Move disk 6 from rod A to rod D
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod D
Move disk 3 from rod B to rod C
Move disk 2 from rod D to rod C
Move disk 1 from rod A to rod C
Move disk 4 from rod B to rod A
Move disk 5 from rod B to rod D
Move disk 4 from rod A to rod D
Move disk 1 from rod C to rod A
Move disk 2 from rod C to rod B
Move disk 3 from rod C to rod D
Move disk 2 from rod B to rod D
Move disk 1 from rod A to rod D
------------------------------------------------
Total moves made: 33
```

## GUI Visualization
https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/90259729/22b07ee5-593d-475d-a100-e34434ee1c3d

## Members:
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Karim-308"><img src="https://github.com/Karim-308.png" width="100px;" alt="Kimo"/><br /><sub><b>Karim Ibrahim</b></sub></a><br />🫡</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Mahmoud-Abdelraouf"><img src="https://github.com/Mahmoud-Abdelraouf.png" width="100px;" alt="Mahmoud"/><br /><sub><b>Mahmoud Abdelraouf</b></sub></a><br />😎</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Saraashrf"><img src="https://github.com/Saraashrf.png" width="100px;" alt="Sara"/><br /><sub><b>Sara Ashraf</b></sub></a><br />🌟</td>
    </tr>
  </tbody>
</table>
