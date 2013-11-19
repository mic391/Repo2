#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
	int numberString;
	std::string wynik(argv[1]);
	std::cout << argv[0] << std::endl;
	std::cout << argv[1] << std::endl; //TODO: what if there is no 1st arg?
	if(wynik=="100")
	{
		std::cout << "you have a perfect score!" << std::endl;

	}

	/// string to number conversion
	 std::stringstream ss;
     ss<<wynik;
     ss>>numberString;
     ss.str("");
     ss.clear();



	if(numberString>=90 && numberString<=100)
	{
		std::cout << "you scored an A!" << std::endl;

	}
	else if(numberString>=80 && numberString<=89)

	{
		std::cout << "you scored an B!" << std::endl;
	}

	else if(numberString>=70 && numberString<=79)

	{
		std::cout << "you scored an C!" << std::endl;
	}
	else if(numberString>=60 && numberString<=69)

	{
		std::cout << "you scored an D!" << std::endl;
	}
	else if(numberString>=0 && numberString<=59)

	{
		std::cout << "you scored an F! Learn idiot" << std::endl;
	}

	return 0;
}

