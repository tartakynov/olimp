#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

int main(void) {
  ifstream fin("grave.in");
  ofstream fout("grave.out");
  int arr[101], n, tmp, max = 0;
  memset(arr, 0, sizeof(int) * 101);

  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> tmp;
    arr[tmp]++;
    if (arr[tmp] > max) {
      max = arr[tmp];
    }
  }

  for (int i = 1; i <= 100; i++) {
    if (arr[i] == max) {
      fout << i << ' ';
    }
  }

  fout.close();
  fin.close();
  return 0;
}
