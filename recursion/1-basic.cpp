#include "../stdc++.h"

using namespace std;

// print a name 'n' times
void f1(int n) {
  if (n == 0)
    return;
  printf("lemon\n");
  return f1(n - 1);
}

// sum of first n numbers
int f2(int n) {
  if (n == 0)
    return 0;
  return n + f2(n - 1);
}

// reverse a array
void reverseArray(int *arr, int start, int end) {
  if (start >= end)
    return;

  swap(arr[start], arr[end]);
  reverseArray(arr, start + 1, end - 1);
}

// check if string is palindrome
bool isPalindrome(string str, int start, int end) {
  if (start >= end)
    return true;

  return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

// fibonacci
int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  f1(5);
  cout << f2(5) << endl;
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  reverseArray(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  string str = "lemon";
  cout << isPalindrome(str, 0, str.length() - 1) << endl;

  str = "racecar";
  cout << isPalindrome(str, 0, str.length() - 1) << endl;

  cout << fibonacci(9) << endl;

  cout << endl;

  return 0;
}
