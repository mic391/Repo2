#include <iostream>
#include <string>

void rysuj(const char *w)

	{
		
		std::cout << std::endl;
		while(*w){
			for(int i=0;i>2;i++){
			{ std::cout <<*(w++) << " - "; }
			}
		std::cout << std::endl;
		}
	}

int main(int argc, char** argv)
{
    void char tablica[2][2] = {"x","o","x","o","x","o","x","o","x",};
    
    rysuj(tablica);    
    
    
    
    return 0;
}

