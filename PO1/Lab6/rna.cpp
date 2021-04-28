#include "rna.h"
#include <algorithm>

std::ostream& operator<<(std::ostream& out, const RNA & seq_){
  for(int elem:seq_.chain) {
    out << (char)elem << " ";
  }
  out << "\n";
  return out;
}

RNA & RNA::mutate(){
  std::rotate(chain.begin(), chain.begin()+1, chain.end());
  return *this;
}
