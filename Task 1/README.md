# Task 01 - Tiling a 2n x 2n Board with Right Trominoes
---

## Problem Description
We are given a 2n × 2n board with one missing square. Our task is to tile this board with right trominoes of three different colors, such that no pair of trominoes that share an edge have the same color. The right tromino is an L-shaped tile formed by three adjacent squares.

## Algorithm
To solve this problem using dynamic programming, we can follow these steps:
### A. Define State:
- Let's define our state as a tuple `(i, mask)`, where:
  - `i` represents the current column we are filling (from 0 to 2n - 1).
  - `mask` is an integer that represents the colors used in the trominoes in the previous column. We can use binary representation where each bit represents whether a color is used or not.
### B. Base Case:
- When `i = 2n`, we have filled the entire board, so we return 1 (indicating success).
### C. Recursive Step:
- At each column `i`, we iterate through all possible ways to place a tromino.
- We consider three cases for each position in the column:
  1. If the square is already filled, we move to the next square.
  2. If we can place a tromino vertically, we recursively call the function for the next column with updated mask and position.
  3. If we can place a tromino horizontally, we recursively call the function for the next column with updated mask and position.
### D. Memoization:
- To avoid recomputation, we memoize the results for each state `(i, mask)` in a 2D array.
### E. Backtracking:
- Once we have computed the count of valid tilings, we can backtrack to find the actual tiling by storing the colors used for each tromino in another 2D array.

## Pseudocode
```python
function countTilings(i, mask):
    if i = 2n:
        return 1
    
    if dp[i][mask] is not null:
        return dp[i][mask]
    
    result = 0
    
    for each position in column i:
        if the square is already filled:
            continue
        for each possible tromino placement:
            if placement is valid:
                new_mask = update mask based on colors used in current tromino
                result += countTilings(i + 1, new_mask)
    
    dp[i][mask] = result
    return result
```

## Complexity Analysis
- **Time Complexity:** Since each state is computed only once, and there are O(2^(2n)) states, the time complexity is O(2^(2n)).
- **Space Complexity:** The memoization array requires O(n * 2^n) space.

## Used Algorithms
1. Divide and Conquer
2. Dynamic Programming
3. Brute Force

Let's compare the three algorithms: Divide and Conquer, Dynamic Programming, and Brute Force. We'll assess them based on their approach, efficiency, and ease of implementation.

1. **Divide and Conquer:**
   - **Approach:** This algorithm divides the problem into smaller subproblems, tiles each subproblem separately, and then combines the solutions. It recursively divides the grid into quadrants until it reaches a base case.
   - **Efficiency:** The algorithm has a time complexity of O(n^2), as each quadrant of the grid is processed independently.
   - **Ease of Implementation:** The implementation is straightforward and intuitive. It involves recursive function calls to tile the grid.

2. **Dynamic Programming:**
   - **Approach:** Dynamic programming stores the solutions to subproblems in a table and reuses these solutions to solve larger subproblems. It involves filling a memoization table with the count of valid tilings for each state.
   - **Efficiency:** The time complexity is O(3^n), where n is the size of the grid. This is because each cell can have three different colors, and there are 3^(n^2) possible colorings. However, memoization reduces the actual computational time by avoiding redundant calculations.
   - **Ease of Implementation:** Implementing dynamic programming can be more complex compared to Divide and Conquer. It requires careful handling of state transitions and memoization.

3. **Brute Force:**
   - **Approach:** Brute force tries all possible colorings of the grid and checks if each coloring satisfies the constraints. It exhaustively searches through all possible combinations.
   - **Efficiency:** The time complexity is very high, O(3^(n^2)), as it explores all possible colorings without any optimization.
   - **Ease of Implementation:** Brute force is relatively easy to implement, as it involves iterating through all possible colorings and checking their validity.

## Conclusion
- **Efficiency:** Divide and Conquer is the most efficient among the three, with a time complexity of O(n^2). Dynamic programming follows, with a time complexity of O(3^n), but it benefits from memoization. Brute Force is the least efficient, with a time complexity of O(3^(n^2)).
- **Ease of Implementation:** Brute force is the easiest to implement, followed by Divide and Conquer. Dynamic programming requires more careful handling due to state transitions and memoization.
- In summary, if efficiency is the primary concern, Divide and Conquer is the best choice. However, if ease of implementation is more important or if the problem size is small enough to tolerate the exponential complexity, Brute Force might suffice. Dynamic Programming strikes a balance between efficiency and ease of implementation but may be overkill for smaller problem instances.

# Members:
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Mahmoud-Abdelraouf"><img src="https://github.com/Mahmoud-Abdelraouf.png" width="100px;" alt="Mahmoud"/><br /><sub><b>Mahmoud Abdelraouf</b></sub></a><br />😎</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/adhamkhaled312"><img src="https://github.com/adhamkhaled312.png" width="100px;" alt="Adham"/><br /><sub><b>Adham Khaled</b></sub></a><br />😏</td>
       <td align="center" valign="top" width="33.33%"><a href="https://github.com/Somaya-Ayman"><img src="https://github.com/Somaya-Ayman.png" width="100px;" alt="Somaya-Ayman"/><br /><sub><b>Somaya Ayman</b></sub></a><br />💫</td>
    </tr>
  </tbody>
</table>
