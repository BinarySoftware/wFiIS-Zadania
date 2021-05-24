
class iter:
  def __init__(self, a, m, c, x0):
    self.a = a
    self.m = m
    self.c = c
    self.x = x0
  
  def __iter__(self):
    return self

  def __next__(self):
    self.x = (self.a * self.x + self.c) % self.m
    return self.x
  
  def __str__(self):
    return f'{self.x}'