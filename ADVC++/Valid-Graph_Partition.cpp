//Develop a task to generate all valid partitiond of a graph into two subsets 
#include <vector>

std::vector<std::vector<std::vector<int>>> graphPartitions (
    const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<std::vector<std::vector<int>>> result;
    std::vector<int> part1, part2;

    std::function<void(int, std::vector<bool>&)> backtrack =
        [&] (int idx, std::vector<bool>& used) {
            if (idx == n) {
                result.push_back({part1, part2});
                return;
            }
            bool valid1 = true, valid2 = true;
            for (int v : part1) {
                if (graph[idx][v]) valid1 = false;
            }
            for (int v : part2) {
                if (graph[idx][v]) valid2 = false;
            }
            if (valid1) {
                part1.push_back(idx);
                used[idx] = true;
                bactrack(idx + 1, used);
                part1.pop_back();
                used[idx] false;
            }
            if (valid2) {
                part2.push_back(idx);
                used[idx] = true;
                backtrack(idx+ 1, used );
                part2.pop_back();
                used[idx] = false;
            }
        };

        std::vector<bool> used (n, false);
        backtrack(0, used);
        return result;
}