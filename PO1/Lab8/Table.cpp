#include "Table.h"
#include <iostream>
#include <algorithm>

void Table::operator +=(const Expense & e){
  expenses.push_back(e);
}

void Table::print() const{
  std::for_each(expenses.begin(), expenses.end(), [](Expense e){
    e.print();
  });
  std::cout << std::endl;
}

Table & Table::sort(unsigned int i){
  unsigned int min_len = expenses[0].size();
  for (Expense e : expenses){
    if (e.size() < min_len){ min_len = e.size(); }
  }

  if (i < min_len){
    std::sort(expenses.begin(), expenses.end(), [i](Expense e1, Expense e2){
      return e1.at(i) < e2.at(i);
    });
  } else {
    std::cout << "Indeks " << i << " nieprawidlowy!" << std::endl;
  }
  return *this;
}

Table & Table::sortByMean(){
  std::sort(expenses.begin(), expenses.end(), [](Expense e1, Expense e2){
    return e1.mean() < e2.mean();
  });
  return *this;
}
