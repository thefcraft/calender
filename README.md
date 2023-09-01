# calender

in this project i will  more focus on algorithm so ignore it but you may consider my approach.
JUST ALGORITHM BASED PROJECT FOR BEGINNERS.

## logic
We know that there is Saturday on 1 jan 0001 so i use this as backend and write my code
365*(year-1) + [(year-1)/4] = total no of days at the end of last year                [.] -> greatest integer less than or equal to
for example, 
    if year = 2023, then
    365*2022 = no of normal days
    [2022/4] = no of leap year extra day
now i add the days of current year, for example 2 sep 2023 there is total of 245 days gone

now i just divide the number by 7 and get the remainder and if remainder = 0 then it is Saturday same as 1 jan 0001
and add 1 day for else....

## how to use
for python
```
python main.py
```
for c++
```
g++ main.cpp
```
and then run the exe

## output
output is look like this
```
Saturday, 2 September 2023
Su Mo Tu We Th Fr Sa
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
```
