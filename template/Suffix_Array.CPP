#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define f first
#define s second
#define ar array
typedef vector<vector<int>> vvi;
typedef vector<int> vi;  
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;
class SuffixArray{
private:
    vi RA;
    void countingSort(int k){
        int maxi = max((int)300, n);
// up to 255 ASCII chars
        vi c(maxi, 0);
        // clear frequency table
        for (int i = 0; i < n; ++i)
        // count the frequency
        ++c[i+k < n ? RA[i+k] : 0];
        // of each integer rank
        for (int i = 0, sum = 0; i < maxi; ++i) {
        int t = c[i]; c[i] = sum; sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i)
        // sort SA
            tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
        swap(SA, tempSA);
    }
    void constructSA() {
// can go up to 400K chars
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0);
        // the initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i) RA[i] = T[i];
        // initial rankings
        for (int k = 1; k < n; k <<= 1) {
            // repeat log_2 n times
            // this is actually radix sort
            countingSort(k);
            // sort by 2nd item
            countingSort(0);
            // stable-sort by 1st item
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;
            // re-ranking process
            for (int i = 1; i < n; ++i)
            // compare adj suffixes
                tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
                ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k])) ?
                r : ++r;
            swap(RA, tempRA);
            // update RA
            if (RA[SA[n-1]] == n-1) break;
            // nice optimization
        }
    }
    void computeLCP(){
        vi Phi(n);
        vi PLCP(n);
        PLCP.resize(n);
        Phi[SA[0]] = -1;
        for (int i = 1; i < n; ++i)
        Phi[SA[i]] = SA[i-1];
        for (int i = 0, L = 0; i < n; ++i) {
            // compute PLCP in O(n)
            if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
            while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L]))
            ++L;
            // L incr max n times
            PLCP[i] = L;
            L = max(L-1, (int)0);
            // L dec max n times
        }
            LCP.resize(n);
            for (int i = 0; i < n; ++i)
            // compute LCP in O(n)
            LCP[i] = PLCP[SA[i]];
        }
public:
    const string T;
    const int n;
    vi SA;
    vi LCP;
    SuffixArray(const string initialT, const int _n) : T(initialT), n(_n) {
        constructSA();
        // O(n log n)
        computeLCP();
        // O(n)
    }
};