
class ciag_1:
  def __init__(self, a0, d):
    self.a = a0
    self.d = d
  
  def __iter__(self):
    return self

  def __next__(self):
    self.a += self.d
    return self.a
  
  def __str__(self):
    return f'{self.a}'

class ciag_2:
  def __init__(self, a0, d, a_max):
    self.a = a0
    self.d = d
    self.max = a_max
  
  def __iter__(self):
    return self

  def __next__(self):
    self.a += self.d
    if self.a < self.max:
      return self.a
    raise StopIteration
  
  def __str__(self):
    return f'{self.a}'

