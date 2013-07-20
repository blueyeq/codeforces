import sys
import os

   

n = input();
if n == 0 and n == 0:
    print('error');
    exit(0);
seg = [map(int, raw_input().split()) for i in xrange(n)]

Min = min(map(lambda x : x[0], seg));
Max = max(map(lambda x : x[1], seg));
 
t = [ i for i, x in enumerate(seg) if x[0] == Min and x[1] == Max]
print t[0] + 1 if t else -1;

exit(0);
