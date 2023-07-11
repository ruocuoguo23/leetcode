//
// Created by 吴洋 on 2023/7/11.
//
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class State {
public:
    int id;
    int dis_from_start;

    State(int id, int dis_from_start): id(id), dis_from_start(dis_from_start) {}

};

struct cmp {
    bool operator()(State a, State b) {
        return a.dis_from_start > b.dis_from_start;
    }
};

class Solution {
public:
    int network_delay_time(vector<vector<int>>& times, int n, int k) {
        // first build graph
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto &time: times) {
            // [0]: source
            // [1]: dst
            // [2]: weight
            graph[time[0]].emplace_back(time[1], time[2]);
        }

        auto result = dij(graph, k);

        int most_delay_time = *max_element(result.begin()+1, result.end());
        if (most_delay_time == INT32_MAX) {
            return -1;
        } else {
            return most_delay_time;
        }
    }

private:
    vector<int> dij(vector<vector<pair<int, int>>>& graph, int start) {
        // 存储start -> all 最短距离
        vector<int> dis_to (graph.size(), INT32_MAX);
        dis_to[start] = 0;

        // 优先级队列
        priority_queue<State, vector<State>, cmp> q;
        q.emplace(start, 0);

        while (!q.empty()) {
            auto cur_state = q.top();
            q.pop();

            auto cur_distance = cur_state.dis_from_start;
            auto cur_id = cur_state.id;
            if (cur_distance > dis_to[cur_id]) {
                continue;
            }

            for (auto& neighbor: graph[cur_id]) {
                auto next_id = neighbor.first;
                auto dis_to_next = dis_to[cur_id] + neighbor.second;
                if (dis_to_next < dis_to[next_id]) {
                    dis_to[next_id] = dis_to_next;
                    q.emplace(next_id, dis_to_next);
                }
            }
        }

        return dis_to;
    }
};

int main() {
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    auto delay_time = Solution().network_delay_time(times, n, k);
    cout << delay_time << endl;
}