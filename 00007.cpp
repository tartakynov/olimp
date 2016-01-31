#include <cstdlib>
#include <fstream>

using namespace std;

inline int compare(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

inline bool triangle(int a, int b, int c) {
  return ((a < (b + c)) && (b < (a + c)) && (c < (a + b)));
}

bool test(int *a, int n) {
  int start = 0;
  while (n - start >= 3) {
    for (int i = start; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (triangle(a[i], a[j], a[k])) {
            return true;
          }
        }
      }
    }

    start++;
    a[start] += a[start - 1];
  }

  return false;
}

int main(void) {
  ifstream fin("fence.in");
  ofstream fout("fence.out");
  int n;
  fin >> n;

  int a[n + 1];
  for (int i = 0; i < n; i++) {
    fin >> a[i];
  }

  qsort(a, n, sizeof(int), compare);
  fout << (test(a, n) ? "yes" : "no") << endl;
  fin.close();
  fout.close();
  return 0;
}
