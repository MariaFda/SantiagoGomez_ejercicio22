import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('datos.txt')
u_inicial = datos[:,2]
u = datos[:,1]
x = datos[:, 0]

plt.figure
plt.plot(x,u, label = 'final')
plt.plot(x,u_inicial, label = 'inicial')
plt.legend();
plt.savefig('PDE.pdf')
