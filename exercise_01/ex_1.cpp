#include <iostream>
#include <string>

class grade
{
public:
    grade(int score) {
        if(score >= 90) _desc = "A";
        else if(score >= 80) _desc = "B";
        else if(score >= 70) _desc = "C";
        else if(score >= 60) _desc = "D";
        else _desc = "F";
    }
    void print(std::ostream& ostream) const {
        ostream << "you scored: " << _desc << "!" << std::endl;
    }
private:
    std::string _desc;
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Give one score!" << std::endl;
        return 1;
    }
    int score = 0;
    try {
        // string to int conversion: std::stoi is in c++11
        score = std::stoi(std::string(argv[1]));
    } catch (std::exception& e) {
        std::cout << "lexical cast failed: " << e.what() << std::endl;
        return 1;
    }
    grade gr(score);
    gr.print(std::cout);
    return 0;
}

