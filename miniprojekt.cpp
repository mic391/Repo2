



	

    #include <iostream>
    #include <vector>
    #include <algorithm>
     
     
using namespace std;     
  
global char spisdowodow[100];
global char *dowod_wsk;
dowod_wsk = & spisdowodow;
  
    
class pojazd {

public:		 
		 pojazd(): 
		 
		
		 
		 {
			 
			 cout << "podaj nr rejestracyjny" << endl;
			 cin >> dowodrj; 
			 cout << "podaj rodzaj pojazdu" << endl;
			 cin >> rodzaj;
			
		}
		virtual void stworz () = 0;
     {
		 
	 }
     
     
        virtual ~pojazd()
     
     

class motor : public pojazd {
	
	void stworz () {
		
		
	}
	
	
}


class samochod : public pojazd {
	
	void stworz () {
	}
}
 
     
     
class TIR : public pojazd {
	
	void stworz () {
	}
}
     

    
    int main(int argc, char* argv[]) {
     
     
     
        return 0;
    }

