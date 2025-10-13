#Resolution equadiff ordre 2
import matplotlib.pyplot as plt
import numpy as np

data=np.loadtxt("equadiffordre2.txt")

plt.figure()
plt.plot(data[:,0],data[:,1],label='Euler')
plt.plot(data[:,0],data[:,3],label='cos(x) theo')
plt.plot(data[:,0],data[:,4],label='RK4')
plt.legend()
plt.xlabel("x")
plt.ylabel("y(x)")
plt.grid()
plt.title('Equation diff resolue par deux methodes ordre 2')

plt.figure()
plt.plot(data[:,4],data[:,5],label="RK4")
plt.legend()
plt.xlabel("y(x)")
plt.ylabel("y'(x)")
plt.grid()
plt.title('yprime en fonction de y')
