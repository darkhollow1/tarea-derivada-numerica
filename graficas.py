import matplotlib.pyplot as plt
import numpy as np

h,Ef,Ec= np.loadtxt("data.txt", unpack=True)

plt.plot(h,Ef,'-o', label="forward error" )
plt.plot(h,Ec,'-o', label="central error" )
plt.xscale("log")
plt.yscale("log")
plt.xlabel("h")
plt.ylabel("perc. error")
plt.legend()
#plt.show()
plt.savefig("perc_error_graph.pdf")