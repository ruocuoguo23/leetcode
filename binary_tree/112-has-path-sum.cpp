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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr && root->val == sum) {
            return true;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    vector<int> input{-1,5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
    TreeNode* root = create_tree(input, 1);

    bool has_path_flag = Solution().hasPathSum(root, 22);
    cout << "has path flag: " << has_path_flag <<endl;
}