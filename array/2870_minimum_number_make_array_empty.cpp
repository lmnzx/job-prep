#include <iostream>
#include <unordered_map>
#include <vector>

int minOperations(std::vector<int> &nums) {
  std::unordered_map<int, int> m;
  for (auto i : nums)
    m[i]++;
  int count = 0;
  for (auto i : m) {
    int t = i.second;
    if (t == 1)
      return -1;
    count += t / 3;
    if (t % 3)
      count++;
  }
  return count;
}

int main(int argc, char *argv[]) {
  std::vector<int> t = {2, 3, 3, 2, 2, 4, 2, 3, 4};
  std::cout << minOperations(t);
  return 0;
}
