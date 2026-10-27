# AI Reflection

**Tools used:** I used ChatGPT to help write and review my code and to check my plan. I compiled and ran both programs myself and compared the output to what I expected.

**One decision:** For the BMI categories I used `bmi < 18.5`, then `else if (bmi <= 25.0)`, then `else`. I used `<=` on the second one so exactly 25.0 counts as optimal, and I left the first one as just `<` so exactly 18.5 is not underweight. In the color mixer I saved each `strcmp` result in a true/false variable like `first_red`. That way I only compare each color once, and the mixing conditions are a lot shorter and easier to read.

**Checking my work:** I compiled it and got no warnings. I also checked one BMI by hand: 150 * 703 = 105,450 and 70 * 70 = 4,900, so 105,450 / 4,900 is about 21.52, and that is what the program printed. For the color mixer I ran every mix in both orders, all three same-color cases, and an invalid color in each spot.

**Learning:** I can now write an if / else if / else chain and make sure the cutoff numbers land in the right category. I can also compare char arrays with `strcmp` and explain why `==` doesn't work for them. I still need practice thinking of my own instead of only using the ones from the lab.
