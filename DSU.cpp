/*
 *  DSU (0 based indexing)
 *  Usage:
    * Pass N to the constructor
 */
struct DSU
{
    vector<int> parent, size;
    DSU(int n) {
        parent.assign(n, 0);
        size.assign(n, 1);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }
    int unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return 0;
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        parent[b] = a;
        return 1;
    }
};