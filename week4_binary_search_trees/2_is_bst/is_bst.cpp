#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void inorder (std::vector<long long> &v, int i,const vector<Node>& tree) {
  if(tree[i].left != -1)
    inorder(v,tree[i].left,tree);
  //if()
  v.push_back(tree[i].key);
  if(tree[i].right != -1)
    inorder(v,tree[i].right,tree);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size() <= 1)
    return true;
  std::vector<long long> result;
  inorder(result,0,tree);

  for(int i=1;i<result.size();i++) {
    if(result[i] < result[i-1])
    {
      //std::cout << result[i] << '\n';
      return false;
    }
  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
