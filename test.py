import sys
sys.path.append("/Users/dkim/Documents/Programming/Python/pyserial-3.4")
import pandas as pd
import operator
import numpy as np
import serial

df = pd.DataFrame({'x' : [1, 2, 3, 4], 'y' : [4, 5, 6, 7], 'z' : [2, 4, 5, 6], 'a' : [3, 5, 7, 8]})
print(df)
s = df.ix[:, [0, 1]]
print s
s1 = s.mean(axis = 1)
print s1
# s2 = [df.ix[:, [2, 3]] - s1 for df.ix[:, [2, 3]], s1 in zip(df.ix[:, [2, 3]], s1)]
# print s2
s2 = df - s1(axis = 1).reshape(-1, 1)
print s2
