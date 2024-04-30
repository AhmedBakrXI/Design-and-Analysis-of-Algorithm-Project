# Task 05 - Coin Pairing Problem

## 1. Problem Description
In this problem, there are n coins initially placed in a row. The objective is to form n/2 pairs of coins through a sequence of moves. On each move, a single coin must jump over adjacent coins, with the number of adjacent coins to jump over increasing by one on each subsequent move. The goal is to determine all values of n for which the problem has a solution and design an algorithm that solves it in the minimum number of moves for those n.

## 2. Algorithm
### Greedy Algorithm to Find Minimum Number of Moves
1. Start from the leftmost coin.
2. On each move, jump the current coin over the next k adjacent coins, where k increases by one on each move.
3. Continue this process until n/2 pairs of coins are formed.

## 3. Pseudocode
```pseudo
// Function to check if it's possible to solve the problem for given 'n'
function check_possible(n):
    if n % 4 == 0:
        return true
    return false

// Function to check if the puzzle is solved
function check_done(coins, size):
    numberOfTwos = 0
    numberOfZeroes = 0
    for i from 0 to size - 1:
        if coins[i] == 2:
            numberOfTwos++
        else if coins[i] == 0:
            numberOfZeroes++
    return numberOfTwos == size / 2 && numberOfZeroes == size / 2

// Function to perform a jump
function jump(coins, coin1_position, coin2_position):
    coins[coin1_position] = 0
    coins[coin2_position] = 2

// Function to check if a move is possible
function move_possible(coins, pos1, pos2, moveNum):
    if coins[pos1] && coins[pos2] != 1:
        return false
    sum = 0
    for i from pos1 + 1 to pos2 - 1:
        sum += coins[i]
    if sum == moveNum:
        return true
    return false

// Function to find the minimum moves to solve the puzzle
function minimum_moves(coins, size):
    if !check_possible(size):
        return -1
    move = 1
    count = size - 1
    for k from 0 to (size / 4) - 1:
        while coins[count] != 1:
            count--
        for j from count - 1 down to 0:
            if move_possible(coins, j, count, move):
                jump(coins, j, count)
                move++
                count--
                break
    for k from 0 to 3 * size / 4:
        if coins[k] != 1:
            continue
        for j from k + 1 to size - 1:
            if move_possible(coins, k, j, move):
                jump(coins, k, j)
                move++
                break
    return move - 1
```

## 4. Complexity Analysis
- **Time Complexity:** The time complexity of the greedy algorithm is O(n), as it iterates through the coins to form pairs and calculates the minimum number of moves.
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
