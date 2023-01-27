#include <string>
#include <vector>

#include <chrono>    //needed for WAIT
#include <thread>  

#include <cstdlib>  //needed for system("CLS")

using std::vector;
using std::string;
using size_type =  std::string::size_type;

#define WAIT(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

class Field {
    friend class Game; 
public: 
    Field() = default;
    Field(size_type wd, size_type ht, string alCel, string deCel): _width(wd), _height(ht), 
                                            _elements(_width * _height, 0),
                                            _deadCell(deCel), _aliveCell(alCel) {}; 

    inline bool get() const {return _elements[_cursor]; }
    inline bool getWidth() const {return _width; }
    inline bool getHeight() const {return _height; }
    Field &change(bool value);
    Field &move_of (int v);
    Field &move (size_type c, size_type r);
    Field &reset ();

    void display(std::ostream &os) ;

private:
    size_type _cursor = 0;
    size_type _width = 0, _height = 0;
    string _deadCell, _aliveCell;

    vector<bool> _elements;
};

class Game{
public:

    static bool CheckAdjacent(Field* permaField, int index, vector<bool>& tempField);
    static void Evaluate(Field* field);
    static void Run(Field* field, size_type duration, int waitTime, std::ostream &os); 
};
