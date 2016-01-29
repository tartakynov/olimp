#include <cstdlib>
#include <iostream>
#include <fstream>

#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

using namespace std;

// returns true if the segments intersect in 1d space
inline bool intersects(int a1, int a2, int b1, int b2) {
  return (a2 >= b1) && (b2 >= a1);
}

// returns true if the rectangles intersect in 2d space
inline bool intersects(int x[], int y[]) {
  return intersects(x[0], x[1], x[2], x[3])
    && intersects(y[0], y[1], y[2], y[3]);
}

// returns a square of the shared portion of the rectangles in 2d space
inline int intersection(int x[], int y[]) {
  int ox[2], oy[2];
  if (intersects(x, y)) {
    ox[0] = max(x[0], x[2]);
    oy[0] = max(y[0], y[2]);
    ox[1] = min(x[1], x[3]);
    oy[1] = min(y[1], y[3]);
    return (ox[1] - ox[0]) * (oy[1] - oy[0]);
  }

  return 0;
}

int main(void) {
  ifstream fin("coloring.in");
  ofstream fout("coloring.out");
  int x[4], y[4];
  fin >> x[0] >> y[0] >> x[1] >> y[1];
  fin >> x[2] >> y[2] >> x[3] >> y[3];
  fout << intersection(x, y);
  fout.close();
  fin.close();
  return 0;
}
