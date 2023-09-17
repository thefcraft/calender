#include <iostream>
#include<cmath> // for std::floor, std::min, std::max
using namespace std;
string f(double d, double m, double y) {
    switch(int((y-1)*365  + floor((y-1)/4) + 28*(m-1) + 2*max(0.0, m-2) + min(1.0, max(0.0, 1-max(m-2, 2-m))) * 2 -floor((1-m-(m/8))/2) + d + (floor(y/4)-floor((y-1)/4))*min(1.0, max(0.0, 1-max(min(m, 3.0)-3, 3-min(m, 3.0)))) -1)%7) {
    case 0: return "Sunday"; case 1: return "Monday"; case 2: return "Tuesday"; case 3: return "Wednesday"; case 4: return "Thursday"; case 5: return "Friday"; case 6: return "Saturday";}
}

int main() {
    cout << f(2, 9, 2023) << endl;  // -> Saturday
    return 0;
}
