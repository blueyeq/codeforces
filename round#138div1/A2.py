import sys
import os
import math

ab, ac, bc = map(int, raw_input().split());
ba = ab;
ca = ac;
cb = bc;
abc = math.sqrt(ab * bc * ac);
#print(abc);
tmp = bc * (ab + ac) + ac * (bc + ba) + ab * (ca + cb);
x = tmp / abc / 2
print((int)(x * 4));
