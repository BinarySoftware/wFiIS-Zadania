

'''
Implementacja 'Game Of Life' Johna Conway'a.
'''
class automata:
  def __init__(self, grid_size, alive_size, iterations):
    '''
    Inicjalizacja klasy, tworzy tablice komorek.
    '''
    self.grid_size = grid_size
    self.iterations = iterations

    self.grid = [ [0] * grid_size for _ in range(grid_size)]
    for i in range(alive_size):
      for j in range(alive_size):
        if (i < self.grid_size and j < self.grid_size):
          self.grid[i][j] = 1
  
  def evolve(self):
    '''
    Tworzy nowa generacje komorek na podstawie poprzedniej.
    '''
    for i in range(self.grid_size):
      for j in range(self.grid_size):
        count_alive = 0
        for x in range(i-1, i+2):
          for y in range(j-1, j+2):
            a = x
            if (x < 0):
              a = self.grid_size-1
            if (x >= self.grid_size):
              a = 0
            b = y
            if (y < 0):
              b = self.grid_size-1
            if (y >= self.grid_size):
              b = 0

            if (self.grid[a][b] == 1 and not (a == i and b == j)):
              count_alive += 1; 
        if (count_alive == 3 and self.grid[i][j] == 0):
          self.grid[i][j] = 1
        elif (count_alive != 2 and count_alive != 3 and self.grid[i][j] == 1):
          self.grid[i][j] = 0
  
  def show(self):
    '''
    Pokazuje zycie na ekranie.
    '''
    for i in range(self.grid_size):
      for j in range(self.grid_size):
        print("*",end='') if (self.grid[i][j] == 1) else print(" ",end='')
      print()
  
  def run(self):
    '''
    Odpala program przeprowadzajac zadana ilosc ewolucji.
    '''
    for i in range(self.iterations):
      print(f'\n\nEwolucja: {i}')
      self.show()
      self.evolve()
    print(f'\n\nEwolucja: {self.iterations}')
    self.show()
