//
// Created by wuyang on 2020/12/8.
//

#include <vector>
#include <queue>
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
    static vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode *> cache;
        cache.push(root);

        while (!cache.empty()) {
            queue<TreeNode *> current_layer = cache;
            cache = queue<TreeNode *>();
            vector<int> current_layer_value;

            while (!current_layer.empty()) {
                auto top = current_layer.front();
                current_layer.pop();

                if (top->left) {
                    cache.push(top->left);
                }

                if (top->right) {
                    cache.push(top->right);
                }

                current_layer_value.push_back(top->val);
            }

            result.push_back(current_layer_value);
        }

        return result;
    }
};

int main() {
    //    3
    //    / \
    //  9  20
    //     /  \
    //   15   7
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = Solution::levelOrder(root);
    for (const auto& layer: result) {
        cout << "[";
        for (auto val: layer) {
            cout << val << ", ";
        }
        cout << "]" << endl;
    }
}