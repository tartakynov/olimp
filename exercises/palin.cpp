#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

bool is_palindrom(string str) {
  const int n = str.length();
  for (int i = 0; i < n / 2; i++) {
    if (str.at(i) != str.at(n - i - 1)) {
      return false;
    }
  }

  return true;
}

void naive(const string &str, set<string> &set) {
  for (int i = 0; i < str.length(); i++) {
    for (int j = 2; j < str.length() - i + 1; j++) {
      string substr = str.substr(i, j);
      if (is_palindrom(substr)) {
        set.insert(substr);
      }
    }
  }
}

int main(void) {
  string str;
  set<string> set;
  cin >> str;
  naive(str, set);
  for (std::set<std::string>::iterator it = set.begin(); it != set.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
