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

TreeNode* createTree(const vector<int>& data, int index) {
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

    cur->left = createTree(data, index*2);
    cur->right = createTree(data, index*2 + 1);

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
    TreeNode* root = createTree(input, 1);

    vector<int> result;
    pre_order_traverse(root, result);
    for (auto cur: result) {
        cout << cur << " ";
    }
    cout << endl;
}