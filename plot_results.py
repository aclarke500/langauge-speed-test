import numpy as np
from matplotlib import pyplot as plt
import math

plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

def f(x):
   return np.sin(x) + x + x * np.sin(x)

def bellcurve(x):
    return math.e**(-x**2)

x = np.linspace(-5, 5, 100)


averages=[]
with open('averages.txt') as file:
    for f in file:
            line=f #get line from file
            end=int(len(line)-1) 
            line=line[0:end] #cut off '/n' that is stored in text file
            averages.append(line)




slowest_time=0
# double averages[4] = {c_average, python_average, java_average, js_average};

# temp = list(map(int, temp)) # change data from string to int
averages = list(map(float, averages))

ratios =[]
constant = 1/averages[1]

for a in averages:
    ratio = 1/a
    ratios.append(ratio/constant)

print(ratios)

langs = ['C','Python', 'Java', 'JS']
plt.bar(langs, ratios)
plt.xlabel("Programming Language")
plt.ylabel("Times faster then Python")
plt.title("Programming Language speed comparison")





plt.show()