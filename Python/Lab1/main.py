#!/usr/bin/env python3
# import this
import keyword
import math
import copy


def main():
  """
  Program entry point.
  """
  print("Hello, Wonsz")
  print()
  print(keyword.kwlist)
  print()

  wypiszTypy()

  a = Animal("Null")
  print(a)

  dog = Dog(12)
  print(dog)
  dog.addName("Azor")
  dog.addName("Burek")
  print(dog.names)
  
  print()

  rown(1,2,0)
  rown(1,2,1)
  print()

  demoKopiowanieListy()


def demoKopiowanieListy():
  k = [1,2,'3',(4,5),[6,7,8]]
  cp = k # plytka kopia - referencja
  cp[1]=[9,0]
  print("cp: " + str(cp))
  print("k: " + str(k))
  print(id(cp),id(k))
  print()

  cp = k[:] # [:] - wycinek listy
  cp[1]=[6,9]
  k[0]=42
  print("cp: " + str(cp))
  print("k: " + str(k))
  print(id(cp),id(k))
  print()

  cp = copy.deepcopy(k) # Gleboka kopia listy
  cp[1]=[0,1,4,9]
  print("cp: " + str(cp))
  print("k: " + str(k))
  print(id(cp),id(k))


def wypiszTypy():
  a=7
  print(type(a))
  a=2.3
  print(type(a))
  a=complex(2,3)
  print(type(a))
  a=[2.3]
  print(type(a))
  a={2.3}
  print(type(a))
  a={2:3}
  print(type(a))
  a=1,2
  print(type(a))
  a='a'
  print(type(a))
  a=True
  print(type(a))
  print()


def rown(a,b,c):
  delta = b^2 + 4*a*c
  if a == 0:
    return
  
  if delta < 0:
    print("brak pierwiastkow.")
  elif abs(delta) < 1e-6:
    print("x0 = " + str(-b/(2*a)))
  else:
    print("x1 = " + str((-b -math.sqrt(delta)) / (2*a)) )
    print("x2 = " + str((-b +math.sqrt(delta)) / (2*a)) )


class Animal:
  def __init__(self, kind:str):
    self.kind = kind
  def __repr__(self):
    return "Animal(" + self.kind + ")"
  def __str__(self):
    return "member of Animal with kind of " + self.kind

class Dog(Animal):
  legs = 4

  names = []

  def __init__(self, age: int):
    super().__init__("Dog")
    self.age = age
  def __str__(self):
    return "Dog of age " + str(self.age)
  def addName(self, n):
    self.names.append(n)
  

if __name__ == "__main__":
  main()