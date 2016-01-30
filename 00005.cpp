#include <cstdlib>
#include <fstream>

using namespace std;

inline int factorial(int n) {
  int ret = 1;
  for(int i = 2; i <= n; i++) {
    ret *= i;
  }

  return ret;
}

inline int combinations(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(void) {
  ifstream fin("drugs.in");
  ofstream fout("drugs.out");
  int n[3], k, ret = 1;
  fin >> n[0] >> n[1] >> n[2] >> k;
  for (int i = 0; i < 3; i++) {
    if (n[i] < k) {
      ret = 0;
      break;
    } else {
      ret *= combinations(n[i], k);
    }
  }

  fout << ret << endl;
  fout.close();
  fin.close();
  return 0;
}
