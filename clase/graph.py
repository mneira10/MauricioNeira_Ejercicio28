import matplotlib
matplotlib.use("Agg")
import numpy as np 
import matplotlib.pyplot as plt

data = np.loadtxt('runs.dat')
# print(data)

plt.semilogy(data[:,0],abs(data[:,1]-155/6)*100/(155/6))
plt.title("Percent error vs number of points")
plt.xlabel("Number of points")
plt.ylabel("Porcentual error")
plt.savefig('results.png')