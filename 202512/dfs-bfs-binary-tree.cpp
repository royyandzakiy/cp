#include <bits/stdc++.h>
using namespace std;

/*

src: https://chat.deepseek.com/a/chat/s/5f63ae66-3581-4846-b5e6-0d3e2494eaa0
bonus: https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
        : val(value),
          left(nullptr),
          right(nullptr) {
    }
};

class BinaryTree {
  private:
    TreeNode* root;

    void visitNode(TreeNode* node) {
        cout << node->val << " ";
    }

    void deleteTree(TreeNode* node) {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node; // visit
    }

  public:
    BinaryTree()
        : root(nullptr) {
    }

    // ---- GENERAL ----
    // buildTree

    ~BinaryTree() {
        deleteTree(root);
    }

    // ---- TRAVERSALS ----
    // algo: left else visit else up else right, repeat
    // use: expression tree
    void dfsInOrder(TreeNode* node) {
        if (node == nullptr)
            return;

        dfsInOrder(node->left);
        visitNode(node); // visit
        dfsInOrder(node->right);
    }

    // algo: visit else left else right else up, repeat
    // use: copy tree, prefix expressions
    void dfsPreOrder(TreeNode* node) {
        if (node == nullptr)
            return;

        visitNode(node);
        dfsPreOrder(node->left);
        dfsPreOrder(node->right);
    }

    // algo: left else visit else right else up, repeat
    // use: delete tree, postfix expression, garbage collection
    void dfsPostOrder(TreeNode* node) {
        if (node == nullptr)
            return;

        dfsPostOrder(node->left);
        visitNode(node);
        dfsPostOrder(node->right);
    }

    // bfsLevelOrder
    void bfsLevelOrder() {
        if (node == nullptr)
            return;

        queue<TreeNode*> q; // eg: 1, 2, 3, 4, 5, 6
        q.push(root);

        while (!q.empty) {
            // visit
            auto curr = q.front();
            cout << curr->val << " ";
            q.pop();

            // add
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }

    // ---- CP Problems ----
    // height

    // weight

    // isBalanced

    // invertTree
};

auto main() -> int {
    // problem case

    return 0;
}