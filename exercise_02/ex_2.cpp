#include <iostream>
#include <string>
#include <exception>

class IndexOutOfBounds: std::exception
{
public:
    const char* what() const noexcept {
        return "Index out of bounds";
    }
};

class TicTacToeArray
{
    enum Owner: unsigned char { X='X', O='O', None=' ' };
    static const std::size_t nRows = 3;
    static const std::size_t nCols = 3;
public:
    TicTacToeArray(): array(nRows*nCols, (char)None) {}
    void print(std::ostream& stream) {
        for(int i=0; i < nRows; ++i) {
            stream << array.substr(i*nCols, nCols) << std::endl;
        }
    }
    void setX(std::size_t row, std::size_t col) {
        set(Owner::X, row, col);
    }
    void setO(std::size_t row, std::size_t col) {
        set(Owner::O, row, col);
    }
private:
    void set(Owner o, std::size_t row, std::size_t col) {
        if(row >= nRows || col >= nCols) throw IndexOutOfBounds();
        array[row*nCols + col] = o;
    }
    std::string array;
};

int main(int argc, char** argv)
{
    TicTacToeArray arr;
    arr.setX(1,1);
    arr.setO(1,0);
    arr.setX(2,1);
    arr.setO(0,1);
    arr.setX(0,2);
    arr.setO(2,0);
    arr.setX(0,0);
    arr.setO(2,2);
    arr.print(std::cout);
  return 0;
}
