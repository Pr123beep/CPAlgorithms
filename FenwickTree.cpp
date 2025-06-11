struct Node
{
    int val;
    Node(int val = 0) : val(val) {}
};

Node operator + (Node a, Node b)
{
    return Node(a.val + b.val); 
}

template<typename T>
struct FenwickTree
{
    vector<T> tree;
    const int n;
    const T identity;

public:
    FenwickTree(int n, T identity) : n(n), identity(identity)
    {
        tree.assign(n + 1, identity);
    }

    void update(int idx, T delta)
    {
        for (++idx; idx <= n; idx += idx & -idx)
            tree[idx] = tree[idx] + delta;
    }

    T query(int idx)
    {
        T res = identity;
        for (++idx; idx > 0; idx -= idx & -idx)
            res = res + tree[idx];
        return res;
    }

    T query(int l, int r)
    {
        return query(r) + (identity - query(l - 1)); // identity - A = inverse if needed
    }
};
