#!/usr/bin/env python3
import random
import string

def main():
  """
  Program entry point.
  """
  # Proszę utworzyć k-elementową listę całkowitych wartości losowych z przedziału [0,5k).Proszę sprawdzić ile elementów pozostaje na swoim miejscu po losowym przemieszaniu listy, mieszanie proszę wykonać 100 razy a wyniki zapisywać w słowniku (2p)
  k = 10
  l = random.sample(range(5*k), k)
  hist = {}

  for i in range(100):
    ol = l[:]
    random.shuffle(l)
    same = 0
    for i in range(k):
      if ol[i] == l[i]:
        same +=1
    if same in hist:
      hist[same] += 1;
    else:
      hist[same] = 1;
  
  print(hist)
  print()


  # Proszę utworzyć losowy string o długości k zawierający tylko małe litery, pomiędzy poszczególne litery proszę wstawić kropkę (1p)
  k = 50
  l = '.'.join(random.choices(string.ascii_lowercase,k=k))
  print(l)
  print()

  # Proszę utworzyć listę stu wartości losowych z przedziału [0,20). Następnie na jej podstawie proszę utworzyć słownik, w którym klucze są liczbami z listy, a wartościami lista ich indeksów. w rozwiązaniu proszę wykorzystać metodę setdefault i funkcjię enumerate (1.5p). w rozwiązaniu proszę wykorzystać metody setdefault i index (1.5p)
  k = 100
  l = random.choices(range(0,20), k=k)
  d = {}
  for i in range(0,20):
    index = [ix for ix,v in enumerate(l) if v == i]
    d.setdefault(i, index)
  print(d)
  print()

  d = {}
  for i in range(0,20):
    index = [l.index(i,c,k) for c in range(0, len(l)) if i == l[c]]
    d.setdefault(i, index)
  print(d)
  print()

  # Proszę sprawdzić ile spośród 1000 losowych wartości całkowitych składających się z n cyfr, gdzie n jest z przedziału [3,6], jest liczbami palindromowymi. Wynik proszę zapisać w słowniku (2p)
  k = 1000
  l = []
  d = {3:0, 4:0, 5:0}
  for i in range(0,k):
    n = random.randint(3,6)
    if n == 3 :
      l.append(random.randint(100,999))
    if n == 4 :
      l.append(random.randint(1000,9999))
    if n == 5 :
      l.append(random.randint(10000,99999))
  
  l = list(map(str, l))

  for i in l:
    if i == i[::-1]:
      d[len(i)] += 1
  
  print(d)
  print()

  # Proszę utworzyć dwa słowniki o rozmiarze 10, w których kluczami są kolejne liczby naturalne, a wartościami liczby losowe z przedziału [1,100). Następnie w obu słownikach proszę zamienić miejscami klucze z wartościami.
  d1 = {}
  d2 = {}

  for i in range(10):
    d1[i] = random.randint(1,100)
    d2[i] = random.randint(1,100)
  
  print(d1, d2) 
  print()
  d1 = dict((v,k) for k,v in d1.items())
  d2 = dict((v,k) for k,v in d2.items())
  print(d1, d2)
  print()

  # Na podstawie tak otrzymanych słowników proszę utworzyć nowy słownik, w którym klucze są kluczami występującymi jednocześnie w obu wcześniej utworzonych słownikach, wartościami natomiast są dwuelementowe krotki wartości związanych z danym kluczem w słownikach oryginalnych  (2p)
  d3 = {}

  for k,v in d1.items():
    if k in d2:
      d3.setdefault(k,(d2[k],v))
  print(d3)
  print()

if __name__ == "__main__":
  main()