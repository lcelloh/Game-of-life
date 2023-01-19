#include "Application.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>

const size_type N_GEN = 5;

const size_type HEIGHT = 20; 
const size_type WIDTH = 20; 

const string blackBlock = "\u25a1";
const string whiteBLock = "\u25a0";

int main (int argc, char *argv[])
{
    Field field(WIDTH, HEIGHT, whiteBLock, blackBlock); 
    Game::Run(&field, N_GEN, 1, std::cout);

    std::cout << std::endl;
    return 0;
}

Field &Field::change()
{
    bool temp = _elements[_cursor];
    _elements[_cursor] = !temp;
    return *this;
}
Field &Field::move_of(int v)
{       
    if(_cursor - v > 0) {
        _cursor += v;
    }
    return *this;
}

Field &Field::move(size_type c, size_type r)
{       
    _cursor = r * _width;
    _cursor += c;
    return *this;
}

Field &Field::reset()
{       
    _cursor = 0;
    return *this;
}

void Field::display(std::ostream &os) 
{
    for(size_type i = 0; i <(_height * _width); i++) {

        if (i % _width == 0 && i != 0)
           os << "\n";
        if(_elements[i])
            os << _aliveCell << " ";
        else 
            os << _deadCell << " ";
    }
}        

bool Game::CheckAdjacent(bool state, size_type cursor, size_type index, vector<bool> collection)
{
    size_type nearAlive = 0; 
}

void Game::Evaluate(Field *field)
{
    vector<bool> copyElements = field->_elements;
    size_type *pCursor = &(field->_cursor);

    for(size_type i = 0; i <(field->_height * field->_width); i++){
        if(copyElements[i]){
            
        }else if (!copyElements[i]) {
        
        }
    }
}


void Game::Run(Field *field, size_type duration, int waitTime, std::ostream &os){
    
    field->display(os);
    std::cin.get();
    os << "\n";
    
    for(int i = 0; i < duration; i++) {
        
        field->reset();
        Evaluate(field);
        system("clear");
        field->display(os);
                
        os << "\n";
        os << "Number of generation: " << i;
        os << "\n";
        WAIT(waitTime * 1000);
    }
}

