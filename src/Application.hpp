#include <cstdio>
#include <ostream>
#include <string>
#include <vector>
#include <iostream>

#include <chrono>    //needed for WAIT
#include <thread>  

using std::vector;
using std::string;
using size_type =  std::string::size_type;

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

class Field {
public: 
    Field() = default;
    Field(size_type wd, size_type ht, string alCel, string deCel): _width(wd), _height(ht), 
                                            _elements(_width * _height, 0),
                                            _deadCell(deCel), _aliveCell(alCel) {}; 

    inline bool get() const {return _elements[_cursor]; }
    Field &move ();
    Field &move (size_type r, size_type c);

    void display(std::ostream &os) ;

private:
    size_type _cursor = 0;
    size_type _width = 0, _height = 0;
    string _deadCell, _aliveCell;

    vector<bool> _elements;
};

