#include <iostream>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

int main(int argc, char const *argv[])
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  return 0;
}
