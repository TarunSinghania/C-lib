#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  // Create a text file
  ofstream MyWriteFile("filename.txt");

  // Write to the file

  MyWriteFile << "Files can be tricky, but it is fun enough!";
  MyWriteFile << '\n';
  MyWriteFile << "xxx";
  
  // Close the file
  MyWriteFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("filename.txt");
  char x;
  
  // Use a while loop together with the getline() function to read the file line by line
  while (!MyReadFile.eof()) {
    MyReadFile>>std::noskipws >>x;
    cout<<x;
  }

  // Close the file
  MyReadFile.close();
}


freopen ("/users/tarunsinghania/Desktop/competitive5Aug22/inputf.in", "r", stdin);
freopen ("/users/tarunsinghania/Desktop/competitive5Aug22/testing/stresstester2/o2.in", "w", stdout);