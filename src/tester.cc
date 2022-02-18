// Copyright (c) 2022

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "./dual_list.h"

using std::endl;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::stringstream;

string ProcessCommand(DualList<char, int> *DL, string input_line) {
  string outputLine = "";
  if (input_line == "size") {
    int size = DL->Size();
    outputLine = "size: " + to_string(size);
  } else if (input_line == "list-by-key1") {
    vector<string> res = DL->ListByKey1();
    outputLine = "list-by-key1:\n";
    for (auto & element : res) {
      outputLine += "\t" + element + "\n";
    }
  } else if (input_line == "list-by-key2") {
    vector<string> res = DL->ListByKey2();
    outputLine = "list-by-key1:\n";
    for (auto & element : res) {
      outputLine += "\t" + element + "\n";
    }
  } else if (input_line == "extract-min-key1") {
    outputLine = "extract-min-key1: " + to_string(DL->ExtractMinKey1());
  } else if (input_line == "extract-min-key2") {
    outputLine = "extract-min-key2: " + to_string(DL->ExtractMinKey2());
  } else if (input_line.substr(0, 6) == "insert") {
    stringstream ss(input_line);
    string key1Val, key2Val;
    getline(ss, key1Val, ':');
    getline(ss, key1Val, ':');
    getline(ss, key2Val, ':');
    DL->Insert(*key1Val.c_str(), stoi(key2Val));
    outputLine = "insert(" + key1Val + ", " + key2Val + "): successful";
  }

  return outputLine;
}

void RunTests(DualList<char, int> *DL, string input_file, string output_file) {
  ifstream infile(input_file);
  ofstream outfile(output_file, std::ios_base::app);
  string line;
  while (infile >> line) {
    string outputLine = ProcessCommand(DL, line);
    outfile << outputLine << endl;
  }
  infile.close();
  outfile.close();
}

int main() {
  DualList<char, int> DL;
  string inputFile = "tests/test01-input.txt";
  string outputFile = "tests/test01-output.txt";
  RunTests(&DL, inputFile, outputFile);

  return 0;
}
