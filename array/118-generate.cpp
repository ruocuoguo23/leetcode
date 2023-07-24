//
// Created by 吴洋 on 2023/7/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int index = 1; index <=numRows; ++ index) {
            vector<int> current(index, 1);

            for (int i = 1; i < index - 1; i ++) {
                current[i] = result[index-1-1][i-1] + result[index-1-1][i];
            }

            result.push_back(current);
        }

        return result;
    }
};

int main() {
    Solution().generate(5);
}