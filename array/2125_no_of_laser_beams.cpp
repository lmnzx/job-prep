#include <string>
#include <vector>

int calc(const std::string &s) {
  int count = 0;
  for (char c : s)
    count += c - '0';

  return count;
}

int numberOfBeans(std::vector<std::string> &bank) {
  int res = 0;
  int prev = 0;
  for (const std::string &row : bank) {
    int curr = calc(row);
    if (curr == 0)
      continue;
    res += curr * prev;
    prev = curr;
  }
  return res;
}
