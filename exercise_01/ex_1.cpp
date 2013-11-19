#include <iostream>
#include <string>

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

