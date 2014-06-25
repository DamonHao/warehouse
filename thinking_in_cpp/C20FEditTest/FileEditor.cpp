#include "stdafx.h"
#include "FileEditor.h"
#include <fstream>
using namespace std;

FileEditor::FileEditor(char* filename) {
  ifstream in(filename);
  //assure(in, filename);
  string line;
  while(getline(in, line))
    push_back(line);
}

// Could also use copy() here:
void FileEditor::write(ostream& out) {
  for(iterator w = begin();  w != end(); w++)
    out << *w << endl;
} ///:~