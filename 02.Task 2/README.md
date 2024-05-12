# Task 2
Is it possible for a chess knight to visit all the cells of an 8 × 8 chessboard exactly once, ending at a cell one knight’s
move away from the starting cell? (Such a tour is called closed or re-entrant. Note that a cell is considered visited only
when the knight lands on it, not just passes over it on its move.)
<br>
If it is possible design a greedy algorithm to find the minimum number of moves the chess knight needs.

## Answer
Yes, it's possible & The minimum number of moves is 64 move.

## Pseudocode
```python
while not finding closed path tour:
    initializeTheBoard()
    
    x = x_init
    y = y_init
    chessboard[x_init][y_init] = 0
    
    for i from 0 to N * N - 1:
        if not pickNextMove(x, y):
            continue
            
    if not isNeighbourSquare(x, y, x_init, y_init):
        continue
        
    printChessBoard()
end
```
## Complexity Analysis
Time complexity: O(N^3 * m), where N is the width of the chess board and m is the number of trials to find the solution.
<br>
Space Complexity: O(N^2), Such That The Chess Board is N x N.
## Sample Output
at (0, 0)
```
0  57 14 31 62 27 12 29
15 32 63 56 13 30 61 26
58 1  48 43 60 55 28 11
33 16 59 52 49 46 25 54
2  51 44 47 42 53 10 39
17 34 19 50 45 40 7  24
20 3  36 41 22 5  38 9
35 18 21 4  37 8  23 6
```
at (2, 5)
```
7  10 5  26 53 12 55 46
4  25 8  11 56 45 52 13
9  6  27 60 29 54 47 44
24 3  30 57 42 59 14 51
31 20 61 28 63 50 43 48
2  23 0  41 58 39 36 15
19 32 21 62 17 34 49 38
22 1  18 33 40 37 16 35
```
at (3, 3)
```
24 27 16 35 30 9  14 11
17 38 25 28 15 12 31 8
26 23 36 55 34 29 10 13
37 18 39 0  57 44 7  32
22 1  56 43 54 33 62 45
19 40 21 48 63 58 53 6
2  49 42 59 4  51 46 61
41 20 3  50 47 60 5  52
```

## Conclusion
We can make a closed tour on a chess board using a knight without moving to a square twice.

## Analytics

<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="100%">
        <img src="https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/7edf24a7-f8ef-4e1f-ae1a-ec2d571712a0" alt="No. of Trials to Find Closed Path vs. Initializing Square">
      </td>
    </tr>
    <tr>
      <td align="center" valign="top" width="100%">
        <img src="https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/3da81528-6bb8-4ce7-8e24-44bd80f650ea" alt="No. of Moves to Find Closed Path vs. Initializing Square">
      </td>
    </tr>
  </tbody>
</table>

## Another Approach
Another approach to solve this problem would be to use backtracking but this results in stack overflow on big boards.
Time Complexity would be O(8^(n^2)) and n is the number of cells in one row i.e. the board is n * n, since the algorithm tries 8 different moves each time the knight jumps on a square.
Space Complexity would be O(N^2) where the board is N * N.

``` python
def knight_tour(board, pos_x, pos_y, x, y, move_num):
    if move_num == N * N:
        return True

    for i in range(8):
        next_x = x + X[i]
        next_y = y + Y[i]

        if 0 <= next_x < N and 0 <= next_y < N and board[next_x][next_y] == -1:
            board[next_x][next_y] = move_num
            visualize_move(pos_x, pos_y, next_x, next_y)

            if knight_tour(board, pos_x, pos_y, next_x, next_y, move_num + 1):
                return True

            visualize_backtrack(next_x, next_y)
            board[next_x][next_y] = -1

    return Falsedef knight_tour(board, pos_x, pos_y, x, y, move_num):
    if move_num == N * N:
        return True

    for i in range(8):
        next_x = x + X[i]
        next_y = y + Y[i]

        if 0 <= next_x < N and 0 <= next_y < N and board[next_x][next_y] == -1:
            board[next_x][next_y] = move_num
            visualize_move(pos_x, pos_y, next_x, next_y)

            if knight_tour(board, pos_x, pos_y, next_x, next_y, move_num + 1):
                return True

            visualize_backtrack(next_x, next_y)
            board[next_x][next_y] = -1

    return False

def visualize_move(pos_x, pos_y, next_x, next_y):
    pos_x.append(next_x)
    pos_y.append(next_y)
    print(f"Move to {next_x},{next_y}")

def visualize_backtrack(next_x, next_y):
    print(f"No place to move from {next_x},{next_y}: Backtrack")


def visualize_move(pos_x, pos_y, next_x, next_y):
    pos_x.append(next_x)
    pos_y.append(next_y)
    print(f"Move to {next_x},{next_y}")

def visualize_backtrack(next_x, next_y):
    print(f"No place to move from {next_x},{next_y}: Backtrack")

```

## References
https://sites.science.oregonstate.edu/math_reu/proceedings/REU_Proceedings/Proceedings2004/2004Ganzfried.pdf

## Visualization




https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/2ef3c391-5081-4ee1-8eaf-c8e4ea17c26d



## Members
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Mahmoud-Abdelraouf"><img src="https://github.com/Mahmoud-Abdelraouf.png" width="100px;" alt="Mahmoud"/><br /><sub><b>Mahmoud Abdelraouf</b></sub></a><br />😎</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/adhamkhaled312"><img src="https://github.com/adhamkhaled312.png" width="100px;" alt="Adham"/><br /><sub><b>Adham Khaled</b></sub></a><br />😏</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/AhmedBakrXI"><img src="https://github.com/AhmedBakrXI.png" width="100px;" alt="Bakr"/><br /><sub><b>Ahmed Bakr</b></sub></a><br />👨‍💻</td>
    </tr>
  </tbody>
</table>
