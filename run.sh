#!/bin/bash

if (($# == 0 )); then
    reps=10
    violated=1
elif (($# < 1 )); then
    echo Usage: '[number of repetitions]'
else
    reps=$1
    violated=0
fi

# create empty files for test results
> averages.txt
cd results # move to results directory

> java_results.txt
> python_results.txt
> c_results.txt
> js_results.txt


cd ../tests

# check if we need to recompile
if !(java Riemann &> /dev/null); then
    javac Riemann.java
fi

if !(./test_riemann &> /dev/null); then
    gcc ./test_riemann.c ./test_riemann
fi

for ((  i = 0; i < reps; i++ ))
do

    echo $(java Riemann) >> ../results/java_results.txt
    echo $(python3 Python_Riemann.py) >> ../results/python_results.txt
    echo $(./test_riemann) >> ../results/c_results.txt
    echo $(node jsRiemannSum.js) >> ../results/js_results.txt
    
done

cd ..

# call time calculator

bash c_run_code.sh get_results.c $reps > results.txt

cat results.txt

if !(python3 plot_results.py &> /dev/null); then
    echo "You may not have numpy or matplot. Run 'bash install_dependencies.sh' to install."
fi