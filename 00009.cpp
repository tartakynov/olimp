#include <cstdlib>
#include <fstream>

using namespace std;

int main(void) {
  ifstream fin("gibdd.in");
  ofstream fout("gibdd.out");
  int n;
  fin >> n;
  char graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> graph[i][j];
    }
  }

  // find minimum vertex cover  
  fout.close();
  fin.close();
  return 0;
}
