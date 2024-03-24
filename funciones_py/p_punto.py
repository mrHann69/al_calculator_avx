import numpy as np

n = 10000000
lst = range(0,n)
x = 2
v1 = np.array(lst)
v2 = np.array(lst)
for i in lst:
  v2[i] = 1
sum = 0
for i in lst:
  sum = sum + (v1[i] + 1) * v2[i]

print("vector 1: %s, vector 2: %s" % (v1, v2))
