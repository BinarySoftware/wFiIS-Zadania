import zad_1
import zad_2
import zad_3
import math

def f(x):
  return math.sin(x)

def g(x):
  return math.sin(x) - (0.5*x)**2

def scale(x):
  return (x/2**48)*math.pi - math.pi/2.0

def main():
  ciag1 = zad_1.ciag_1(2,5)
  for i in range(10):
    print(ciag1)
    next(ciag1)
  print()

  ciag2 = zad_1.ciag_2(2,5,50)
  for i in ciag2:
    print(i)
  print()

  integral_iter = zad_2.iter(44485709377909,2**48,0,1)
  t = 0
  n = 1
  area = math.pi*2
  while True:
    n += 1
    next(integral_iter)
    x = scale(integral_iter.x)
    fx = f(x)
    y = math.sin(scale(next(integral_iter)))
    print(f'x:{x} f(x):{fx} y:{y} t:{t} n:{n}')
    prev_int = area*t/(n-1)
    if (y > 0 and 0 < y <= fx):
      t += 1
    if (y < 0 and 0 > y >= fx):
      t -= 1
    if abs((area*t/n) - prev_int) < 1e-7:
      break
  print(f'Ilosc iteracji: {n}')

  print()

  newt_rhap = zad_3.iter(g, 1.5, 1e-5)

  for i in newt_rhap:
    print(i)



if __name__ == "__main__":
  main()