# CIS 165 Lab 7: BMI and Color Mixer

## How I ran the programs
I wrote both programs and compiled them with c++ 


## Plan for Program 1 (bmi.cpp)
- **Inputs:** weight in pounds and height in inches, both stored as doubles.
- **Variables:** `weight`, `height`, `bmi`, and the constants `POUNDS`, `UNDERWEIGHT_LIMIT`, and `OVERWEIGHT_LIMIT`.
- **Validation:** if weight or height is 0 or less, print an error and stop before doing the math.
- **Calculation:** `bmi = weight * POUNDS_FACTOR / (height * height)`, saved in the `bmi` variable.
- **Comparisons:** under 18.5 is Underweight, 25.0 or less is Optimal weight, anything higher is Overweight.
- **Output:** the BMI with two decimal places, then the category.


## Plan for Program 2 (color_mixer.cpp)
- **Inputs:** two color names saved in char arrays that hold up to `COLOR_SIZE` (20) characters.
- **Variables:** `first_color`, `second_color`, and true/false variables like `first_red` and `second_blue`.
- **Validation:** each color has to be red, blue, or yellow. I check with `strcmp`. If either one is wrong, I print an error.
- **Comparisons:** if both colors are the same, print that color. Red and blue make purple, red and yellow make orange, and blue and yellow make green. I check each mix in both orders.
- **Output:** the mixed color or an error message.

## Test records

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| BMI 1 | 100, 70 | 14.35 - Underweight | BMI: 14.35 - Underweight | Match |
| BMI 2 | 150, 70 | 21.52 - Optimal weight | BMI: 21.52 - Optimal weight | Match |
| BMI 3 | 200, 70 | 28.69 - Overweight | BMI: 28.69 - Overweight | Match |
| BMI 4 | 150, 0 | Error message | Error: weight and height must be positive. | Match |
| BMI 5 | -150, 70 | Error message | Error: weight and height must be positive. | Match |
| BMI extra | 133.2, 70 | About 19.11 - Optimal weight. I wanted to test a number in the middle of the optimal range. By hand: 133.2 * 703 / 4900 is about 19.11. | BMI: 19.11 - Optimal weight | Match |
| Color 1 | red, blue | purple | Result: purple | Match |
| Color 2 | red, yellow | orange | Result: orange | Match |
| Color 3 | blue, yellow | green | Result: green | Match |
| Color 4 | blue, red | purple | Result: purple | Match |
| Color 5 | red, red | red | Result: red | Match |
| Color 6 | orange, blue | Error | Error: enter red, blue, or yellow. | Match |
| Color 7 | red, orange | Error | Error: enter red, blue, or yellow. | Match |
| Color extra | yellow, yellow | yellow. I wanted to make sure same-color works for a color other than red. | Result: yellow | Match |

## Why 18.5 and 25.0 are "Optimal weight"
The lab says the optimal range is 18.5 through 25.0 and includes both ends. My first check is `bmi < 18.5`, which is false for exactly 18.5, so it moves on to the next check and ends up in Optimal weight. My second check is `bmi <= 25.0`, which is true for exactly 25.0, so that is optimal too. Only numbers bigger than 25.0 get to the last `else`.

## Explaining my code

**1. How does the BMI formula use pounds and inches? Why is height * height needed?**
The formula takes weight in pounds, multiplies it by 703.0, and divides by height in inches squared. The 703.0 is what makes the units work out for pounds and inches. The height has to be squared, and in C++ `^` does not mean exponent, so I wrote `height * height`.

**2. How do the conditions handle exactly 18.5 and 25.0? Does order matter?**
Exactly 18.5 is not less than 18.5, so it skips Underweight and lands in Optimal weight. Exactly 25.0 passes `bmi <= 25.0`, so it is also optimal. The order does matter. Each `else if` only runs if the one before it was false, so by the time the program checks `<= 25.0` it already knows the BMI is at least 18.5. If I switched the order, I would have to change the conditions or some values would end up in the wrong group. There are no gaps because every number is either under 18.5, between 18.5 and 25.0, or over 25.0.

**3. Why check weight and height before calculating?**
If the height were 0 the formula would divide by zero. Negative numbers also do not make sense for a person's weight or height. Checking first stops the program before it can do a bad calculation.

**4. Why classify the unrounded BMI and only round the displayed value?**
If I used the rounded number, a BMI like 25.004 would print as 25.00 but is really over 25.0. Using the real stored value keeps the category right. `setprecision(2)` only changes how the number prints, not the number itself.

**5. What does strcmp return for equal text? Why not use ==?**
`strcmp` returns 0 when the two strings match. With a char array, `==` compares where the arrays are stored in memory instead of the letters inside them, so it would almost never be true even if the words are the same.

**6. How does each mixture work in either order, and with two of the same color?**
For each mix I check both orders using `||`. For example, purple is `(first_red && second_blue) || (first_blue && second_red)`. For two of the same color, once I know both are valid I use `strcmp(first_color, second_color) == 0` and print that color.

**7. How do I check for an invalid color in either position?**
I made two variables, `first_valid` and `second_valid`. The first `if` checks `!first_valid || !second_valid`, so if either color is bad the error prints before any mixing happens.

**8. How do named constants and result variables make the programs easier to read?**
Names like `COLOR_SIZE` and `UNDERWEIGHT_LIMIT` tell you what a number is for, and if I need to change one I only change it in one place. Saving the answer in `bmi` and using true/false variables means the math and long comparisons are not stuffed inside `cout` or the `if` statements, so they are easier to read and check.
