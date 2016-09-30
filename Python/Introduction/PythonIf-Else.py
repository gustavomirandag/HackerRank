#Another option:
#print((lambda n:'Weird' if n % 2 or 5 < n < 21 else 'Not Weird')(int(input())))

#!/bin/python3

import sys


n = int(input().strip())
if (n%2 != 0):
    print("Weird")
else:
    if (n>=2 and n<=5):
        print("Not Weird")
    else:
        if (n>=6 and n<=20):
            print("Weird")
        else:
            print("Not Weird")
            
        