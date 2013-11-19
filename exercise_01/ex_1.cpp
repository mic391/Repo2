#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Give one score!" << std::endl;
        return 1;
    }
    // string to int conversion: std::stoi is in c++11
    int score = std::stoi(std::string(argv[1]));
    if (score == 100) {
        std::cout << "you have a perfect score!" << std::endl;
    }
    if (score >= 90 && score <= 100) {
        std::cout << "you scored an A!" << std::endl;
    } else if (score >= 80 && score <= 89) {
        std::cout << "you scored an B!" << std::endl;
    } else if (score >= 70 && score <= 79) {
        std::cout << "you scored an C!" << std::endl;
    } else if (score >= 60 && score <= 69) {
        std::cout << "you scored an D!" << std::endl;
    } else if (score >= 0 && score <= 59) {
        std::cout << "you scored an F! Learn idiot" << std::endl;
    }
    return 0;
}

