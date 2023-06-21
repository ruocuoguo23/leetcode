//
// Created by 吴洋 on 2023/6/21.
//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) {
            return root;
        }

        auto left = lowest_common_ancestor(root->left, p, q);
        auto right = lowest_common_ancestor(root->right, p, q);

        if (left && !right) {
            return left;
        } else if (right && !left) {
            return right;
        } else if (left && right) {
            return root;
        } else {
            return nullptr;
        }
    }
};

int main() {

}
