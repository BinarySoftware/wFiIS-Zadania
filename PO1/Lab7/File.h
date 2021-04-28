#pragma once

#include <iostream>
#include <string>

static int indent_level = 4;

class File {
  public:
    File(std::string n): name(n), size(0) {};
    File(std::string n, int s): name(n), size(s) {};
    virtual ~File() = default;

    friend std::ostream & operator<<(std::ostream & o, File const & f){
      for(int i=0; i<indent_level; i++){
        o << " ";
      }
      o << f.name << "(" << f.size << ")\n";
      return o;
    }

    std::string name;
    int size;

};