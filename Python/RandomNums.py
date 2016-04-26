import subprocess
import random
#runs a.out with paramater 3 => "./a.out 3 3"
numRuns = random.randint(1, 2000)
#converts numRuns to a string to allow the subprocess call to run
numRuns = str(numRuns)
subprocess.call(['/home/andrew/GIT/GeneralStuff/C++/PNT.out', numRuns]) 
outputFile = open('RandomNumsOut.txt',"r")
string = outputFile.read()
numTrue = string.count("True")
numFalse = string.count("False")
print "number of values >= 1000: " + str(numTrue) 
print "number of values < 1000: " + str(numFalse)