#include <iostream>
#include <regex>
#include <fstream>
#include <string>
using namespace std;
class program{
	public:
		ifstream wejscie;
		ofstream wyjscie;
		string napis;
		program();
		~program();
		
	void sprawdzPlik();
	void wczytaj();
	void sprawdz();
	void zapis();
};
program::program(){
	wejscie.open("wejscie.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"Poprawne kody pocztowe: "<<endl;
}
program::~program(){
	wejscie.close();
	wyjscie.close();
}
void program::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()){
		wczytaj();
	}
	else{ 
		cout<<"blad";
		
	}
}
void program::wczytaj(){
	while(!wejscie.eof()){
		wejscie>>napis;
		sprawdz();
	}
}
void program::sprawdz(){
	regex regularne("[0-9]{2}-[0-9]{3}");
	if(regex_match(napis,regularne)){
		cout<<"Kod pocztowy "<<napis<<" jest prawidlowy"<<endl;
		zapis();
	}
	else{
		cout<<"Kod pocztowy "<<napis<<" jest nieprawidlowy"<<endl;
	}
}
void program::zapis(){
	wyjscie<<napis<<endl;
}
int main() {
	program p1;
	p1.sprawdzPlik();
	return 0;
}
