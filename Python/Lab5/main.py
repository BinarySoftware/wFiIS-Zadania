#!/usr/bin/env python3
import random

def main():
  """
  Program entry point.
  """
  # Proszę napisać funkcję przyjmującą jako parametr string 
  # (przy wywołaniu będziemy przekazać argument wiersza poleceń). 
  # Zakładamy, że string ten zawiera poprawną definicję wyrażenia/funkcji matematycznej z jedną zmienną x, czyli np. 'a*x+b', 'a*x**2+b*x+c'. 
  # W miejscu wszystkich stałych proszę wstawić losowe liczby całkowite z przedziału [0,10), proszę wykorzystać metodę translate. 
  # Z funkcji proszę zwrócić listę dwuelementowych krotek (x, f(x)), dla 10 losowych liczb rzeczywistych z przedziału [0,1] (2p).
  print(" --- Zadanie 1 ---")
  print(zad1('a*x+b'))
  print(zad1('a*x**2+b*x+c'))

  # Proszę napisać funkcję, do której można przekazać zmienną liczbę parametrów, zwracającą listę
  # Do wynikowej listy trafiają elementy, które powtarzają się we wszystkich parametrach przekazanych do funkcji, np. ([1,2,3], (1,3,5), [3,2]) -> [3], ([1,2,3], (1,3,5), [3,2,1]) -> [1,3].
  # Proszę użyć konstrukcji for-else (2p)
  print("\n --- Zadanie 2 ---")
  print(zad2([1,2,3], (1,3,5), [3,2]))
  print(zad2([1,2,3], (1,3,5), [3,2,1]))

  # Proszę napisać funkcję przyjmującą dwie sekwencje i parametr z wartością domyślną True
  # Funkcja zwraca listę dwuelementowych krotek zawierających elementy o tych samych indeksach z obu sekwencji. 
  # Jeżeli wartość trzeciego parametru wynosi True, długość zwracanej listy równa jest długości krótszej z przekazanych sekwencji, w przeciwnym wypadku brakujące elementy w krotkach uzupełniamy wartością None. 
  # Budowanie każdej z wynikowych list jedna linijka, proszę nie używać funkcji wbudowanych! (2p)
  print("\n --- Zadanie 3 ---")
  print(zad3([1,2,3,4],[7,6,5,4,3,2,1]))
  print(zad3([1,2,3,4],[7,6,5,4,3,2,1],False))  

  # Proszę napisać funkcję umożliwiającą rozmienienie kwoty pieniędzy przekazanej jako jej pierwszy parametr nominałami określonymi poprzez drugi parametr - wartość domyślna krotka (10,5,2) (algorytm zachłanny).
  # Proszę sprawdzić działanie funkcji przekazując inny zestaw monet (2p)
  print("\n --- Zadanie 4 ---")
  zad4(32)
  zad4(37)
  zad4(36)
  zad4(36,(10,3))
  
  # Proszę napisać funkcję przyjmującą cztery parametry: liczba całkowita, której wartość zgadujemy, granice przedziału, w którym szukana liczba się mieści i ostatni określający sposób poszukiwania wartości z wartością domyślną 'r'.
  # Przy wartości domyślnej ostatniego parametru, liczby poszukujemy losując kolejną wartość, w innym przypadku poszukujemy wartości poprzez podział przedziału poszukiwania wartości na pół.
  # W obu przypadkach w każdym kroku odpowiednio zawężamy przedział poszukiwania (proszę wykorzystać operator trójargumentowy).
  # Proszę sprawdzić ile kroków jest potrzebnych do znalezienia szukanej wartości w zależności od metody (2p)
  print("\n --- Zadanie 5 ---")
  zad5(17,0,26)
  zad5(4,0,26,'b')
  zad5(17,0,26,'b')

def zad1(str):
  re = []
  # trans = s.maketrans("zxcvbnmasdfghjklqwertyuiop","{}".format(random.randint(0,10)))
  # s = s.translate(trans)

  a = random.randint(0,10)
  b = random.randint(0,10)
  c = random.randint(0,10)
  d = random.randint(0,10)
  e = random.randint(0,10)
  f = random.randint(0,10)
  g = random.randint(0,10)
  h = random.randint(0,10)
  i = random.randint(0,10)
  j = random.randint(0,10)
  k = random.randint(0,10)
  l = random.randint(0,10)
  m = random.randint(0,10)
  n = random.randint(0,10)
  o = random.randint(0,10)
  p = random.randint(0,10)
  r = random.randint(0,10)
  s = random.randint(0,10)
  t = random.randint(0,10)
  u = random.randint(0,10)
  v = random.randint(0,10)
  w = random.randint(0,10)
  y = random.randint(0,10)
  z = random.randint(0,10)

  for iter in range(10):
    x = random.random()
    fun = eval(str)
    re.append((x,fun))
  return(re)



def zad2(*s):
  r = s[0]
  l = len(s)
  for i in range(1,l):
    r = list(set(r).intersection(s[i]))
  print(s)
  return(r)



def zad3(s1, s2, param=True):
  r = []
  if(param):
    l = len(s1) if len(s1) < len(s2) else len(s2) 
    r = [(s1[i],s2[i]) for i in range(l)]
  else:
    l = len(s1) if len(s1) > len(s2) else len(s2) 
    r = [(s1[i] if i < len(s1) else None,s2[i] if i < len(s2) else None) for i in range(l)]
  return(r)



def zad4(kwota,nominaly=(10,5,2)):
  ind = 0
  lm = []
  while(True):
    if(kwota <= 0 or ind >= len(nominaly)):
      break
    if(kwota >= nominaly[ind]):
      lm.append(nominaly[ind])
      kwota -= nominaly[ind]
    else:
      ind += 1
  print(lm)



def zad5(l,min,max,typ='r'):
  il_kr = 0
  while(True):
    los = random.randint(min,max) if typ=='r' else (max+min)//2
    il_kr += 1
    if (los == l):
      break
    if(l > los):
      min = los
    elif(l < los):
      max = los
  print("Randomowa? : {} il.krokow: {}".format(typ=='r',il_kr))


if __name__ == "__main__":
  main()
