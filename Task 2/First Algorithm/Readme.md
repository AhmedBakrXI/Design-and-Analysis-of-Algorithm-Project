# Task 2
## Pseudocode
```
1- Initialize all squares on the board as unvisited.
2- Start at any point on the chess board.
3- Mark the initial position.
4- Discover the neighbors of the current square and 
choose the unvisited square with minimal degree "has least neighbors".
5- Mark the cell with the current move number.
6- Repeat 4 and 5 till you finish marking the board.
7- Return the marked board.
```
## Complexity Analysis
Time complexity: O(N^3)
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
## References
https://sites.science.oregonstate.edu/math_reu/proceedings/REU_Proceedings/Proceedings2004/2004Ganzfried.pdf

## Contributers
<table>
  <tbody>
    <tr> 
        <td align="center" align="top" width="100%"><a href="https://github.com/AhmedBakrXI"><img src="https://github.com/AhmedBakrXI.png" width="100px;" alt="Bakr"/><br /><sub><b>Ahmed Bakr</b></sub></a><br />👨‍💻</td>
    </tr>
  </tbody>
</table>
