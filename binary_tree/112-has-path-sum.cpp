// LeetCode 112：路径总和
// 题意：判断是否存在一条从根到叶子的路径，使沿途节点值之和等于目标值。
// 示例：根为 1、左侧叶子为 2，目标为 3 时返回 true；目标为 1 时返回 false。
// 思路：递归向下时从剩余目标中减去当前节点值；只有到达叶子且其值等于
//       剩余目标才成功，左右子树任意一侧成功即可。空节点返回 false。
// 本地建树：采用从 1 开始的完全二叉树位置下标，-1 表示空位。
// 复杂度：时间 O(n)，递归栈空间 O(h)，h 为树高。

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