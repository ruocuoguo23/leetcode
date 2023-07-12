//
// Created by wuyang on 2020/12/9.
//

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return false;
        } else {
            return isSymmetricRecurse(root->left, root->right);
        }
    }

private:
    bool isSymmetricRecurse(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        } else if (left && !right) {
            return false;
        } else if (!left && right) {
            return false;
        } else {
            if (left->val != right->val) {
                return false;
            } else {
                return isSymmetricRecurse(left->right, right->left) && isSymmetricRecurse(left->left, right->right);
            }
        }
    }
};

int main() {
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// return true

//     1
//    / \
//   2   2
//    \   \
//     3   3
// return false

}