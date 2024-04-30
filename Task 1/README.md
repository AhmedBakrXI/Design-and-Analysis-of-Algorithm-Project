# Task 01 - Tiling a 2n x 2n Board with Right Trominoes

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
```lua
-- Declare global variables
local gridSize, xCoordinate, yCoordinate, count = 0
local grid = {}

-- Function to place a tile at given coordinates
function placeTile(x1, y1, x2, y2, x3, y3)
    -- Generate a random count value
    count = generateRandomCount()

    -- Mark the tiles in the grid with random numbers
    grid[x1][y1] = count % 3 + 1
    grid[x2][y2] = count % 3 + 1
    grid[x3][y3] = count % 3 + 1
end

-- Function to generate a random count value
function generateRandomCount()
    return math.random(1, RAND_MAX)
end

-- Function based on divide and conquer to fill the grid with tiles recursively
function tile(size, startX, startY)
    -- Variables to store the coordinates of the hole
    local holeRow, holeCol

    -- Base case: if the grid size is 2x2
    if size == 2 then
        -- Generate a random count value
        count = generateRandomCount()

        -- Place tiles in the grid
        for i = 0, size - 1 do
            for j = 0, size - 1 do
                if grid[startX + i][startY + j] == 0 then
                    grid[startX + i][startY + j] = count % 3 + 1
                end
            end
        end
        return
    end

    -- Finding hole location
    for i = startX, startX + size - 1 do
        for j = startY, startY + size - 1 do
            if grid[i][j] ~= 0 then
                holeRow = i
                holeCol = j
            end
        end
    end

    -- Calculate half of the 'size' variable
    local half = size / 2

    -- Placing tiles in the respective quadrants based on the location of the hole
    if holeRow < startX + half and holeCol < startY + half then
        placeTile(startX + half, startY + half - 1, startX + half, startY + half, startX + half - 1, startY + half)
    elseif holeRow >= startX + half and holeCol < startY + half then
        placeTile(startX + half - 1, startY + half, startX + half, startY + half, startX + half - 1, startY + half - 1)
    elseif holeRow < startX + half and holeCol >= startY + half then
        placeTile(startX + half, startY + half - 1, startX + half, startY + half, startX + half - 1, startY + half - 1)
    elseif holeRow >= startX + half and holeCol >= startY + half then
        placeTile(startX + half - 1, startY + half, startX + half, startY + half - 1, startX + half - 1, startY + half - 1)
    end

    -- Recursively divide the grid into 4 quadrants and fill them with tiles
    tile(half, startX, startY + half)      -- Top right quadrant
    tile(half, startX, startY)             -- Top left quadrant
    tile(half, startX + half, startY)      -- Bottom left quadrant
    tile(half, startX + half, startY + half) -- Bottom right quadrant
end
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

## Simple output

## GUI Visualization

## Members
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Mahmoud-Abdelraouf"><img src="https://github.com/Mahmoud-Abdelraouf.png" width="100px;" alt="Mahmoud"/><br /><sub><b>Mahmoud Abdelraouf</b></sub></a><br />😎</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/adhamkhaled312"><img src="https://github.com/adhamkhaled312.png" width="100px;" alt="Adham"/><br /><sub><b>Adham Khaled</b></sub></a><br />😏</td>
       <td align="center" valign="top" width="33.33%"><a href="https://github.com/Somaya-Ayman"><img src="https://github.com/Somaya-Ayman.png" width="100px;" alt="Somaya-Ayman"/><br /><sub><b>Somaya Ayman</b></sub></a><br />💫</td>
    </tr>
  </tbody>
</table>
