#include <iostream>
#include <string> 



int main(int argc, char **argv)
{
	std::string wynik(argv[1]);
	std::cout << argv[0] << std::endl;
	std::cout << argv[1] << std::endl;
	if(wynik=="100") 
	{
		std::cout << "you have a perfect score!" << std::endl;
		
	}
	
	
	return 0;
}

