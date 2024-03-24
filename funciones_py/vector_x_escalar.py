import numpy as np

# function para calcular un vector por un escalar
n = 10000000
lst = range(0,n)
x = 2
v = np.array(lst)

for i in lst:
  v[i] = v[i] * x

print("vector: %s, escalar: %f" % (v, x))
