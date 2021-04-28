
# Zadanie 1

def zad1(name,n):
  with open(name) as pl:
    l = pl.readlines()
    print(l[:n]) # pierwsze n
    print()
    print(l[-n:]) # ostanie n
    print()
    print(l[::n]) # co n
    print()
    print([e.split()[n-1] for e in l]) # n-te slowo
    print()
    print([e[n-1] for e in l]) # n-ty znak

# zad1("lines.txt",3)

# Zadanie 2

import glob
import numpy

def zad2():
  inputs = glob.glob("data/*.in")
  data = [open(n) for n in  inputs]
  lines = list(map(lambda x: x.readlines(), data))
  lines = numpy.transpose(lines)
  print(lines)
  
  with open("data.out", "a") as output:
    for i in range(len(lines)):
      nums = list(map(lambda x: float(x), lines[i]))
      avg = numpy.average(nums)
      std_dev = numpy.std(nums)
      output.write(f"{i} {avg} {std_dev}\n")


  for f in data:
    f.close()

# zad2()

# Zadanie 3

def zad3():
  with open ("plot.py", "w") as f:
    f.write("""
import matplotlib.pyplot as plt
import numpy
x,y,z = numpy.loadtxt("data.out", unpack=True)

# plt.plot(x, y, 'o')
plt.errorbar(x, y, marker='*', yerr=z)
plt.xlabel('x')
plt.savefig('res.pdf')
    """)

# zad3()

# Zadanie 4

def zad4():
  inputs = glob.glob("rank/*.txt")
  data = [open(n) for n in  inputs]
  lines = list(map(lambda x: x.readlines(), data))
  for i in range(len(lines)):
    lines[i] = list(map(lambda x: (x.split(" ")[0], x.split(" ")[1]), lines[i]))
    # wziac z listy list krotek krotki o tym samym kluczu
    # zrobic liste list [klucz wartosc wartsc ... wartosc]
  print(lines)

  for f in data:
    f.close()

zad4()

# Zadanie 5
import matplotlib.pyplot as plt

def zad5():
  l = []
  with open("zad5A.in") as f:
    l = f.read().split()
  # with open("zad5B.in") as f:
  #   l = f.read().split()

  l.sort()
  el, cnt = numpy.unique(l, return_counts=True)
  ticks = range(len(cnt))
  plt.bar(ticks,cnt)
  plt.xticks(ticks,el)
  plt.savefig("zad5.pdf")

# zad5()