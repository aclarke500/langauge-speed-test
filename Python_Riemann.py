import time

def riemann(a, b):
    width = 0.000001
    sum = 0
    position = a  # we start at a 
    val = 0

    while (position < b):
        val = example_function(position)
        val *= width
        sum += val
        position += width

    return sum

def example_function(x):
    return x**3 + 4


t0 = time.time()
x = riemann(0,100)
t1 = time.time()

print(t1-t0)