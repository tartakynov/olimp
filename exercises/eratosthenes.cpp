#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void primes(int n, vector<int> &v) {
  bool arr[n + 1];
  for (int i = 0; i <= n; i++) arr[i] = true;

  for (int i = 2; i <= sqrt(n); i++) {
    if (arr[i]) {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (arr[i]) {
      v.push_back(i);
    }
  }
}

int main(void) {
  int n;
  vector<int> v;

  cin >> n;
  primes(n, v);
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
  return 0;
}
