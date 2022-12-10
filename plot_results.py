import numpy as np
from matplotlib import pyplot as plt


# get averages from c output file
averages=[]
with open('averages.txt') as file:
    for f in file:
            line=f #get line from file
            end=int(len(line)-1) 
            line=line[0:end] #cut off '/n' that is stored in text file
            averages.append(line)


# change data from string to int
averages = list(map(float, averages))


# convert from time to times faster then python
ratios =[]
constant = 1/averages[1]

for a in averages:
    print('state')
    ratio = 1/a
    ratios.append(ratio/constant)


# setup graph
languages = ['C','Python', 'Java', 'JS']
plt.bar(languages, ratios)
plt.xlabel("Programming Language")
plt.ylabel("Times faster then Python")
plt.title("Programming Language speed comparison")
# display graph
plt.show()