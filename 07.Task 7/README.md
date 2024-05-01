# Task 7
A computer game has a shooter and a moving target. The shooter can hit any of n > 1 hiding spot located along a
straight line in which the target can hide. The shooter can never see the target; all he knows is that the target moves
to an adjacent hiding spot between every two consecutive shots. 
<br>
Design a Dynamic Programing algorithm that
guarantees hitting the target.
<hr>
solution: 
<br>
implementing a dynamic programming solution to find the minimum number of shots needed to guarantee hitting a target positioned at one of several hiding spots. The problem assumes that the target can move between hiding spots, and the goal is to determine the minimum shots required to ensure a hit, regardless of the target's movements.

The minShotsToHitTarget function takes an integer n representing the number of hiding spots and returns the minimum shots needed. The program uses a dynamic programming approach to build an array DP, where DP[i] represents the minimum shots required to hit the target at the i-th hiding spot.

The DP array is initialized with maximum integer values, except for the base case DP[1], where no shots are needed to hit the target at the first hiding spot. The program then iterates through all hiding spots, considering all possible positions for the target to move.

For each hiding spot i, the program iterates through potential target positions j and updates DP[i] based on the minimum shots needed from the previous hiding spot.

# Members:
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Mennatallah74"><img src="https://github.com/Mennatallah74.png" width="100px;" alt="Menna"/><br /><sub><b>Mennatallah</b></sub></a><br />🌸</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/MightyMaya"><img src="https://github.com/MightyMaya.png" width="100px;" alt="Maya"/><br /><sub><b>Maya Sharaf</b></sub></a><br />🌷</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Saraashrf"><img src="https://github.com/Saraashrf.png" width="100px;" alt="Sara"/><br /><sub><b>Sara Ashraf</b></sub></a><br />🌟</td>
    </tr>
  </tbody>
</table>
