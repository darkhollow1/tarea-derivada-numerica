import matplotlib.pyplot as plt
import numpy as np

x,y,z= np.loadtxt("data.txt", unpack=True)

plt.plot(x,y,'-o', label="data1" )
plt.plot(x,z,'-o', label="data2" )
plt.xscale("log")
plt.yscale("log")
plt.legend()
plt.show()