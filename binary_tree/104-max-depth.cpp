// LeetCode 104：二叉树的最大深度
// 题意：返回从根节点到最远叶子节点的最长路径所包含的节点数；空树深度为 0。
// 示例：层序表示 [3, 9, 20, null, null, 15, 7] 的最大深度为 3。
// 思路：递归求左右子树深度，当前深度为 max(左子树深度, 右子树深度) + 1。
// 本地建树：数组下标从 1 开始，-1 表示空位，左右孩子下标为 2*i、2*i+1。
// 复杂度：求深度时间 O(n)，递归栈空间 O(h)，h 为树高。

//
// Created by 吴洋 on 2023/6/20.
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
    int max_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(max_depth(root->left)+1, max_depth(root->right)+1);
    }

private:

};

TreeNode* create_tree(const vector<int>& data, int index) {
    // input data format [null,3,9,20,null,null,15,7]
    //    3
    //   / \
    //  9  20
    //    /  \
    //   15   7
    auto size = data.size();
    if (index >= size) {
        return nullptr;
    }

    if (data[index] == -1) {
        return nullptr;
    }

    auto cur = new TreeNode(data[index]);

    cur->left = create_tree(data, index * 2);
    cur->right = create_tree(data, index * 2 + 1);

    return cur;
}

int main() {
    // first build a b-tree
    vector<int> input{-1, 3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = create_tree(input, 1);

    // cal it's max depth
    auto depth = Solution().max_depth(root);
    cout << "max depth of tree is " << depth << endl;
}