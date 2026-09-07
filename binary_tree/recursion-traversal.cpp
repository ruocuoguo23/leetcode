// 练习：二叉树的前序、中序和后序递归遍历
// 目标：分别按“根、左、右”“左、根、右”“左、右、根”的顺序返回节点值。
// 示例：根为 2，左孩子为 1，右孩子为 3，三种遍历依次为 [2, 1, 3]、
//       [1, 2, 3]、[1, 3, 2]。
// 思路：空节点结束递归；调整记录当前节点与递归左右子树的先后顺序即可。
// 复杂度：每种遍历时间 O(n)，递归栈空间 O(h)，另需 O(n) 结果空间。

//
// Created by wuyang on 2021/10/9.
//
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
    vector<int> preorder_traversal(TreeNode *root) {
        vector<int> result;
        preorder_impl(root, result);

        return result;
    }

    void preorder_impl(TreeNode *node, vector<int> &result) {
        if (!node) {
            return;
        }

        result.push_back(node->val);
        preorder_impl(node->left, result);
        preorder_impl(node->right, result);
    }

    vector<int> inorder_traversal(TreeNode *root) {
        vector<int> result;
        inorder_impl(root, result);

        return result;
    }

    void inorder_impl(TreeNode *node, vector<int> &result) {
        if (!node) {
            return;
        }

        inorder_impl(node->left, result);
        result.push_back(node->val);
        inorder_impl(node->right, result);
    }

    vector<int> postorder_traversal(TreeNode *root) {
        vector<int> result;
        postorder_impl(root, result);

        return result;
    }

    void postorder_impl(TreeNode *node, vector<int> &result) {
        if (!node) {
            return;
        }

        postorder_impl(node->left, result);
        postorder_impl(node->right, result);
        result.push_back(node->val);
    }
};

int main() {
    //    3
    //   /  \
    //  9    20
    // / \   /  \
    //12  8 15   7
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = Solution().preorder_traversal(root);
    cout << "preorder result:" << endl;
    for (const auto& val: result) {
        cout << val << ", ";
    }
    cout << endl;

    result = Solution().inorder_traversal(root);
    cout << "inorder result:" << endl;
    for (const auto& val: result) {
        cout << val << ", ";
    }
    cout << endl;

    result = Solution().postorder_traversal(root);
    cout << "postorder result:" << endl;
    for (const auto& val: result) {
        cout << val << ", ";
    }
    cout << endl;
}