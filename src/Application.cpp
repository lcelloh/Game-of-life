#include "Application.hpp"
#include <iostream>

const size_type HEIGHT = 20; 
const size_type WIDTH = 20; 

const string blackBlock = "\u25a1";
const string whiteBLock = "\u25a0";

int main (int argc, char *argv[])
{
    Field field(WIDTH, HEIGHT, whiteBLock, blackBlock); 
    field.display(std::cout);

    return 0;
}

Field &Field::move()
{       
    _cursor += 1;
    return *this;
}

void Field::display(std::ostream &os) 
{
    for(size_type i = 0; i <(_height * _width); i++) {
        os << _elements[_cursor] << " ";
        this->move();
        if (i % _width == 0){
           os << "\n";
        }
    }
}        
