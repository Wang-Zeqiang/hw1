#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat0;
  dat0.push_back("7");
  dat0.push_front("8");
  dat0.push_back("9");
  cout << "dat0 should be 8 7 9." << endl;
  cout << dat0.get(0) << " " << dat0.get(1) << " " << dat0.get(2) << endl;
  cout << endl;

  ULListStr dat3;
  dat3.push_back("7");
  dat3.push_back("1");
  dat3.push_front("8");
  dat3.push_back("9");
  dat3.push_back("10");
  cout << "dat3 should be 8 7 1 9 10" << endl;
  cout << dat3.get(0) << " " << dat3.get(1) << " " << dat3.get(2) << " " << dat3.get(3) << " " << dat3.get(4) << endl;
  cout << "Size: " << dat3.size() << endl;
  cout << "dat3 back should be 10" << endl;
  cout << dat3.back() << endl;
  cout << "dat3 front should be 8" << endl;
  cout << dat3.front() << endl;
  dat3.pop_front();
  dat3.pop_back();
  cout << "dat3 should be 7 1 9" << endl;
  cout << dat3.get(0) << " " << dat3.get(1) << " " << dat3.get(2) << endl;

  // cout << "Out of bound: " << dat3.get(3) << endl;
  // cout << endl;

  dat0.clear();
  dat3.clear();
}
