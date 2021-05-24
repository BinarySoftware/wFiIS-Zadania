from scipy.misc import derivative

class iter:
  def __init__(self, f, x, e):
    self.f = f
    self.x = x
    self.e = e
  
  def __iter__(self):
    return self

  def __next__(self):
    old_x = self.x
    self.x = old_x - self.f(old_x)/derivative(self.f,old_x)
    if abs(self.x - old_x) < self.e:
      raise StopIteration
    return self.x
  
  def __str__(self):
    return f'{self.x}'