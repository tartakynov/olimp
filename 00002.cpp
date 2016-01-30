#include <cstdlib>
#include <cstring>
#include <fstream>
#include <stack>

#define N 101

using namespace std;

struct Coord {
  int x;
  int y;
  Coord(int x, int y): x(x), y(y) { }
  Coord(): x(0), y(0) {}
};

// returns sum of min span tree using Vojtěch Jarník's algorithm
int min_span_tree(int (&graph)[N][N], int n) {
  int sum = 0;
  char used[n];
  memset(used, 0, n);
  used[0] = 1;
  while (true) {
    int min_distance = -1;
    int next_vertex = -1;
    for (int city = 0; city < n; city++) {
      if (used[city]) {
        for (int neighbor = 0; neighbor < n; neighbor++) {
          if (graph[city][neighbor] && !used[neighbor]) {
            int distance = graph[city][neighbor];
            if (min_distance < 0 || distance < min_distance) {
              min_distance = distance;
              next_vertex = neighbor;
            }
          }
        }
      }
    }

    if (next_vertex < 0) {
      break;
    } else {
      sum += min_distance;
      used[next_vertex] = 1;
    }
  }

  return sum;
}

// converts coordinates map to adjacency matrix
// returns number of vertices in a connected undirected graph
int map_to_graph(int (&map)[N][N], int (&graph)[N][N], int n, Coord start) {
  int count = 0;
  char used[n];
  memset(used, 0, n);
  stack<Coord> stack;
  stack.push(start);
  while (!stack.empty()) {
    Coord coord = stack.top(); stack.pop();
    int city = map[coord.x][coord.y] - 1;
    if (used[city]) continue;
    used[city] = 1;
    count++;
    for (int i = 0; i < N; i++) {
      // moving along y-axis
      if (map[coord.x][i] && i != coord.y) {
        int neighbor = map[coord.x][i] - 1;
        int distance = abs(coord.y - i);
        graph[city][neighbor] = graph[neighbor][city] = distance;
        stack.push(Coord(coord.x, i));
      }

      // moving along x-axis
      if (map[i][coord.y] && i != coord.x) {
        int neighbor = map[i][coord.y] - 1;
        int distance = abs(coord.x - i);
        graph[city][neighbor] = graph[neighbor][city] = distance;
        stack.push(Coord(i, coord.y));
      }
    }
  }

  return count;
}

int main(void) {
  ifstream fin("paral.in");
  ofstream fout("paral.out");
  int graph[N][N], map[N][N], n;
  Coord coord;
  fin >> n;

  memset(map, 0, sizeof(int) * (N * N));
  memset(graph, 0, sizeof(int) * (N * N));
  for (int i = 1; i <= n; i++) {
    fin >> coord.x >> coord.y;
    map[coord.x][coord.y] = i;
  }

  if (map_to_graph(map, graph, n, coord) != n) {
    fout << -1;
  } else {
    fout << min_span_tree(graph, n);
  }

  fout.close();
  fin.close();
  return 0;
}
