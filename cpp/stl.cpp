#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

// the stl contains of 4 parts:
// 1. containers
// 2. iterators
// 3. algorithms
// 4. functions

// pairs
void pairs_explain() {
  // pair is in the utility header
  pair<int, int> p = {1, 2};

  cout << p.first << " " << p.second << endl;

  pair<int, pair<int, int>> p2 = {1, {2, 3}}; // nested pairs

  cout << p.first << " " << p2.second.second << " " << p2.second.first << endl;

  pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}}; // array of pairs

  cout << arr[0].first << " " << arr[0].second << endl;
}

// vectors (dynamic arrays)
void vector_explain() {
  // vector is in the vector header
  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.emplace_back(3); // same as push_back
  // emplace_back is faster than push_back
  // emplace_back constructs the object in place
  // push_back constructs the object and then moves it to the vector
  // emplace_back is faster because it doesn't move the object

  cout << v[0] << " " << v[1] << " " << v[2] << endl;

  // vector of pairs
  vector<pair<int, int>> v2;
  v2.push_back({1, 2});
  v2.emplace_back(2, 3);

  cout << v2[0].first << " " << v2[1].second << endl;

  // iterating over a vector
  v.emplace_back(4);
  cout << *v.begin() << endl; // * dereferences the iterator
  // v.end() points to the element after the last element
  // v.rend() points to the element before the first element (reverse iterator)
  // v.rbegin() points to the last element (reverse iterator)
  vector<int>::iterator it = v.begin(); // iterator is a pointer to the vector
  while (it != v.end()) {
    cout << *it << " "; // dereference the iterator to get the value
    it++;
  }

  auto it2 = v.begin(); // auto keyword automatically deduces the type
  while (it2 != v.end()) {
    cout << *it2 << " ";
    it2++;
  }

  for (auto it : v) { // range based for loop
    cout << it << " ";
  }

  // deleting elements from a vector
  v.erase(v.begin() + 1);                // erases the second element
  v.erase(v.begin() + 1, v.begin() + 3); // erases the second and third elements
  v.clear();                             // erases all elements

  // inserting elements into a vector
  v.insert(v.begin() + 1, 2);    // inserts 2 at the second position
  v.insert(v.begin() + 1, 3, 2); // inserts 2, 2, 2 at the second position
  // inserting aother vector into a vector
  vector<int> v3 = {1, 2, 3};
  v.insert(v.begin() + 1, v3.begin(),
           v3.end()); // inserts v3 into v at the second position

  // swap
  vector<int> v4 = {1, 2, 3};
  vector<int> v5 = {4, 5, 6};
  v4.swap(v5); // swaps v4 and v5

  // empty
  vector<int> v6 = {1, 2, 3};
  cout << v6.empty() << endl; // returns 0 if not empty, 1 if empty
}

// lists (doubly linked lists)
// same as vectors but with different functions
// lists are slower than vectors
void list_explain() {
  list<int> l;
  l.push_back(4);
  l.push_front(0);
  l.emplace_back(5);
  l.emplace_front(-1);

  cout << l.front() << " " << l.back() << endl;

  l.pop_back();
  l.pop_front();

  cout << l.front() << " " << l.back() << endl;

  l.insert(l.begin(), 0);
  l.insert(l.begin(), 3, 2);
  l.insert(l.begin(), l.begin(), l.end());

  l.erase(l.begin());
  l.erase(l.begin(), l.end());

  l.clear();

  // l.swap(l2);

  cout << l.empty();
}

// deque (double ended queue)
// same as vectors but with push_front and pop_front
void deque_explain() {
  deque<int> d;
  d.push_back(1);
  d.push_front(2);
  d.emplace_back(3);
  d.emplace_front(4);

  cout << d.front() << " " << d.back() << endl;

  d.pop_back();
  d.pop_front();

  cout << d.front() << " " << d.back() << endl;

  d.insert(d.begin(), 0);
  d.insert(d.begin(), 3, 2);
  d.insert(d.begin(), d.begin(), d.end());

  d.erase(d.begin());
  d.erase(d.begin(), d.end());

  d.clear();

  // d.swap(d2);

  cout << d.empty();
}

// stack (LIFO)
void stack_explain() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.emplace(3);

  cout << s.top() << endl;

  s.pop();

  cout << s.top() << endl;

  cout << s.size() << endl;

  s.pop();
  s.pop();

  cout << s.empty() << endl;
}

// queue (FIFO)
void queue_explain() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.emplace(3);

  cout << q.front() << " " << q.back() << endl;

  q.pop();

  cout << q.front() << " " << q.back() << endl;

  cout << q.size() << endl;

  q.pop();
  q.pop();

  cout << q.empty() << endl;
}

// priority queue (max heap)
// same as queue but with a priority
// the element with the highest priority is at the top
// the priority is determined by the operator < (less than)
void priority_queue_explain() {
  // priority_queue is in the queue header
  priority_queue<int> pq;
  pq.push(1);    // {1} log(n)
  pq.push(2);    // {2, 1}
  pq.emplace(3); // {3, 2, 1}

  cout << pq.top() << endl; // O(1)

  pq.pop(); // {2, 1} log(n)

  cout << pq.top() << endl;

  cout << pq.size() << endl;

  // Minimum heap
  priority_queue<int, vector<int>, greater<int>> pq2;
  pq2.emplace(1); // {1}
  pq2.emplace(2); // {1, 2}
  pq2.emplace(3); // {1, 2, 3}
  pq2.emplace(0); // {0, 1, 2, 3}

  cout << pq2.top() << endl;
}

// set
// stores unique elements in sorted order
void set_explained() {
  set<int> s;

  s.insert(1);  // {1}
  s.insert(2);  // {1, 2}
  s.emplace(3); // {1, 2, 3}
  s.emplace(3); // {1, 2, 3}

  cout << s.size() << endl; // 3

  auto it = s.find(2); // returns an iterator to the element O(log(n))
  if (it != s.end()) {
    cout << *it << endl; // 2
  }

  s.erase(2); // {1, 3} log(n)

  int c = s.count(3); // returns 1 if the element is in the set, 0 otherwise
  cout << c << endl;

  auto it2 = s.find(3);
  s.erase(it2); // {1}
}

// multiset
// same as set but can store multiple elements with the same value
// sorted in ascending order

// unordered_set
// same as set but not sorted
// faster than set O(1) average case, worst case O(n)
// uses hashing
// stores unique elements

// map
// stores key value pairs
// keys are unique
// keys are sorted in ascending order
void map_explain() {
  map<int, int> m;

  m.insert({1, 2}); // {1: 2}
  m.insert({2, 3}); // {1: 2, 2: 3}
  m.emplace(3, 4);  // {1: 2, 2: 3, 3: 4}
  m.emplace(3, 5);  // {1: 2, 2: 3, 3: 4}
  m.emplace(4, 5);  // {1: 2, 2: 3, 3: 4, 4: 5}

  for (auto it : m) {
    cout << it.first << " " << it.second << endl;
  }

  cout << m[3] << endl; // 4
  cout << m[5] << endl; // 0

  auto it = m.find(3); // returns an iterator to the element O(log(n))
  if (it != m.end()) {
    cout << it->first << " " << it->second << endl; // 3 4
  }
}

// multimap
// same as map but can store multiple elements with the same key
// keys are sorted in ascending order

// unordered_map
// same as map but not sorted
// faster than map O(1) average case, worst case O(n)
// uses hashing
// stores unique elements

int main(int argc, char *argv[]) {
  cout << "Hello, world!" << endl;
  // pairs_explain();
  // vector_explain();
  // list_explain();
  // deque_explain();
  // stack_explain();
  // queue_explain();
  // priority_queue_explain();
  // set_explained();
  map_explain();
  return 0;
}
