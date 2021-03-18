#!/usr/bin/env python3
import sys

def main():
  """
  Program entry point.
  """
  args = sys.argv[1:]
  numArg = len(args)

  if numArg <= 0:
    print("Nie podano argumentow.")
    exit(1)
  
  joinedStr = ''.join(args)
  print(joinedStr)

  bigLetters = list(filter(str.isupper, joinedStr))
  smallLetters = list(filter(str.islower, joinedStr))
  ints = list(filter(str.isdigit, joinedStr))
  nonLetters = [c for c in joinedStr if not c.isalnum()]

  print(bigLetters)
  print(smallLetters)
  print(ints)
  print(nonLetters)

  uniqueElems = set(smallLetters)
  print(uniqueElems)

  krotka = [(el, smallLetters.count(el)) for el in uniqueElems]
  print(krotka)

  krotka.sort(key = lambda x: x[1], reverse = True)
  print(krotka)

  letters = list(filter(str.isalpha, joinedStr.lower()))
  samo = ['a','e','i','o','u','y']
  ileSamo = sum(letters.count(el) for el in samo)
  ileSpol = len(letters) - ileSamo
  krotka = [(float(x), float(ileSamo*int(x)+ileSpol)) for x in ints]
  print(krotka)

  avgx = sum(i for i,v in krotka) / len(krotka)
  avgy = sum(v for i,v in krotka) / len(krotka)

  D = sum(pow((i-avgx),2) for i,v in krotka)
  a = sum(v * (i-avgx) for i,v in krotka)
  
  a = (1.0/D) * a
  b = avgy - a * avgx

  print ("D: ", D)
  print ("a: ", a)
  print ("b: ", b)

if __name__ == "__main__":
  main()