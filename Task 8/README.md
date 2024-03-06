# Task 8
If you have 50 boxes that contains 50 pieces of metal all of the same known weight. one of these boxes contains fake
metal pieces that weigh 1 kilogram less than the pieces in the rest of the boxes. You can use a digital scale only once
to find this fake box. 
<br>
Design a brute force algorithm to solve this problem.

## Pseudo Code:
``` python
Initialize total_weight to 0
Initialize fake_box_index to 0

for index from 1 to 50:
    balls_count = index
    total_weight += balls_count * weight_of_non_fake_ball
    new_box_weight = balls_count * weight_of_non_fake_ball
end

Place the new box on the digital scale
real_weight = weight measured by the scale

fake_box_index = (total_weight - real_weight) / weight_of_non_fake_ball

Display "Weight Difference: ", (total_weight - real_weight)
Display "Fake Box index: ", fake_box_index

```

## Complexity Analysis:
Time Complexity: O(n), where n is the no. of boxes.
Space Complexity: O(1)

## Sample Output:
Input:
```
2 21
```
Output:
```
Weight Difference: 42
Fake Box index: 21
```

## GUI Visualization:


https://github.com/AhmedBakrXI/Design-and-Analysis-of-Algorithm-Project/assets/114930002/d0726e42-0a35-47d8-aad9-cdf17c339d26



## Members:
<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif">

<table align="center">
  <tbody>
    <tr>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/Karim-308"><img src="https://github.com/Karim-308.png" width="100px;" alt="Kimo"/><br /><sub><b>Karim Ibrahim</b></sub></a><br />🫡</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/AhmedBakrXI"><img src="https://github.com/AhmedBakrXI.png" width="100px;" alt="Bakr"/><br /><sub><b>Ahmed Bakr</b></sub></a><br />👨‍💻</td>
      <td align="center" valign="top" width="33.33%"><a href="https://github.com/D3cipherd"><img src="https://github.com/D3cipherd.png" width="100px;" alt="Abd-Elrahman"/><br /><sub><b>Abdelrahman Elsayed</b></sub></a><br />🔇</td>
    </tr>
  </tbody>
</table>
<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif">
