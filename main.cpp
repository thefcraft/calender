#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;

class Month {
public:
    Month(int month = 1, int year = 1970) {
        this->month = month;
        monthName = {
            {1,"January"}, {2,"February"}, {3,"March"},
            {4,"April"}, {5,"May"}, {6,"June"},
            {7,"July"}, {8,"August"}, {9,"September"},
            {10,"October"}, {11,"November"}, {12,"December"}
        };
        leapYear = (year % 4 == 0);
        noOfDays = {
            {1,31}, {2, (leapYear?29:28)}, {3,31}, {4,30}, {5,31}, {6,30},
            {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}
        };
    }

    string str() const {
        return monthName.at(month);
    }

    int getNoOfDays() const {
        return noOfDays.at(month);
    }

private:
    int month;
    unordered_map<int, string> monthName;
    bool leapYear;
    unordered_map<int, int> noOfDays;
};

class Calendar {
public:
    Calendar(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
        for(int i = 1; i <= 12; ++i) {
            months[i] = Month(i, year);
        }
        assert(months[month].getNoOfDays() >= day && day > 0 && month > 0 && month <= 12);
    }

    string str() const {
        string output = nameOfDay() + ", " + to_string(day) + " " + months.at(month).str() + " " + to_string(year) + "\n";
        output += "Su Mo Tu We Th Fr Sa\n";
        int idx = 0;
        for(int i = 0; i < (totalDaysFromStarting() - day) % 7; ++i) {
            output += "   ";
            idx++;
        }
        for(int i = 1; i <= months.at(month).getNoOfDays(); ++i) {
            output += (i >= 10 ? to_string(i) : " " + to_string(i)) + " ";
            idx++;
            if(idx % 7 == 0) output += "\n";
        }
        if(output.back() == ' ') output.pop_back();
        if(output.back() == '\n') output.pop_back();
        return output;
    }

    bool isLeapYear(int year) const {
        return year % 4 == 0;
    }

    int daysAtEndOfYearFromStarting(int year) const {
        return 365 * year + year / 4;
    }

    int daysAtCurrentdayOfYearFromStartingOfYear() const {
        int days = 0;
        for(int i = 1; i < month; ++i) days += months.at(i).getNoOfDays();
        days += day;
        return days;
    }

    int totalDaysFromStarting() const {
        return daysAtCurrentdayOfYearFromStartingOfYear() + daysAtEndOfYearFromStarting(year - 1);
    }

    string nameOfDay() const {
        unordered_map<int, string> dayNames = {
            {0,"Saturday"}, {1,"Sunday"}, {2,"Monday"}, {3,"Tuesday"},
            {4,"Wednesday"}, {5,"Thursday"}, {6,"Friday"}
        };
        return dayNames[totalDaysFromStarting() % 7];
    }

private:
    int day, month, year;
    unordered_map<int, Month> months;
};

int main() {
    Calendar calendar(15, 9, 2023);
    cout << calendar.str() << endl;
    return 0;
}