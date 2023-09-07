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

void postorder(Node *node)
{
  if (node == NULL)
    return;

  postorder(node->left);
  std::cout << node->data << " ";
  postorder(node->right);
}

int main(int argc, char const *argv[])
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(7);
  root->left->right = new Node(6);
  root->right->left = new Node(5);
  root->right->right = new Node(4);

  postorder(root);
  return 0;
}
