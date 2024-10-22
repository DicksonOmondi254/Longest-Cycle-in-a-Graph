#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int dfs(int node, vector<int>& edges, unordered_set<int>& visited, vector<int>& stack) {
    if (find(stack.begin(), stack.end(), node) != stack.end()) {
        return stack.size() - (find(stack.begin(), stack.end(), node) - stack.begin());
    }
    if (visited.count(node) || edges[node] == -1) {
        return -1;
    }

    visited.insert(node);
    stack.push_back(node);
    int cycle_length = dfs(edges[node], edges, visited, stack);
    stack.pop_back();
    return cycle_length;
}

int longestCycle(vector<int>& edges) {
    int n = edges.size();
    unordered_set<int> visited;
    int longest = -1;

    for (int i = 0; i < n; ++i) {
        if (!visited.count(i)) {
            vector<int> stack;
            int cycle_length = dfs(i, edges, visited, stack);
            longest = max(longest, cycle_length);
        }
    }

    return longest;
}

// Example usage:
int main() {
    vector<int> edges = {3, 3, 4, 2, 3};
    int result = longestCycle(edges);
    cout << "The length of the longest cycle is: " << result << endl;  // Output: 3
    return 0;
}
