// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
struct Node {
  char amount;
  std::vector<Node*> child;
  explicit Node(char amount = '\0') : amount(amount) {}
};
class Tree {
 private:
  Node* root;
  std::vector<std::vector<char>> perm;
  void createPerm(const std::vector<char>& sequence) {
    addElem(root, sequence);
    readTree(root, {});
  }
  void addElem(Node* rootptr, const std::vector<char>& sequence) {
    if (rootptr == nullptr) {
      root = rootptr = new Node;
    }
    for (char amount : sequence) {
      Node* num = new Node(amount);
      rootptr->child.push_back(num);
      std::vector<char> updateSequence(sequence);
      updateSequence.erase(std::find(updateSequence.begin(), \
                                     updateSequence.end(), amount));
      addElem(num, updateSequence);
    }
  }
  void readTree(Node* rootptr, std::vector<char> sequence) {
    if (rootptr != nullptr && rootptr->amount != '\0')
      sequence.push_back(rootptr->amount);
    if (rootptr->child.empty())
      perm.push_back(sequence);
    for (Node* child : rootptr->child) {
      readTree(child, sequence);
    }
  }

 public:
  explicit Tree(const std::vector<char>& init) : root(nullptr) {
    createPerm(init);
  }
  std::vector<std::vector<char>> getPerm() const {
    return perm;
  }
};
#endif  // INCLUDE_TREE_H_
