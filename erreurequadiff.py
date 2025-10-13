#Methodes de resolution d'equations différentielles
import matplotlib.pyplot as plt
import numpy as np

methodes=np.loadtxt("equadiff.txt")
erreurs=np.loadtxt("erreurequadiff.txt")

plt.figure()
plt.plot(methodes[:,0],methodes[:,1],label="Euler")
plt.plot(methodes[:,0],methodes[:,2],label="Heun")
plt.plot(methodes[:,0],methodes[:,3],label="RK4")
plt.plot(methodes[:,0],methodes[:,4],label="Theorie exp(-x)")
plt.grid()
plt.legend()
plt.xlabel("x")
plt.ylabel("y(x)")
plt.title("Comparaison des methodes de resolution a la theorie")

h=erreurs[:,0]

plt.figure()
plt.plot(erreurs[:,0],erreurs[:,1],label="Euler")
plt.grid()
plt.legend()
plt.xscale('log')
plt.yscale('log')
plt.xlabel("h (pas)")
plt.ylabel("y(x)")
plt.title("Erreurs des methodes de resolution d'equadiff en fonction du pas")

# plt.figure()
plt.plot(erreurs[:,0],erreurs[:,2],label="Heun")
plt.grid()
plt.legend()
plt.xscale('log')
plt.yscale('log')
plt.xlabel("h (pas)")
plt.ylabel("y(x)")
plt.title("Erreurs des methodes de resolution d'equadiff en fonction du pas")

# plt.figure()
plt.plot(erreurs[:,0],erreurs[:,3],label="RK4")
plt.grid()
plt.legend()
plt.xscale('log')
plt.yscale('log')
plt.xlabel("h (pas)")
plt.ylabel("y(x)")
plt.title("Erreurs des methodes de resolution d'equadiff en fonction du pas")
