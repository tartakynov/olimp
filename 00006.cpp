#include <cstdlib>
#include <fstream>

using namespace std;

int main(void) {
  ifstream fin("plan.in");
  ofstream fout("plan.out");
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    int start = i * n + 1;
    int end = i * n + n;
    if (i % 2 == 0) {
      // straight
      for (int j = start; j <= end; j++) {
        fout << j << ' ';
      }
    } else {
      // backwards
      for (int j = end; j >= start; j--) {
        fout << j << ' ';
      }
    }

    fout << endl;
  }

  fout.close();
  fin.close();
  return 0;
}
