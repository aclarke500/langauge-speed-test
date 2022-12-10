#include <stdio.h>
#include <time.h>

clock_t start, end;

double example_function(double x) { return x * x * x + 4.0; }

double left_riemann_sum(double a, double b) {
    // we need to define the width of the rectangles
    double width = 0.0001;
    double sum = 0;
    double position = a;  // we start at a double a
    double val = 0;

    while (position < b) {
        val = example_function(position);
        val *= width;
        sum += val;
        position += width;
    }
    return sum;
}

int main() {
    start = clock();
    double riemann_sum = left_riemann_sum(0, 100);
    end = clock();

    double time_used = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f", time_used);
}