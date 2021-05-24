#include "Expense.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void Expense::print() const {
  std::cout << day << ":";
  std::for_each(exp.begin(), exp.end(), [](double d){
    std::cout << "\t\t" << d;
  });
  std::cout << std::endl;
}

double Expense::mean() const {
  return std::accumulate(exp.begin(), exp.end(), 0.0)/exp.size();
}

double Expense::at(int i) const {
  return exp[i];
}

unsigned int Expense::size() const {
  return exp.size();
}
