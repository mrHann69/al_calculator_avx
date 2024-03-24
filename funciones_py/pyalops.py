import numpy as np

def p_punto_py():
  n = 100
  lst = range(0,n)
  x = 2
  v1 = np.array(lst)
  v2 = np.array(lst)
  for i in lst:
    v2[i] = 1
  sum = 0
  for i in lst:
    sum = sum + (v1[i] + 1) * v2[i]
  return sum

def vector_x_escalar():
  numMax = 100
  lst = range(0, numMax)
  escalar = 2
  vector = np.array(lst)
  for i in lst:
    vector[i] = vector[i] * escalar
  return vector
