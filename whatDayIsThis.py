def f(d, m, y):
    # return {0:'Sunday', 1:'Monday', 2:'Tuesday', 3:'Wednesday', 4:'Thursday', 5:'Friday', 6:'Saturday'}[int((y-1)*365+(y-1)//4+28*(m-1)+2*max(0, m-2)+min(1, max(0,1-max(m-2, 2-m)))*2-((-(m-1+(m//8))/2)//1) +d+ (y//4-(y-1)//4)*min(1, max(0,1-max(min(m,3)-3, 3-min(m,3))))-1)%7]
    return ((y-1)*365+(y-1)//4+28*(m-1)+2*max(0, m-2)+min(1, max(0,1-max(m-2, 2-m)))*2-((-(m-1+(m//8))/2)//1) +d+ (y//4-(y-1)//4)*min(1, max(0,1-max(min(m,3)-3, 3-min(m,3))))-1)%7

print(f(2, 9, 2023)) #-> Saturday