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

## math's
```python
def f(d, m, y):
    #single line of code
    return int((y-1)*365+(y-1)//4+28*(m-1)+2*max(0, m-2)+min(1, max(0,1-max(m-2, 2-m)))*2-((-(m-1+(m//8))/2)//1) +d+ (y//4-(y-1)//4)*min(1, max(0,1-max(min(m,3)-3, 3-min(m,3))))-1)%7

print({0:'Sunday', 1:'Monday', 2:'Tuesday', 3:'Wednesday', 4:'Thursday', 5:'Friday', 6:'Saturday'}[f(2, 9, 2023)]) #-> Saturday
```

## how to use
for python
```
python main.py
```
or
```python
from main import Calendar
calendar = Calendar(2, 9, 2023)
print(calendar)
print(calendar.nameOfDay) # -> 'Saturday' on 2 sep 2023
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
