/**
 * make_24.cc
 * Author: Libao Jin
 * Date: 2020-06-11 00:14
 */

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
int interface = 2;

double op(double a, double b, int o) {
  switch (o) {
    case 0:  // '+'
      return a + b;
    case 1:  // '-'
      return a - b;
    case 2:  // '*'
      return a * b;
    case 3:  // '/'
      return b != 0 ? a / b : INT_MIN;
    default:
      return -1;
  }
}

bool solve(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  unordered_set<string> seen;
  int n = 4;
  do {
    int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
    string key = to_string(a) + "," + to_string(a) + "," + to_string(c) + "," + to_string(d) + ",";
    if (seen.count(key) > 0) continue;
    seen.insert(key);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          vector<double> results;
          // ((a - b) - c) - d
          results.push_back(op(op(op(a, b, i), c, j), d, k));
          // (a - b) - (c - d)
          results.push_back(op(op(a, b, i), op(c, d, k), j));
          // (a - (b - c)) - d
          results.push_back(op(op(a, op(b, c, j), i), d, k));
          // a - ((b - c) - d)
          results.push_back(op(a, op(op(b, c, j), d, k), i));
          // a - (b - (c - d))
          results.push_back(op(a, op(b, op(c, d, k), j), i));
          for (auto& r : results)
            if (fabs(r - 24) < EPS) return true;
        }
      }
    }
  } while (next_permutation(nums.begin(), nums.end()));
  return false;
}

void show_result(vector<int>& nums) {
  bool isFirst = true;
  for (auto& n : nums) {
    if (isFirst) {
      cout << n;
      isFirst = false;
    } else {
      cout << " " << n;
    }
  }
  bool isValid = solve(nums);
  cout << ": " << isValid << endl;
}

int main(int argc, char* argv[]) {
  vector<int> nums(4, 0);
  if (argc > 1) {
    interface = atoi(argv[1]);
  } else {
    interface = 0;
  }
  switch (interface) {
    case 1:
      for (int i = 2; i < 6; ++i) nums[i - 2] = atoi(argv[i]);
      show_result(nums);
      break;
    case 2:
      int n, i = 0;
      while (cin >> n) {
        nums[i++ % 4] = n;
        if (i % 4 == 0) show_result(nums);
      }
      break;
  }
  return 0;
}
