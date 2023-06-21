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