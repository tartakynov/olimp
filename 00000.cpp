#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
  ifstream fin("yield.in");
  ofstream fout("yield.out");
  int a, b;
  fin >> a >> b;
  fout << a + b;
  fout.close();
  fin.close();
  return 0;
}
