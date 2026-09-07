// 练习：由数组构建二叉树并进行前序遍历
// 输入约定：数组从下标 1 开始存放根节点，0 号位置占位，-1 表示空节点；
//           位置 i 的左右孩子位于 2*i、2*i+1。不能用 -1 表示真实节点值。
// 思路：下标越界或值为 -1 时返回空指针，否则创建节点并递归构建左右子树；
//       随后按照“根、左、右”的顺序收集节点值。
// 注意：这是完全二叉树位置编码，不是省略空节点后任意压缩的层序数组。

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
    explicit TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* create_tree(const vector<int>& data, int index) {
    // input data format [3,9,20,null,null,15,7]
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

// let's see a traverse
void pre_order_traverse(TreeNode* root, vector<int>& result) {
    if (!root) {
        return;
    }

    result.push_back(root->val);
    pre_order_traverse(root->left, result);
    pre_order_traverse(root->right, result);
}


int main() {
    vector<int> input{-1, 3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = create_tree(input, 1);

    vector<int> result;
    pre_order_traverse(root, result);
    for (auto cur: result) {
        cout << cur << " ";
    }
    cout << endl;
}