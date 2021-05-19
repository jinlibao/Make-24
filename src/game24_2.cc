/*
 * game24_2.cc
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

vector<string> game24_2(vector<int>& _cards) {
  vector<double> cards(_cards.begin(), _cards.end());
  const double eps = 1e-8;
  int n = cards.size();
  vector<string> ans;
  vector<string> exprs(n, "");
  for (int i = 0; i < n; ++i) exprs[i] = to_string(_cards[i]);

  auto backtrack = y_combinator([&](auto backtrack, int n, int target = 24) -> void {
    if (n == 1) {
      if (abs(cards[0] - target) < eps) {
        ans.push_back(exprs[0]);
      }
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          double a = cards[i], b = cards[j];
          vector<double> vals{a + b, a - b, b - a, a * b, a / b, b / a};
          string u = exprs[i], v = exprs[j];
          vector<tuple<string, string, char>> options{{u, v, '+'}, {u, v, '-'}, {v, u, '-'}, {u, v, '*'}, {u, v, '/'}, {v, u, '/'}};
          vector<string> my_expr(options.size());
          for (int k = 0; k < (int)options.size(); ++k) {
            auto [x, y, c] = options[k];
            ostringstream oss;
            oss << "(" << x << " " << c << " " << y << ")";
            my_expr[k] = oss.str();
          }

          exprs[i] = exprs[n - 1];
          cards[i] = cards[n - 1];
          for (int k = 0; k < (int)options.size(); ++k) {
            cards[j] = vals[k];
            exprs[j] = my_expr[k];
            backtrack(n - 1);
          }
          cards[i] = a;
          cards[j] = b;
          exprs[i] = u;
          exprs[j] = v;
        }
      }
    }
  });
  backtrack(cards.size());
  sort(ans.begin(), ans.end());
  auto it = unique(ans.begin(), ans.end());
  ans.resize(it - ans.begin());
  return ans;
}

void solve() {
  vector<int> cards(4);
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    for (int i = 0; i < (int)cards.size(); ++i) iss >> cards[i];
    auto ans = game24_2(cards);
    cout << line << ":" << (ans.empty() ? " No solution." : "") << '\n';
    for (auto& s : ans) cout << "    " << s << '\n';
  }
}

int main() {
  solve();
  return 0;
}
