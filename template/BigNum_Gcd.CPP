#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define ar array
typedef vector<vector<int>> vvi;
typedef vector<int> vi;  
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;

int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
 
int reduceB(int a, string b)
{
    // Initialize result
    int mod = 0;
 
    // calculating mod of b with a to make
    // b like 0 <= b < a
    for (int i = 0; i < b.size(); i++)
        mod = (mod * 10 + b[i] - '0') % a;
 
    return mod; // return modulo
}
 
int gcdLarge(int a, string b)
{
    // Reduce 'b' (second number) after modulo with a
    int num = reduceB(a, b);
 
    // gcd of two numbers
    return gcd(a, num);
}