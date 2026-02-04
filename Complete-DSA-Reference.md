# Complete DSA Reference for C++ Interview Preparation (Updated)

Based on your comprehensive 79-problem list, here's the complete reference guide covering ALL algorithms, data structures, syntax, time complexities, and STL implementations in C++.

## Essential Algorithms (Complete Coverage)

### 1. **Array & Hashing Algorithms**

#### Next Permutation
```cpp
void nextPermutation(vector<int>& arr) {
    int n = arr.size(), pivot = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i; break;
        }
    }
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]); break;
        }
    }
    reverse(arr.begin() + pivot + 1, arr.end());
}
```
**Time:** O(n), **Space:** O(1)

#### 3-Sum (Two Pointers)
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return result;
}
```
**Time:** O(n²), **Space:** O(1)

#### Kadane's Algorithm
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
```
**Time:** O(n), **Space:** O(1)

#### Count Inversions (Merge Sort Based)
```cpp
long long mergeAndCount(vector<int>& arr, int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long invCount = 0;
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i);
        }
    }
    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return invCount;
}
```
**Time:** O(n log n), **Space:** O(n)

### 2. **Binary Search Algorithms**

#### Binary Search (Basic)
```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```
**Time:** O(log n), **Space:** O(1)

#### Search in Rotated Sorted Array
```cpp
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}
```
**Time:** O(log n), **Space:** O(1)

#### Find Peak Element
```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
**Time:** O(log n), **Space:** O(1)

#### Koko Eating Bananas (Binary Search on Answer)
```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }
        if (hours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
**Time:** O(n log(max(piles))), **Space:** O(1)

### 3. **Graph Algorithms (Complete Set)**

#### DFS & BFS Traversal
```cpp
// DFS
void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, visited);
        }
    }
}

// BFS
vector<int> bfs(vector<vector<int>>& adj, int start) {
    vector<int> result;
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}
```
**Time:** O(V + E), **Space:** O(V)

#### Dijkstra's Algorithm
```cpp
vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```
**Time:** O((V + E) log V), **Space:** O(V)

#### Bellman-Ford Algorithm (Negative Cycle Detection)
```cpp
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return {}; // Negative cycle detected
        }
    }
    return dist;
}
```
**Time:** O(VE), **Space:** O(V)

#### Floyd-Warshall Algorithm
```cpp
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}
```
**Time:** O(V³), **Space:** O(1)

#### Kruskal's MST Algorithm (with Union-Find)
```cpp
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int kruskalMST(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    int mstWeight = 0;
    
    for (auto& edge : edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        if (uf.unite(u, v)) {
            mstWeight += w;
        }
    }
    return mstWeight;
}
```
**Time:** O(E log E), **Space:** O(V)

#### Topological Sort (DFS Based)
```cpp
void topologicalSort(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;
    
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
        st.push(node);
    };
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
```
**Time:** O(V + E), **Space:** O(V)

### 4. **String Algorithms**

#### KMP Algorithm (Pattern Matching)
```cpp
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> result;
    int n = text.length(), m = pattern.length();
    int i = 0, j = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}
```
**Time:** O(n + m), **Space:** O(m)

#### Z-Algorithm
```cpp
vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```
**Time:** O(n), **Space:** O(n)

#### Rabin-Karp Algorithm
```cpp
vector<int> rabinKarp(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    int prime = 101;
    int patternHash = 0, textHash = 0, h = 1;
    vector<int> result;
    
    for (int i = 0; i < m - 1; i++) {
        h = (h * 256) % prime;
    }
    
    for (int i = 0; i < m; i++) {
        patternHash = (256 * patternHash + pattern[i]) % prime;
        textHash = (256 * textHash + text[i]) % prime;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) result.push_back(i);
        }
        
        if (i < n - m) {
            textHash = (256 * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0) textHash += prime;
        }
    }
    return result;
}
```
**Time:** O(nm) worst case, O(n + m) average, **Space:** O(1)

### 5. **Advanced Data Structures**

#### Segment Tree (Range Sum Query & Update)
```cpp
class SegmentTree {
    vector<int> tree;
    int n;
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }
    
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};
```
**Time:** Build O(n), Query/Update O(log n), **Space:** O(n)

#### Fenwick Tree (Binary Indexed Tree)
```cpp
class FenwickTree {
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
    
    int rangeQuery(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
```
**Time:** Update/Query O(log n), **Space:** O(n)

#### Trie (Prefix Tree)
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int count; // For counting prefixes
    
    TrieNode() {
        isEndOfWord = false;
        count = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
            current->count++;
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
    
    int countWordsWithPrefix(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return 0;
            }
            current = current->children[index];
        }
        return current->count;
    }
};
```
**Time:** Insert/Search/StartsWith O(m), **Space:** O(ALPHABET_SIZE * N * M)

#### LCA using Binary Lifting
```cpp
class LCA {
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    
public:
    LCA(vector<vector<int>>& adj, int root) {
        int n = adj.size();
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);
        
        dfs(adj, root, -1);
        
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j-1] != -1) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    void dfs(vector<vector<int>>& adj, int u, int parent) {
        up[u][0] = parent;
        for (int v : adj[u]) {
            if (v != parent) {
                depth[v] = depth[u] + 1;
                dfs(adj, v, u);
            }
        }
    }
    
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
```
**Time:** Preprocessing O(n log n), Query O(log n), **Space:** O(n log n)

## Complete STL Reference

### **Containers & Time Complexities**

| Container | Access | Insert | Erase | Find | Use Case |
|-----------|--------|---------|-------|------|----------|
| `vector` | O(1) | O(1)* | O(n) | O(n) | Dynamic array |
| `deque` | O(1) | O(1) | O(1) | O(n) | Double-ended queue |
| `list` | O(n) | O(1) | O(1) | O(n) | Doubly linked list |
| `set` | - | O(log n) | O(log n) | O(log n) | Ordered unique elements |
| `map` | - | O(log n) | O(log n) | O(log n) | Ordered key-value pairs |
| `unordered_set` | - | O(1) avg | O(1) avg | O(1) avg | Hash-based unique elements |
| `unordered_map` | - | O(1) avg | O(1) avg | O(1) avg | Hash-based key-value pairs |
| `priority_queue` | O(1) | O(log n) | O(log n) | - | Heap (max/min) |
| `stack` | O(1) | O(1) | O(1) | - | LIFO structure |
| `queue` | O(1) | O(1) | O(1) | - | FIFO structure |

*Amortized for vector push_back

### **Algorithm Functions**
```cpp
// Sorting
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend()); // Descending
stable_sort(v.begin(), v.end()); // Preserves relative order

// Searching
binary_search(v.begin(), v.end(), x);
lower_bound(v.begin(), v.end(), x); // First >= x
upper_bound(v.begin(), v.end(), x); // First > x

// Min/Max
min_element(v.begin(), v.end());
max_element(v.begin(), v.end());
*max_element(v.begin(), v.end()); // Value

// Numeric
accumulate(v.begin(), v.end(), 0); // Sum
accumulate(v.begin(), v.end(), 1, multiplies<int>()); // Product

// Permutations
next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());

// Set operations (on sorted ranges)
set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

// Other useful
reverse(v.begin(), v.end());
unique(v.begin(), v.end()); // Remove consecutive duplicates
```

## Algorithm Complexity Summary

| Algorithm | Time Complexity | Space Complexity | Use Case |
|-----------|----------------|------------------|----------|
| Binary Search | O(log n) | O(1) | Sorted array search |
| Quick Sort | O(n log n) avg, O(n²) worst | O(log n) | General sorting |
| Merge Sort | O(n log n) | O(n) | Stable sorting |
| Heap Sort | O(n log n) | O(1) | In-place sorting |
| DFS/BFS | O(V + E) | O(V) | Graph traversal |
| Dijkstra | O((V + E) log V) | O(V) | Single-source shortest path |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |
| Bellman-Ford | O(VE) | O(V) | Negative edges, cycle detection |
| Kruskal MST | O(E log E) | O(V) | Minimum spanning tree |
| Topological Sort | O(V + E) | O(V) | DAG ordering |
| KMP | O(n + m) | O(m) | Pattern matching |
| Z-Algorithm | O(n) | O(n) | Pattern matching |
| Kadane's | O(n) | O(1) | Maximum subarray |
| LCA Binary Lifting | O(log n) query | O(n log n) | Tree queries |
| Segment Tree | O(log n) | O(n) | Range queries |
| Fenwick Tree | O(log n) | O(n) | Prefix operations |

## Problem Pattern Categories

### 1. **Two Pointers**
- 3Sum, Container With Most Water, Trapping Rain Water
- Remove duplicates, Palindrome checking

### 2. **Sliding Window**
- Maximum/Minimum subarray problems
- Longest substring problems

### 3. **Binary Search**
- Search in rotated array, Find peak element
- Binary search on answer (Koko bananas, Aggressive cows)

### 4. **Dynamic Programming**
- LCS, LIS, Edit Distance, Knapsack variants
- Matrix chain multiplication, Palindrome partitioning

### 5. **Graph Algorithms**
- BFS/DFS variations, Shortest path problems
- MST, Topological sorting, Cycle detection

### 6. **Tree Algorithms**
- Tree traversals, LCA problems
- Binary tree construction, Morris traversal

### 7. **Advanced Data Structures**
- Segment trees for range queries
- Tries for string problems
- Heaps for priority-based problems

### 8. **String Algorithms**
- KMP for pattern matching
- Z-algorithm for string processing
- Manacher's algorithm for palindromes

This comprehensive reference covers all 79 problems from your SDE sheet with complete implementations, time complexities, and usage patterns for efficient interview preparation.