#include "Application.hpp"
#include <iostream>
#include <vector>

const int HEIGHT = 50;
const int WIDTH = 50;

const String blackBlock = "\u25a1";
const String whiteBLock = "\u25a0";


int main (int argc, char *argv[])
{
    Window window(HEIGHT, WIDTH, blackBlock, whiteBLock);

    window.GetFieldA()->PrintField();
    String tempstr; 

    std::cin >> tempstr; 
    for (int i = 0; i < 10; i++ ){
    window.GetFieldA()-> PrintField(blackBlock, whiteBLock);
    std::cout << "NUMBER OF GENERATIONS : " << i << std::endl;
    WAIT(1000);
    }
    return 0;

}

Field::Field(int r, int c)
{
    _rows = r;
    _cols = c;
    Entity e(0, 0);
    _cells.resize(_rows, vector<Entity>(_cols, e));

    int count = 0; 
    for (int i=0; i < _rows; i++){
        for (int j = 0;j < _cols; j++){
            _cells[i][j].SetPoss(j, i);
        }
    }
}

void Field::PrintField(String s1, String s2)
{
    for(auto &bvec: _cells){
        for(auto cell: bvec){
            if (cell.GetState() == false) {
                // std::cout << s1 << " ";
                for (auto c: cell.GetPoss()){
                    std::cout << c << " ";
                }
            }else {
                std::cout << s2 << " ";
            }
        }
        // _cells [HEIGHT/2][WIDTH/2] = ;
        std::cout << '\n';
    }
}

void Field::PrintField()
{
    int countr = 0;
    for(auto &bvec: _cells){
        int countc = 0;

        for(auto cell: bvec){
            if(countr == 0 || countr == (HEIGHT - 1) || countc == WIDTH - 1){
                if (countc < 10) {
                    std::cout << "0 ";
                    countc++;
                }else{
                    std::cout << "0  "; 
                }
            } 
            else{
                std::cout << countc++ << " " ;
            }
             
        }
        
        std::cout << "    line number: " << countr;  
        std::cout << '\n'; 
        ++countr;
    }
}

Window::Window(int h, int w, String deadC, String aliveC)
{
    _height = h;
    _width = w;
    _deadCell = deadC; 
    _aliveCell = aliveC;

    _pFieldA = new Field(h, w);
    _pFieldB = new Field(h, w);
}

Window::~Window()
{
    if (_pFieldA == nullptr) {
       delete _pFieldA; 

    if (_pFieldB == nullptr) {
        delete _pFieldB; 
    }
    }
}

