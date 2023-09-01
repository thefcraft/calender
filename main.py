class Month:
    def __init__(self, month=None, year=None):
        self.month = month
        self.monthName = {1:'January', 2:'February', 3:'March', 
                          4:'April', 5:'May', 6:'June', 
                          7:'July', 8:'August', 9:'September', 
                          10:'October', 11:'November', 12:'December'}[self.month]
        self.leapYear = True if year%4 == 0 else False
        
        self.noOfDays = {1:31, 2:29 if self.leapYear else 28,
                         3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31,
                         11:30, 12:31}[self.month]
    
    def __str__(self): return self.monthName#f"{self.month}-{self.monthName}"

class Calendar:
    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year = year
        self.months = {i:Month(i, self.year) for i in range(1,13)}
        assert self.months[self.month].noOfDays >= self.day and self.day>0 and self.month>0 and self.month<=12
        
    def __str__(self):
        output = f"{self.nameOfDay}, {self.day} {self.months[self.month]} {self.year}\n"
        output += 'Su Mo Tu We Th Fr Sa\n'
        idx = 0
        for i in range((self.totalDaysFromStarting()-2)%7):
            output += '   '
            idx += 1
        for i in range(1, self.months[self.month].noOfDays+1):
            output += f'{i if len(str(i))==2 else " "+str(i)} '
            idx+=1
            if idx %7 ==0 : output+='\n'
            
        return output.replace(' \n', '\n').removesuffix('\n')
    
    def isLeapYear(self, year=None):
        if year is None: year = self.year
        return True if year%4 == 0 else False
    
    def daysAtEndOfYearFromStarting(self, year=None):
        if year is None: year = self.year
        return 365*year + year//4
    
    def daysAtCurrentdayOfYearFromStartingOfYear(self):
        days = 0
        for i in range(1, self.month): days+=self.months[i].noOfDays
        days += self.day
        return days
    
    def totalDaysFromStarting(self):
        return self.daysAtCurrentdayOfYearFromStartingOfYear() + self.daysAtEndOfYearFromStarting(self.year-1)
    
    @property
    def nameOfDay(self):
        return {0:'Saturday', 1:'Sunday', 2:'Monday', 3:'Tuesday', 
                4:'Wednesday', 5:'Thursday', 6:'Friday'}[self.totalDaysFromStarting()%7]
        
    
calendar = Calendar(2, 9, 2023)
print(calendar)
# print(calendar.nameOfDay)
# print(calendar.totalDaysFromStarting()%7)
# print((calendar.totalDaysFromStarting()-2)%7)