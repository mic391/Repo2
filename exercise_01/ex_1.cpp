#include <iostream>
#include <string> 
#include <sstream>

int main(int argc, char **argv)
{
	int numberString;
	std::string wynik(argv[1]);
	std::cout << argv[0] << std::endl;
	std::cout << argv[1] << std::endl;
	if(wynik=="100") 
	{
		std::cout << "you have a perfect score!" << std::endl;
		
	}
	
	/// string to number conversion
	 stringstream ss;
     ss<<wynik;
     ss>>numberString; 
     ss.str(""); 
     ss.clear(); 
     
     
	if(numberString>=90 && numberString<=100) 
	{
		std::cout << "you scored an A!" << std::endl;
		
	}
	
	return 0;
}

