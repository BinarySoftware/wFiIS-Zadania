import copy

class Tablica:
  def __init__(self, size, elems):
    try:
      if(len(elems) > size):
        raise
      else:
        self.size = size
        self.elems = copy.deepcopy(elems)
        print("Stworzono tablice.")
    except:
      print("Za duzo elementow.")
  
  def __add__(self, elem2):
    newTab = Tablica(self.size, self.elems)
    newTab.elems.append(elem2)
    return newTab
  
  def __iadd__(self, elem2):
    self.elems.append(elem2)
    return self
  
  def __getitem__(self, index):
    return self.elems[index]
  
  def __setitem__(self, index, elem):
    self.elems[index] = elem

  def hasCorrectSize(self):
    return self.size <= len(self.elems)
  
  def show(self):
    print("[",end="")
    for i in range(self.size if (self.size <= len(self.elems)) else len(self.elems)):
      print(self.elems[i], end = ', ')
    print("]")
  