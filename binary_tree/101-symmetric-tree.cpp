// LeetCode 101：对称二叉树
// 题意：判断二叉树是否关于根节点的中心轴镜像对称，需要同时比较结构和节点值。
// 示例：层序表示 [1, 2, 2, 3, 4, 4, 3] 返回 true。
// 思路：递归比较一对镜像节点；都为空则匹配，仅一个为空或值不同则失败。
//       继续比较左树的右孩子与右树的左孩子，以及左树的左孩子与右树的右孩子。
// 注意：通常将空树视为对称；当前入口对空根返回 false。
// 复杂度：时间 O(n)，递归栈空间 O(h)，h 为树高。

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