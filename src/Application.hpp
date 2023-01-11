#include <string>
#include <vector>
#include <iostream>

#include <chrono>    //needed for wait
#include <thread>  

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

using String = std::string;
using std::vector;


#ifndef ENTITY
#define ENTITY
class Entity 
{
private:
    bool _state = false;
    int _posX = 0;
    int _posY = 0;

public:
    Entity(int x,  int y): _posX(x), _posY(y){}
    Entity() = default;

    void SetPoss(int x, int y){_posX = x; _posY = y;}
    void SetState(bool st){_state = st;}
    bool GetState(){return _state;}
    vector<int> GetPoss(){
        vector<int> vi {_posX, _posY};
        return vi;
    }
};

#endif

#ifndef FIELD 
#define FIELD 
class Field  
{
private:
    int _rows = 0;
    int _cols = 0;
    
    vector<vector<Entity>> _cells;

public:
    Field(int, int );

    int GetRows() {return _rows; }
    int GetCols() {return _cols; }
    void PrintField(String, String);
    void PrintField();
};

#endif

#ifndef WINDOW 
#define WINDOW
class Window
{
private:
    int _height;
    int _width;
    String _deadCell;
    String _aliveCell;

    Field* _pFieldA = nullptr;
    Field* _pFieldB = nullptr;

public:
    Window(int, int, String, String);
    ~Window();   

    Field* GetFieldA() {return _pFieldA; };
    Field* GetFieldB() {return _pFieldB; };
};

#endif
