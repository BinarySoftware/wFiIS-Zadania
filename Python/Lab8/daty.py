import datetime

def avgAge(inFileName, restrictive=False):
  poprawne = []
  try:
    with open(inFileName) as daty:
      for data in daty.readlines():
        data = data.replace('\n','').split(' ')
        if (len(data) == 3):
          d = int(data[0])
          m = int(data[1])
          r = int(data[2])
          if (m > 0 and m < 13 and d > 0 and d < 32):
            if(czy_przestepny(r) and m == 2 and d == 29):
              poprawne.append(datetime.date(r,m,d))
            elif((m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) and d < 32):
              poprawne.append(datetime.date(r,m,d))
            elif((m == 2) and d < 29):
              poprawne.append(datetime.date(r,m,d))
            elif((m != 2) and d < 31):
              poprawne.append(datetime.date(r,m,d))
          elif (restrictive):
            raise ValueError("Niepoprawna data.")
        elif (restrictive):
          raise ValueError("Niepoprawna data.")
  except ValueError as e:
    print(e)
    return

  today = datetime.date.today()
  tab_wiek = list(map(lambda d: today - d, poprawne))
  tab_wiek = list(map(lambda d: d.days/365, tab_wiek))
  avg = sum(tab_wiek)/len(tab_wiek)
  print(avg)


def czy_przestepny(rok) -> bool:
  return ((rok%4 == 0 and rok%100 != 0) or (rok%400 == 0))