import random
from math import log

#
# Zadanie 1 - Proszę napisać generator zwracający kolejne wiersze trójkąta 
#             Pascala wraz z sumą ich wartości
#

def pascal():
  k = [1]
  yield sum(k), k
  while True:
    l = []
    el = 0
    for i in k:
      l.append(el+i)
      el = i
    l.append(1)
    k = l
    yield sum(k), k

print("Z1\n")
g = pascal()
for i in range(10):
  spaces = "  " * (10-i)
  print(f"{i}: {spaces}{next(g)}")

#
# Zadanie 2 - Proszę wygenerować losowy ciąg zer i jedynek o długości N. 
#             Proszę napisać generator zwracający liczbę zer oddzielających kolejne 
#             jedynki w sekwencji przekazanej jako parametr. 
#             Korzystając z utworzonego generatora proszę obliczyć średnią odległość 
#             między kolejnymi jedynkami w wygenerowanym wcześniej ciągu.
#

def ileZer(s):
  n = 0
  for i in s:
      if i == 1:
        yield n
        n = 0
      else:
        n += 1

print("\nZ2\n")
N = 10000
input = [random.choice([0,1]) for _ in range(N)]
iloscZer = list(ileZer(input))
print(iloscZer)
avgOdl = sum(iloscZer)/len(iloscZer)
print(avgOdl)

#
# Zadanie 3 - Proszę napisać trzy funkcje generatorowe:
# - zwracającą kolejne elementy ciągu Fibonacciego,
# - zwracającą te wartości z przekazanej jako parametr sekwencji, które są 
#   parzyste/nieparzyste
# - zwracającą wartości z przekazanej jako pierwszy parametr sekwencji i przerywającą 
#   działanie po napotkaniu wartości większej niż drugi parametr przekazany do funkcji
# Korzystając ze zdefiniowanych funkcji proszę obliczyć sumę parzystych/nieparzystych # elementów ciągu Fibonacciego mniejszych od 100
#

def fib():
  a, b = 0, 1
  while True:
    yield a
    a, b = b, a + b

def isEven(s,even=True):
  for e in s:
    if even:
      if e%2 == 0:
        yield e
    else:
      if e%2 != 0:
        yield e

def lessThan(s,par):
  for e in s:
    if e < par:
      yield e
    else: return

print("\nZ3\n")
g = fib()
for i in range(10):
  print(next(g))

input = [random.randrange(10) for _ in range(10)]
g = isEven(input)
print(list(g))

input = [random.randrange(50) for _ in range(20)]
g = lessThan(input,35)
print(list(g))

evenSum = sum(isEven(lessThan(fib(), 100)))
oddSum = sum(isEven(lessThan(fib(), 100), False))

print(evenSum)
print(oddSum)

#
# Zadanie 4 - Proszę napisać generator działający dokładnie tak samo jak wbudowany 
#             range, ale pozwalający na generowanie liczb rzeczywistych.

def myrange(min=0,max=None,step=1):
  # Case : tylko jeden parametr maksymalny
  if max == None and min != 0:
    max = min
    min = 0

  if step == 0: return
  elif step > 0 and max > min:
    while min < max:
      yield min
      min += step
  elif step < 0 and max < min:
    while min > max:
      yield min
      min += step
  else: return

print("\nZ4\n")
print(list(myrange(7)))
print(list(myrange(-7)))
print(list(myrange(2,7)))
print(list(myrange(7,2)))
print(list(myrange(2,7,2)))
print(list(myrange(2,7,-2)))
print(list(myrange(7,2,2)))
print(list(myrange(7,2,-2)))
print()
print(list(range(7)))
print(list(range(-7)))
print(list(range(2,7)))
print(list(range(7,2)))
print(list(range(2,7,2)))
print(list(range(2,7,-2)))
print(list(range(7,2,2)))
print(list(range(7,2,-2)))

#
# Zadanie 5 - Proszę napisać generator obliczający ui wg zależności:
# ui=ui-1+a/xi-1, z wartością początkową u0=0 dla x0=1 oraz z xi=x0+ia
# Obliczenia proszę wykonać dla a=0.05 i przerwać je dla x=1.5. 
# Zależność pozwala na wyznaczenie przybliżonej wartości logarytmu naturalnego
# z danej liczby. Generator ma zwracać x oraz przybliżoną i dokładną wartość 
# logarytmu naturalnego dla danego x

def approxLog():
    u = 0.0
    x0 = 1.0
    a = 0.05
    maxX = 1.5
    iter = 1
    x = 1.0
    while x <= maxX:
      yield x, u, log(x)
      u += a/x
      x = x0 + iter*a
      iter += 1

print("\nZ5\n")
print(list(approxLog()))