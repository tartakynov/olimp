#include <cstdlib>
#include <climits>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

struct Coord {
  int x;
  int y;

  Coord(): x(0), y(0) {}
  Coord(int x, int y): x(x), y(y) {}
};

int main(void) {
  ifstream fin("vanya.in");
  ofstream fout("vanya.out");
  int h, w;
  Coord start, end;
  fin >> h >> w;

  char map[h][w];
  int distances[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      fin >> map[i][j];
      distances[i][j] = INT_MAX;
      if (map[i][j] == 'S') {
        start.x = i;
        start.y = j;
        distances[i][j] = 0;
      } else if (map[i][j] == 'T') {
        end.x = i;
        end.y = j;
      }
    }
  }

  stack<Coord> stack;
  stack.push(start);
  while (!stack.empty()) {
    int x, y;
    Coord coord = stack.top(); stack.pop();
    for (int i = 0; i < 4; i++) {
      switch (i) {
        case 0:
          x = coord.x - 1; y = coord.y;
          break;
        case 1:
          x = coord.x + 1; y = coord.y;
          break;
        case 2:
          x = coord.x; y = coord.y - 1;
          break;
        case 3:
          x = coord.x; y = coord.y + 1;
          break;
      }

      if (x >= 0 && x < h && y >= 0 && y < w && map[x][y] != '#') {
        if (distances[x][y] > (distances[coord.x][coord.y] + 1)) {
          distances[x][y] = distances[coord.x][coord.y] + 1;
          stack.push(Coord(x, y));
        }
      }
    }
  }

  fout << distances[end.x][end.y];

  fout.close();
  fin.close();
  return 0;
}
