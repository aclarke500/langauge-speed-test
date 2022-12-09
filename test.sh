#!/bin/bash

# create empty files for test results

> java_results.txt
> python_results.txt
> c_results.txt
> js_results.txt


for ((  i = 0; i < 15; i++ ))
do
    echo $(java Riemann) >> java_results.txt
    echo $(python3 Python_Riemann.py) >> python_results.txt
    echo $(./test_riemann) >> c_results.txt
    echo $(node jsRiemannSum.js) >> js_results.txt
    
done
# call time calculator
results=$(bash c_run_code.sh get_results.c)

echo $results > results.txt
echo $results