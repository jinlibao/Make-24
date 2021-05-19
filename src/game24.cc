/*
 * game24.cc
 * Copyright (C) 2021 Libao Jin <jinlibao@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <class Fun>
class y_combinator_result {
  Fun fun_;

 public:
  template <class T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

vector<string> game24(vector<int>& cards, int target = 24) {
  string op = "+-*/";
  vector<string> ops;
  auto _combination = y_combinator([&](auto _combination, int i, int n, string o) -> void {
    if (i == n) {
      ops.push_back(o);
    } else {
      for (int k = 0; k < (int)op.size(); ++k) _combination(i + 1, n, o + op[k]);
    }
  });
  _combination(0, 3, "");

  auto _next_permuation = [&](vector<int>& nums) -> bool {
    int n = nums.size();
    int k, l;
    for (k = n - 2; k >= 0 && nums[k] >= nums[k + 1]; --k)
      ;
    if (k == -1) {
      reverse(nums.begin(), nums.end());
      return false;
    } else {
      for (l = n - 1; l > k && nums[l] <= nums[k]; --l)
        ;
      swap(nums[k], nums[l]);
      reverse(nums.begin() + k + 1, nums.end());
      return true;
    }
  };
  sort(cards.begin(), cards.end());

  const double eps = 1e-8;
  auto calc = [&](double num1, double num2, char op) -> double {
    double ans = 0;
    switch (op) {
      case '+':
        ans = num1 + num2;
        break;
      case '-':
        ans = num1 - num2;
        break;
      case '/':
        ans = num1 / num2;
        break;
      case '*':
        ans = num1 * num2;
        break;
    }
    return ans;
  };

  vector<string> ans;
  do {
    auto [a, b, c, d] = make_tuple(cards[0], cards[1], cards[2], cards[3]);
    for (auto& o : ops) {
      auto [x, y, z] = make_tuple(o[0], o[1], o[2]);
      // (((a + b) + c) + d)
      if (abs(calc(calc(calc(a, b, x), c, y), d, z) - target) < eps) {
        ostringstream oss;
        oss << "(((" << a << " " << x << " " << b << ") " << y << " " << c << ") " << z << " " << d << ")";
        ans.push_back(oss.str());
      }
      // ((a + b) + (c + d))
      if (abs(calc(calc(a, b, x), calc(c, d, z), y) - target) < eps) {
        ostringstream oss;
        oss << "((" << a << " " << x << " " << b << ") " << y << " (" << c << " " << z << " " << d << "))";
        ans.push_back(oss.str());
      }
      // ((a + (b + c)) + d)
      if (abs(calc(calc(a, calc(b, c, y), x), d, z) - target) < eps) {
        ostringstream oss;
        oss << "((" << a << " " << x << " (" << b << " " << y << " " << c << ")) " << z << " " << d << ")";
        ans.push_back(oss.str());
      }
      // (a + ((b + c) + d))
      if (abs(calc(a, calc(calc(b, c, y), d, z), x) - target) < eps) {
        ostringstream oss;
        oss << "(" << a << " " << x << " ((" << b << " " << y << " " << c << ") " << z << " " << d << "))";
        ans.push_back(oss.str());
      }
      // (a + (b + (c + d)))
      if (abs(calc(a, calc(b, calc(c, d, z), y), x) - target) < eps) {
        ostringstream oss;
        oss << "(" << a << " " << x << " (" << b << " " << y << " (" << c << " " << z << " " << d << ")))";
        ans.push_back(oss.str());
      }
    }
  } while (_next_permuation(cards));

  return ans;
}

void solve() {
  vector<int> cards(4);
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    for (int i = 0; i < (int)cards.size(); ++i) iss >> cards[i];
    auto ans = game24(cards);
    cout << line << ":" << (ans.empty() ? " No solution." : "") << '\n';
    for (auto& s : ans) cout << "    " << s << '\n';
  }
}

int main() {
  solve();
  return 0;
}
