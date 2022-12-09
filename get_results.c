#include <stdio.h>
#include <stdlib.h>

double average_time(char file[]){

    double time_recorded = 0;
    double sum =0;
    FILE *f = fopen(file, "r");

    for (int i = 0; i < 15; i++){
        fscanf(f, "%lf", &time_recorded);
        sum+=time_recorded;
    }

    return sum/15;
}


int main(){

    char c_results[] = "c_results.txt";
    char python_results[] = "python_results.txt";
    char java_results[] = "java_results.txt";
    char js_results[] = "js_results.txt";

    double c_average=average_time(c_results);
    double python_average=average_time(python_results);
    double java_average=average_time(java_results);
    double js_average=average_time(js_results);

    printf("%s %f \n%s %f \n%s %f \n%s %f \n", "Average C run time: ", c_average, "Average Python run time: ", 
    python_average, "Average Java run time: ", java_average, "Average JavaScript run time: ", js_average);
    return 0;
}