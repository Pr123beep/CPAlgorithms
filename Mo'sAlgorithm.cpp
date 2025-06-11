static const int MAXN = 200000;
int B;
vector<int> A, freq;
int curAns;

// Add/Remove as free functions
void add(int i){
    if (freq[A[i]]++ == 0) ++curAns;
}
void remove_(int i){
    if (--freq[A[i]] == 0) --curAns;
}

struct Query {
    int L, R, idx;
    bool operator<(Query const &o) const {
        int b1 = L/B, b2 = o.L/B;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (R > o.R) : (R < o.R);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    for(int &x : A) cin >> x;

    // (coordinate‐compress if needed) …

    B = max(1, int(sqrt(N)));
    vector<Query> qs(Q);
    for(int i = 0; i < Q; i++){
        cin >> qs[i].L >> qs[i].R;
        --qs[i].L; --qs[i].R;
        qs[i].idx = i;
    }
    sort(qs.begin(), qs.end());

    freq.assign(/* M = #distinct values */, 0);
    curAns = 0;

    vector<int> ans(Q);
    int curL = 0, curR = -1;
    for(auto &q : qs){
        while(curL >  q.L) add(--curL);
        while(curR <  q.R) add(++curR);
        while(curL <  q.L) remove_(curL++);
        while(curR >  q.R) remove_(curR--);
        ans[q.idx] = curAns;
    }

    for(int x : ans) 
        cout << x << "\n";
    return 0;
}
