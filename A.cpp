// minum distance with point in Ox
#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
// #define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
#endif
using namespace std;
#define int long long
// #define ll long long
#define LL __int128
#define ld long double
#define f first
#define s second
#define ar array
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;
vi toX = {1, -1, 0, 0}, toY = {0, 0, 1, -1};
const int inf = 1e18;
void bfs(int r, int c, vector<vi> adj, int R, int C, vector<vi> &dist){
    int vis[R + 5][C + 5];
    memset(vis, 0, sizeof vis);
    queue<ar<int,2>> q;
    dist[r][c] = 0;
    q.push({r, c});
    while(!q.empty()){
        auto [a, b] = q.front(); q.pop();
        if(vis[a][b]) continue;
        vis[a][b] = 1;
        for(int i = 0; i < 4; ++i){
            int _x = a + toX[i], _y = b + toY[i];
            if(_x > R || _x <= 0 || _y > C || _y <= 0) continue;
            if(!vis[_x][_y]){
                dist[_x][_y] = min(dist[_x][_y], dist[a][b] + 1);
                if(adj[_x][_y] == 0){
                    q.push({_x, _y});
                }
            }
        }
    }
}
void test_case(){
    int R, C, N, r, c;
    cin>>R>>C>>N>>r>>c;
    vector<vi> dist(R + 5, vi(C + 5, inf));
    vector<vi> adj(R + 5, vi(C + 5));
    vector<pi> start, wall;
    for(int i = 1; i <= N; ++i){
        int a,b; cin>>a>>b;
        start.push_back({a, b});
    }
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            char s; cin>>s;
            if(s == 'W'){
                adj[i][j] = 1;
                wall.push_back({i, j});
            }
        }
    }
    bfs(r, c, adj, R, C, dist);
    int res1 = 0, res2 = 0;
    for(auto [a, b] : start){
        vector<vi> d(R + 5, vi(C + 5, inf));
        bfs(a, b, adj, R, C, d);
        if(dist[a][b] != inf){
            res1 += dist[a][b];
            for(auto [x, y] : wall){
                res2 += abs(min(d[r][c] ,(d[x][y] + dist[x][y])) - d[r][c]);
            }
        }else{
            for(auto [x, y] : wall){
                if(d[x][y] + dist[x][y] < inf){
                    res2 += d[x][y] + dist[x][y];
                }
            }
        }
    }
    cout<<res1<<" "<<res2<<"\n";
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin>>t;
    for(int i = 0; i < t; ++i){
        test_case();
    }
}