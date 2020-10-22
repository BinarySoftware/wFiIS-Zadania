#include <iostream>
#include <stdlib.h>

using namespace std;

const int * initFibonacci(int len){
  int * tab = new int[len+1];
  tab[0] = 0;
  tab[1] = 1;
  for (int i = 2; i <= len; i++){
    tab[i] = tab[i-1] + tab[i-2];
  }
  return tab;
}

void print(const int * sequence, int abs_n){
  cout << "(";
  for (int i = 0; i <= abs_n; i++) {
    cout << sequence[i];
    if (i<abs_n){
      cout << ",";
    }
  }
  cout << ")" << endl;
}

void deleteSequence(const int * sequence){
  delete[] sequence;
}

void addSequence(int * numberOfSequences, int *** sequencesList, int ** sequencesLength, int newLength){
  (*numberOfSequences)++;

  if((*numberOfSequences) == 1){
    *sequencesLength = (int*)malloc(sizeof(int)*(*numberOfSequences));
  } else {
     *sequencesLength = (int*)realloc(*sequencesLength, sizeof(int)*(*numberOfSequences));
  }
  (*sequencesLength)[*numberOfSequences - 1] = abs(newLength);

  int* fib = (int*) initFibonacci(abs(newLength));
  if((*numberOfSequences) == 1){
    *sequencesList = (int**)malloc(sizeof(int*)*(*numberOfSequences));
  } else {
     *sequencesList = (int**)realloc(*sequencesList, sizeof(int*)*(*numberOfSequences));
  }
  (*sequencesList)[*numberOfSequences - 1] = fib;
}

void printAllSequences(int ** sequencesList, int * sequencesLenght,int numberOfSequences){
  for (int i = 0; i < numberOfSequences; i++){
    cout << "ciag " << i << ": ";
    print(sequencesList[i], sequencesLenght[i]);
  }
}

/////////////////// BROKEN /////////////////////////
void removeSequence(int * numberOfSequences, int *** sequencesList, int ** sequencesLength, int n){
  delete[] (*sequencesList)[n];
  delete sequencesLength[n];
  for (int i = n; i < *numberOfSequences; i++){
    (*sequencesList)[i] = (*sequencesList)[i+1];
    (*sequencesLength)[i] = (*sequencesLength)[i+1];
  }
  (*numberOfSequences)--;
}

/////////////////// BROKEN /////////////////////////
void deleteSequences(int * numberOfSequences, int *** sequencesList, int ** sequencesLength){
  for (int i = 0; i < *numberOfSequences; i++) {
    delete[] (*sequencesList)[i];
    delete sequencesLength[i];
  }
  delete numberOfSequences;
}
