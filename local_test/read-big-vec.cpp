//
// Created by 吴洋 on 2023/7/14.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


//class BigVector {
//public:
//    BigVector(int cache_size): cache_size(cache_size) {
//
//    }
//
//    // op, 0 for read, 1 for write, others invalid
//    void execute(int op, );
//
//    long index(long index) {
//        // return value of index
//        int page_size = 200亿 / 20 ;
//        int page_index, offset = index / page_size;
//
//        //
//    private:
//        unordered_map<long, long> cache; // 10w
//        int cache_size;
//
//        map<long, long> cache;
//    }
//
//    void set_value(long index, long value) {
//        // from index -> page, offset
//
//        // open file, write value
//        if (cache.size() >= cache_size) {
//            // write to disk
//            // 落盘一部分
//        }
//        cache[index] = value;
//
//
//    }
//
//    void
//
//    vector<long> current_page_content;
//    unordered_map<int, File*>
//    unordered_map<long, value> cache;
//
//private:
//   int cache_size = 10w;
//
//};

class Solution {
public:
    string big_int_add(const string& value1, const string& value2) {
        // 1. value pre-op string -> vector<int>
        auto vec_value1 = pre_op(value1);
        auto vec_value2 = pre_op(value2);

        // 2. vector reverse
        reverse(vec_value1.begin(), vec_value1.end());
        reverse(vec_value2.begin(), vec_value2.end());

        // 3. add each v, 注意进位
        vector<int> add_result;
        int min_size = min(value1.size(), value2.size());
        bool flag = false;
        int cur_result;
        for (int index = 0; index < min_size; ++ index) {
            if (flag) {
                cur_result = vec_value1[index] + vec_value2[index] + 1;
            } else {
                cur_result = vec_value1[index] + vec_value2[index];
            }

            if (cur_result >= 10) {
                flag = true;
            } else {
                flag = false;
            }

            add_result.push_back(cur_result%10);
        }

        // 处理剩下的
        if (value1.size() > min_size) {
            for (int index = min_size; index < value1.size(); ++ index) {
                if (flag) {
                    cur_result = vec_value1[index] + 1;
                } else {
                    cur_result = vec_value1[index];
                }

                if (cur_result >= 10) {
                    flag = true;
                } else {
                    flag = false;
                }

                add_result.push_back(cur_result%10);
            }
        }

        if (value2.size() > min_size) {
            for (int index = min_size; index < value2.size(); ++ index) {
                if (flag) {
                    cur_result = vec_value2[index] + 1;
                } else {
                    cur_result = vec_value2[index];
                }

                if (cur_result >= 10) {
                    flag = true;
                } else {
                    flag = false;
                }

                add_result.push_back(cur_result%10);
            }
        }

        // 处理最后的进位
        if (flag) {
            add_result.push_back(1);
        }

        // 4. 转换成结果
        string result;
        for (auto i: add_result) {
            result += to_string(i);
        }

        reverse(result.begin(), result.end());

        return result;
    }

private:
    vector<int> pre_op(const string& value) {
        vector<int> result(value.size());
        for (int index = 0; index < value.size(); ++index) {
            string temp(1, value[index]);
            result[index] = atoi(temp.c_str());
        }

        return result;
    }
};


int main() {
    // 200亿 long类型 8字节
    // mem 32GB
    // 160GB, 40亿 * 5
    // [0-40亿], [], [], [], []
    // long v[20000000000];
    //v[19000000000] = 100;
    // v[0] = 100;
    // cout << v[0] << endl;
    // cout << v[19000000000] << endl;
//    vector<long> v(20000000000);
    string big_value1 = "99999998";
    string big_value2 = "1";

    string result = Solution().big_int_add(big_value1, big_value2);
    cout << result << endl;
}
