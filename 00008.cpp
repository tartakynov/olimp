#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>

#define N 2
#define M 10

struct Seat {
  int x;
  int y;
  Seat(): x(0), y(0) { }
  Seat(int x, int y): x(x), y(y) { }
};

double distance(Seat v1, Seat v2) {
  double a = abs(v1.x - v2.x) * 2;
  double b = abs(v1.y - v2.y);
  return sqrt(a * a + b * b);
}

int main(void) {
  std::ifstream fin("bus.in");
  std::ofstream fout("bus.out");

  char c;
  int n = 0;
  Seat bus[20];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      fin >> c;
      if (c == '-') {
        Seat v(i, j);
        bus[n++] = v;
      }
    }
  }

  double result = 100000;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        double s = distance(bus[i], bus[j]) + distance(bus[i], bus[k]) + distance(bus[j], bus[k]);
        if (s < result) {
          result = s;
        }
      }
    }
  }

  fout << std::fixed << std::setprecision(3) << result;
  fout.close();
  fin.close();
  return 0;
}
