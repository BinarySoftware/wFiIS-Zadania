
import matplotlib.pyplot as plt
import numpy
x,y,z =numpy.loadtxt("data.out", unpack=True)

plt.plot(x, y, 'o')
plt.errorbar(x, y, marker='*', yerr=z)
plt.xlabel('x')
plt.savefig('res.pdf')
    