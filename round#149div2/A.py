import sys
import os

x, y, a, b = map(int, raw_input().split());

a = [(u, v) for u in xrange(a, x + 1) for v in xrange(b, min(u, y + 1))]
print len(a);
print '\n'.join(map(lambda x : '%d %d' % (x[0], x[1]), a));
