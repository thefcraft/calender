## Calendar Algorithm Project

This project is primarily focused on the underlying algorithm to determine the day of the week for any given date. It's tailored for beginners looking to understand date-time mathematics and computations.

### Background:

The anchor point for this algorithm is knowing that 1st January 0001 was a Saturday. Using this knowledge, we can compute the day of the week for any subsequent date.

### Logic:

1. Compute the total number of days at the end of the last year.
    - Normal days: `365 * (year - 1)`
    - Leap year days: `floor(year - 1 / 4)`
2. Add days of the current year up to the given date.
3. Divide the total by 7 and use the remainder to determine the day of the week.

### Mathematical Implementation:

In Python:
```python
def f(d, m, y):
    return int((y-1)*365+(y-1)//4+28*(m-1)+2*max(0, m-2)+min(1, max(0,1-max(m-2, 2-m)))*2-((-(m-1+(m//8))/2)//1) +d+ (y//4-(y-1)//4)*min(1, max(0,1-max(min(m,3)-3, 3-min(m,3))))-1)%7
```

Usage:
```python
print({0:'Sunday', 1:'Monday', 2:'Tuesday', 3:'Wednesday', 4:'Thursday', 5:'Friday', 6:'Saturday'}[f(2, 9, 2023)])
```

### How to Use:

#### Python:
- Direct execution:
    ```bash
    python main.py
    ```
- As a module:
    ```python
    from main import Calendar
    calendar = Calendar(2, 9, 2023)
    print(calendar)
    print(calendar.nameOfDay)  # Outputs: 'Saturday' on 2 sep 2023
    ```

#### C++:
Compile and run:
```bash
g++ main.cpp
./a.out  # Or the generated executable name
```

### Expected Output:
```
Saturday, 2 September 2023
Su Mo Tu We Th Fr Sa
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
```
