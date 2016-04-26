import subprocess
import random
#runs a.out with paramater 3 => "./a.out 3 3"
numRuns = random.randint(1, 10)
#converts numRuns to a string to allow the subprocess call to run
numRuns = str(numRuns)
t = subprocess.call(['/home/andrew/GIT/GeneralStuff/C++/a.out', '3', numRuns]) 
print t