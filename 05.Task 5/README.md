# Task 05 - Coin Pairing Problem

## 1. Problem Description
In this problem, there are n coins initially placed in a row. The objective is to form n/2 pairs of coins through a sequence of moves. On each move, a single coin must jump over adjacent coins, with the number of adjacent coins to jump over increasing by one on each subsequent move. The goal is to determine all values of n for which the problem has a solution and design an algorithm that solves it in the minimum number of moves for those n.

## 2. Algorithm
### Greedy Algorithm to Find Minimum Number of Moves
1. Start from the leftmost coin.
2. On each move, jump the current coin over the next k adjacent coins, where k increases by one on each move.
3. Continue this process until n/2 pairs of coins are formed.

## 3. Pseudocode
```lua
-- Function to check if it's possible to solve the problem for given 'n'
function check_possible(n)
    if n % 4 == 0 then
        return true
    end
    return false
end

-- Function to check if the puzzle is solved
function check_done(coins, size)
    local numberOfTwos = 0
    local numberOfZeroes = 0
    for i = 1, size do
        if coins[i] == 2 then
            numberOfTwos = numberOfTwos + 1
        elseif coins[i] == 0 then
            numberOfZeroes = numberOfZeroes + 1
        end
    end
    return numberOfTwos == size / 2 and numberOfZeroes == size / 2
end

-- Function to perform a jump
function jump(coins, coin1_position, coin2_position)
    coins[coin1_position] = 0
    coins[coin2_position] = 2
end

-- Function to check if a move is possible
function move_possible(coins, pos1, pos2, moveNum)
    if coins[pos1] ~= 1 or coins[pos2] ~= 1 then
        return false
    end
    local sum = 0
    for i = pos1 + 1, pos2 - 1 do
        sum = sum + coins[i]
    end
    return sum == moveNum
end

-- Function to find the minimum moves to solve the puzzle
function minimum_moves(coins, size)
    if not check_possible(size) then
        return -1
    end
    local move = 1
    local count = size
    for k = 1, size / 4 do
        while coins[count] ~= 1 do
            count = count - 1
        end
        for j = count - 1, 1, -1 do
            if move_possible(coins, j, count, move) then
                jump(coins, j, count)
                move = move + 1
                count = count - 1
                break
            end
        end
    end
    for k = 1, 3 * size / 4 do
        if coins[k] ~= 1 then
            goto continue
        end
        for j = k + 1, size do
            if move_possible(coins, k, j, move) then
                jump(coins, k, j)
                move = move + 1
                break
            end
        end
        ::continue::
    end
    return move - 1
end
```

## 4. Complexity Analysis
- **Time Complexity:** The time complexity of the greedy algorithm is O(n^2) omega(n), as it iterates through the coins to form pairs and calculates the minimum number of moves.
- **Space Complexity:** The space complexity is also O(n), as the algorithm stores the sequence of moves needed to form pairs.

## 5. The Used Algorithm
The greedy algorithm iterates through the coins and forms pairs by jumping each coin over adjacent coins in a sequence of moves. It starts with a single move, where a coin jumps over one adjacent coin, and increases the number of adjacent coins to jump over on each subsequent move until n/2 pairs of coins are formed. This approach ensures that the minimum number of moves is used to form pairs of coins.

## Members:
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Ahmed-Khaled-Abdelmaksod"><img src="https://github.com/Ahmed-Khaled-Abdelmaksod.png" width="100px;" alt="Ahmed Khaled"/><br /><sub><b>Ahmed Khaled</b></sub></a><br />🤨</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Somaya-Ayman"><img src="https://github.com/Somaya-Ayman.png" width="100px;" alt="Somaya-Ayman"/><br /><sub><b>Somaya Ayman</b></sub></a><br />💫</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/MightyMaya"><img src="https://github.com/MightyMaya.png" width="100px;" alt="Maya"/><br /><sub><b>Maya Sharaf</b></sub></a><br />🌷</td>
    </tr>
  </tbody>
</table>
