# Task 3
There is a row of n security switches protecting a military installation entrance. The switches can be manipulated as
follows:
<br>
-   The rightmost switch may be turned on or off at will.
-   Any other switch may be turned on or off only if the switch to its immediate right is on and all the other
    switches to its right, if any, are off.
- Only one switch may be toggled at a time.

Design a Dynamic Programing algorithm to turn off all the switches, which are initially all on, in the minimum number of
moves. (Toggling one switch is considered one move.) Also find the minimum number of moves.

## Pseudocode

``` vbnet
function min_switch_helper(n, ans):
    if n <= 2:
        return n
    end if

    if ans[n] is not -1:
        return ans[n]
    end if

    x = min_switch_helper(n - 1, ans) + 2 * min_switch_helper(n - 2, ans) + 1
    ans[n] = x
    return ans[n]
end function

function min_switch(n):
    ans = new array of size n + 1

    for i from 0 to n:
        ans[i] = -1
    end for

    return min_switch_helper(n, ans)
end function
```
## Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(n)

## Sample Output
@ n = 4
```agsl
10
```
@ n = 5
```agsl
21
```

## Analytics
![image](https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/fdfb7405-f334-44a3-8bf5-c7e198a54972)

![image](https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/16f7f474-bf92-4044-b3ca-47c3bbda89e7)

![image](https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/b19460e5-1202-446b-ba05-3f1ff33fccf1)


## GUI Visualization

## Reference

## Members

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif">
<table align="center">
  <tbody>
    <tr>
      <td align="center" valign="top" width="25%"><a href="https://github.com/Ahmed-Khaled-Abdelmaksod"><img src="https://github.com/Ahmed-Khaled-Abdelmaksod.png" width="100px;" alt="Ahmed Khaled"/><br /><sub><b>Ahmed Khaled</b></sub></a><br />🤨</td>
       <td align="center" valign="top" width="25%"><a href="https://github.com/adhamkhaled312"><img src="https://github.com/adhamkhaled312.png" width="100px;" alt="Adham"/><br /><sub><b>Adham Khaled</b></sub></a><br />😏</td>
      <td align="center" valign="top" width="25%"><a href="https://github.com/AhmedBakrXI"><img src="https://github.com/AhmedBakrXI.png" width="100px;" alt="Bakr"/><br /><sub><b>Ahmed Bakr</b></sub></a><br />👨‍💻</td>
      <td align="center" valign="top" width="25%"><a href="https://github.com/waelmarwan7"><img src="https://github.com/waelmarwan7.png" width="100px;" alt="Marwan"/><br /><sub><b>Marwan Wael</b></sub></a><br />💥</td>
    </tr>
  </tbody>
</table>
<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif">
