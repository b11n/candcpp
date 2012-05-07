#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
using namespace std;

int main () {
  string line;
  ifstream myfile ("sic.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
 getch();
  return 0;
 
}
