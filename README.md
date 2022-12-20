# langauge-speed-test
Compares Python, C, Java, and Javascript run times in computing a simple Riemann sum. Is organized through a bash script.
 Usage : bash run.sh [optional : number of test repetitions]
 
 
 Math Content: 
 
  Riemann Sum:
    The Riemann sum was used as an applied repetitive task. Although you'd normally just integrate this function, it serves
    as an example of when a programming language would run the same task over and over and over again.
    
   Statistics:
    The stat calculations were done in C for 2 reasons: 1. I hate myself 2. I need to study for my C exam. 
    I chose Python for the plotting because I got fed up with C, and the libraries used (pyplot and matplot) are good industry 
    standards to practice. 
    
   File Structure:   
     The run.sh script runs the files either 10, or the user specified number of, times. It then iterates over each language,
     and they run their Riemann sum. It get's the time that took, and stores that in a language respective txt file. The 
     tests are stored in the tests directory, and the results in the results directory.
     run.sh then calls a c file get_results.c which does the average and varience calculation, then it calls a Python script
     to display the data.
     
