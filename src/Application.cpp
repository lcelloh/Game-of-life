#include "Application.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <ostream>

const size_type N_GEN = 30;

const size_type HEIGHT = 20; 
const size_type WIDTH = 20; 

const string blackBlock = "\u25a1";
const string whiteBLock = "\u25a0";

int main (int argc, char *argv[])
{
    Field field(WIDTH, HEIGHT, whiteBLock, blackBlock); 
    Game::Run(&field, N_GEN, 1 , std::cout);

    std::cout << std::endl;
    return 0;
}

Field &Field::change(bool value)
{
    _elements[_cursor] = value;
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

bool Game::CheckAdjacent(Field* permaField,int index, vector<bool>& tempField)
{
    size_type nearAlive = 0; 
    size_type fWidth = 20; 

    bool state = tempField[index];

    if ((index - 1) >= 0 && ((index -1) % fWidth ) !=0) {         //element line check
        if(tempField[index - 1]) 
        nearAlive++;
    }
    if((index % fWidth) != 0 && index < tempField.size()){
        if(tempField[index + 1]) 
        nearAlive++;
    }

    if (((index - fWidth) - 1) >= 0 && ((index -1) % fWidth ) !=0) {         //previous line check
        if(tempField[((index - fWidth) - 1)] ) 
            nearAlive++;
    }
    if((index % fWidth) !=0 && index - fWidth >= 0){
        if(tempField[index - fWidth + 1]) 
        nearAlive++;
    }
    if(index - fWidth >= 0 ){
        if(tempField[index - fWidth])
            nearAlive++;
    }

    if (((index + fWidth) - 1) < tempField.size() && (((index -1) % fWidth ) !=0)) {         //next line check
        if(tempField[((index + fWidth) - 1)] ) 
            nearAlive++;
    }
    if(((index  % fWidth) !=0) && ((index + fWidth) < tempField.size())){
        if(tempField[(index + fWidth) + 1]) 
            nearAlive++;
    }
    if((index + fWidth) < tempField.size()){
        if(tempField[index + fWidth])
            nearAlive++;
    }

    if(state){
        if(!(nearAlive >= 2 && nearAlive <= 3)){
            state = false;
        }
    }else if (!state){
        if(nearAlive == 3){
            state = true;
        }
    }

    return state;
}

void Game::Evaluate(Field *field)
{
    vector<bool> copyElements = field->_elements;

    for(size_type i = 0; i <(field->_height * field->_width); i++){
        bool state = CheckAdjacent(field, i , copyElements);
        field->_elements[i] = state;
    }
}


void Game::Run(Field *field, size_type duration, int waitTime, std::ostream &os){
   
    field->move_of(145).change(true).move_of(1).change(true).move_of(1).change(true).move(6,6).change(true);// .move_of(19).change(true).move_of(1).change(true);

    field->display(os);
    std::cin.get();
    os << "\n";
    
    for(int i = 0; i < duration; i++) {
        
        field->reset();

        Evaluate(field);
        // system("clear");
        field->display(os);
                
        os << "\n";
        os << "Number of generation: " << i;
        os << "\n";
        WAIT(waitTime * 500);
    }
}

