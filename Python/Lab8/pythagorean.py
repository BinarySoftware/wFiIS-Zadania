
def posiadaTrojkiCzworki(l):
  try:
    if (len(l)%4 != 0 and len(l)%3 != 0):
      raise ValueError("Niepoprawna dlugosc listy.")
  except ValueError as e:
    print(e)
  
  s = 3
  czy_ma = False

  if (len(l)%3 == 0 and len(l)%4 == 0):
    s == -1
    c1 = [l[i*3:(i+1)*3] for i in range((len(l)+3-1)//3)]
    c2 = [l[i*4:(i+1)*4] for i in range((len(l)+4-1)//4)]

    for i in c1:
      if (s == 3 and len(i) == 3):
        if (i[0]**2 + i[1]**2 == i[2]**2):
          czy_ma = True
          print_parz_nparz(i)
    for i in c2:
      if(s == 4 and len(i) == 4):
        if (i[0]**2 + i[1]**2 + i[2]**2 == i[3]**2):
          czy_ma = True
          print_parz_nparz(i)
  elif (len(l)%4 == 0):
    s = 4
  
  if (s != -1):
    c = [l[i*s:(i+1)*s] for i in range((len(l)+s-1)//s)]

    for i in c:
      if (s == 3 and len(i) == 3):
        if (i[0]**2 + i[1]**2 == i[2]**2):
          czy_ma = True
          print_parz_nparz(i)
      elif(s == 4 and len(i) == 4):
        if (i[0]**2 + i[1]**2 + i[2]**2 == i[3]**2):
          czy_ma = True
          print_parz_nparz(i)
  
  try:
    if (czy_ma == False):
      raise ValueError("Nie ma trojki ani czworki pitagorejskiej.\n")
    else:
      print("Znaleziono czworke lub trojke w liscie.\n")
  except ValueError as e:
    print(e)


def print_parz_nparz(i):
  parz = []
  nparz = []
  for a in i:
    if (a%2 == 1):
      nparz.append(a)
    else:
      parz.append(a)
  print(f"Parzyste: {parz}")
  print(f"Niearzyste: {nparz}")
