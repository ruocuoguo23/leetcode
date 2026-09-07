// LeetCode 455：分发饼干
// 题意：g[i] 为孩子的最低饼干需求，s[j] 为饼干大小；每个孩子最多一块，
//       每块最多分给一个孩子，求最多能满足多少个孩子。
// 示例：g = [1, 2]，s = [1, 2, 3]，返回 2。
// 思路：原地排序两个数组，从胃口最大的孩子开始；最大剩余饼干能满足他时
//       就分配，否则跳过该孩子，将这块饼干留给胃口较小的孩子。
// 复杂度：时间 O(m log m + n log n)，扫描仅需 O(1) 辅助空间，另计排序栈。

//
// Created by 吴洋 on 2023/6/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int find_content_children(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int s_index = s.size()-1;
        // 这个非常需要注意，如果用了auto，那么这里的child index就是无符号整形的，会有溢出的问题。
        for (int child_index = g.size()-1; child_index >= 0; child_index--) {
            if (s_index < 0) {
                break;
            }

            if (s[s_index] >= g[child_index]) {
                // 利用贪心算法找到最大的饼干满足胃口最大的孩子
                result ++;
                s_index --;
            }
        }

        return result;
    }
};

int main() {
    vector<int> g{1, 2};
    vector<int> s{1, 2, 3};
    auto content_num = Solution::find_content_children(g, s);
    cout << "content num is " << content_num <<endl;

    return 0;
}