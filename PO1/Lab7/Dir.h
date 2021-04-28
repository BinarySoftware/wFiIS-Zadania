#pragma once

#include <iostream>
#include <vector>
#include "File.h"

class Dir final : public File {
  public:
    Dir(std::string name): File(name){};
    ~Dir();

    void copy(File * f);
    void operator+=(File * f);
    void operator-=(std::string s);

    Dir * getDir(std::string s);
    File * get(std::string s);

    friend std::ostream & operator<<(std::ostream & o, Dir const & d){
      o << d.name << "(dir)\n";
      for(File * f : d.tree){
        if (typeid(*f) == typeid(Dir)){
          Dir * dt = (Dir *)f;
          o << *dt;
        } else {
          o << *f;
        }
      }
      return o;
    }
  int indent_level = 0;
  protected:
    std::vector<File *> tree;
};