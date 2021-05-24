
def sprawdz(pesel, urodziny, plec):
  try:
    if (len(pesel) != 11):
      raise ValueError("Niepoprawna dlugosc PESEL.")
    d = pesel[0:2]
    m = pesel[2:4]
    r = pesel[4:6]
    lp = pesel[6:10]
    sk = pesel[10]

    d_ur = int(urodziny.split("-")[0])
    m_ur = int(urodziny.split("-")[1])
    r_ur = int(urodziny.split("-")[2])

    if (check_year(m,m_ur,r_ur) == False):
      raise ValueError("Niepoprawny miesiac w PESEL.")
    if(int(d) != d_ur):
      raise ValueError("Niepoprawny dzien urodzin.")
    if(int(r) != int(urodziny.split("-")[2][2:4])):
      raise ValueError("Niepoprawny rok urodzin.")
    if((int(lp)%2 == 1 and plec=='K') or (int(lp)%2 == 0 and plec=='M')):
      raise ValueError("Niepoprawna plec.")
    
    ske = (int(pesel[0])*1 + int(pesel[1])*3 + int(pesel[2])*7 + int(pesel[3])*9 + int(pesel[4])*1 + int(pesel[5])*3 + int(pesel[6])*7 + int(pesel[7])*9 + int(pesel[8])*1 + int(pesel[9])*3) % 10
    ske = (10 - ske)%10
    if (int(sk) != ske):
      raise ValueError("Niepoprawna suma kontrolna.")
    else:
      print("Wszystko ok:")
      print(d, m, r, lp, sk)

  except ValueError as e:
    print(e)

def check_year(m,m_ur,r_ur):
  baza = 0
  if (r_ur >= 1800 and r_ur < 1900):
    baza = 0
  elif (r_ur >= 2000 and r_ur < 2100):
    baza = 20
  elif (r_ur >= 2100 and r_ur < 2200):
    baza = 60
  elif (r_ur >= 2200 and r_ur < 2300):
    baza = 80
  
  if(baza + m_ur == int(m)):
    return True
  return False