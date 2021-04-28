import math

def expXsquare(x):
  return math.exp(-x**2)

def cheb(min,max,m,n):
  return 0.5 * ((max - min) * math.cos(math.pi * ((2.0 * float(m) + 1.0) / (2.0 * float(n) + 2.0))) + (min + max))

def setPlacement(x,y,size,x_min,x_max):
  for i in range(size+1):
    x[i] = x_min + ((x_max-x_min)/float(size)*i)
    y[i] = expXsquare(x[i])
    print(f"{x[i]} {y[i]}")
  
def setPlacementCheb(x,y,size,x_min,x_max):
  for i in range(size+1):
    x[i] = cheb(x_min, x_max, i, size)
    y[i] = expXsquare(x[i])
    print(f"{x[i]} {y[i]}")

def lagrange(wezel,wartosc,stopien, x_min):
  w = 0.0
  omega = 1.0;
  for i in range(stopien+1):
    for j in range(stopien+1):
      if(i != j):
        omega *= (x_min-wezel[j])/(wezel[i]-wezel[j])
    w += wartosc[i] * omega;
    omega = 1.0
  return w;

def compute(x,y,size,x_min,f):
  for i in range(100):
    w_n = lagrange(x,y,size,x_min)
    f.write(f"{x_min} {w_n} \n")
    x_min += 0.1
  f.write("\n\n")

def main():
  x_min = -5
  x_max = 5

  n = [5, 10, 15, 20]

  x_n1 = [0] * (n[0]+1)
  x_n2 = [0] * (n[1]+1)
  x_n3 = [0] * (n[2]+1)
  x_n4 = [0] * (n[3]+1)

  y_n1 = [0] * (n[0]+1)
  y_n2 = [0] * (n[1]+1)
  y_n3 = [0] * (n[2]+1)
  y_n4 = [0] * (n[3]+1)

  setPlacement(x_n1,y_n1,n[0], x_min, x_max)
  setPlacement(x_n2,y_n2,n[1], x_min, x_max)
  setPlacement(x_n3,y_n3,n[2], x_min, x_max)
  setPlacement(x_n4,y_n4,n[3], x_min, x_max)

  new_x_min = x_min
  f = open("zad_1.dat", "a")
  compute(x_n1,y_n1,n[0], new_x_min, f)
  compute(x_n2,y_n2,n[1], new_x_min, f)
  compute(x_n3,y_n3,n[2], new_x_min, f)
  compute(x_n4,y_n4,n[3], new_x_min, f)
  f.close()

  setPlacementCheb(x_n1,y_n1,n[0], x_min, x_max)
  setPlacementCheb(x_n2,y_n2,n[1], x_min, x_max)
  setPlacementCheb(x_n3,y_n3,n[2], x_min, x_max)
  setPlacementCheb(x_n4,y_n4,n[3], x_min, x_max)

  f = open("zad_2.dat", "a")
  compute(x_n1,y_n1,n[0], new_x_min, f)
  compute(x_n2,y_n2,n[1], new_x_min, f)
  compute(x_n3,y_n3,n[2], new_x_min, f)
  compute(x_n4,y_n4,n[3], new_x_min, f)
  f.close()

if __name__ == "__main__":
  main()