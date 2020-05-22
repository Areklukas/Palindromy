#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class zampal
{
    ifstream plik1;
    ofstream plik2;
	public:				
    zampal();
	~zampal();
    void pal();        
};
zampal::zampal()
{ 
    plik1.open("c:\\plik1.txt");
    plik2.open("c:\\plik2.txt");
}
void zampal::pal()
{
    string pal;string s(),wyraz,lacz("");
	while(!plik1.eof())
	{ 
    	getline(plik1,pal);
        for(int i = 0; i<pal.length(); i++)
		{
  			if(pal[i]>64&&pal[i]<91)
    		pal[i] += 32;           
    	} 
   		stringstream ss(pal);
   		while(ss >> wyraz) 
   		lacz += wyraz; 
    	int end = lacz.length()-1; 
   		bool isPalindrome = true; 
   		string Is;
    	for (int i=0; i<lacz.length()/2 && isPalindrome; i++) 
   		if (lacz[i] != lacz[end--]) 
   		isPalindrome = false;
        if(isPalindrome)
        	Is = "Tak - Palindrom";
		else
	    	Is = "Nie";      
       	plik2<<lacz<<Is;      
        lacz="";                  
    }
}
zampal::~zampal()
{
    plik1.close();
    plik2.close();
}

int main() 
{
	zampal change; 
    change.pal(); 
    
	return 0;
}
