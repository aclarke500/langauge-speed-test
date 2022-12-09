#include <stdio.h>
#include <stdlib.h>

int reps;  // the amount of times we repeat the calculation, equal to the number
           // of lines of text in each file

double average_time(char file[]) {
    // puts(file);
    double time_recorded = 0;
    double sum = 0;
    FILE *f = fopen(file, "r");

    for (int i = 0; i < reps; i++) {
        fscanf(f, "%lf", &time_recorded);
        sum += time_recorded;
    }

    return sum / reps;
}


/*
 * Writes sz int values from arr into f one value per line.
 */
void arr_write(FILE *f, size_t arr_sz, const double *arr) {
    for (int i = 0; i < arr_sz; i++) {
        puts("state");
        fprintf(f, "%f\n", arr[i]);
    }
}

double time_varience(char file[]) {
    double mean = average_time(file);
    double sum = 0;
    double value = 0;
    FILE *f = fopen(file, "r");

    for (int i = 0; i < reps; i++) {
        fscanf(f, "%lf", &value);
        sum += (value - mean);
    }

    return sum / (reps - 1.0);
}

int main(int argc, char *argv[]) {
    // set reps to command line args

    reps = atoi(argv[1]);
    // printf("%d", reps);

    char c_results[] = "results/c_results.txt";
    char python_results[] = "results/python_results.txt";
    char java_results[] = "results/java_results.txt";
    char js_results[] = "results/js_results.txt";

    double c_average = average_time(c_results);
    double python_average = average_time(python_results);
    double java_average = average_time(java_results);
    double js_average = average_time(js_results);

    double c_var = time_varience(c_results);
    double python_var = time_varience(python_results);
    double java_var = time_varience(java_results);
    double js_var = time_varience(js_results);

    // printf("%s %f \n%s %f \n%s %f \n%s %f \n", "Average C run time: ",
    // c_average, "Average Python run time: ", python_average, "Average Java run
    // time: ", java_average, "Average JavaScript run time: ", js_average);

    // make array of length 4
    double averages[4] = {c_average, python_average, java_average, js_average};
    int size=4;
    int *sz = &size;
    FILE *a = fopen("averages.txt", "w");
    arr_write(a, 4, averages);
    // call function

    printf("%s %f %s %f \n", "js average time: ", js_average, "js varience: ", js_var);
    printf("%s %f %s %f\n", "java average time: ", java_average, "java varience: ", java_var);
    printf("%s %f %s %f\n", "Python average time: ", python_average, "Python varience: ", python_var);
    printf("%s %f %s %f\n", "C average time: ", c_average, "C varience: ", c_var);

    return 0;
}