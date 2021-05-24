import game_of_life
import tablica

def zad1():
  a1 = game_of_life.automata(30,10,5)
  a2 = game_of_life.automata(30,11,10)
  a3 = game_of_life.automata(30,10,20)
  a4 = game_of_life.automata(30,13,100)

  a1.run()
  a2.run()
  a3.run()
  a4.run()

def main():
  zad1()

  tablica.Tablica(2, [1,2,3])
  t1 = tablica.Tablica(4, [1,2,3])
  t1.show()
  t1 += 66
  t1.show()
  t1.size = 5
  t2 = t1 + 666
  t1.show()
  t2.size = 10
  t2 += 10
  print(t2[0])
  t2[0] = 90909
  t2.show()
  t1.show()

if __name__ == "__main__":
  main()