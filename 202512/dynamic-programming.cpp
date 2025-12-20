#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long fib(int n) {
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

long long fib_tab(int n) {
    if (n <= 1)
        return n;

    vector<long long> table(n + 1);
    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
        table[i] = table[i - 2] + table[i - 1]; // keep adding up

    return table[n];
}

long long fib_memo(int n, vector<long long> &memo) {
    if (n <= 1)
        return n;

    // already calculated
    if (memo[n] != -1)
        return memo[n];

    // calculate
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);

    return memo[n];
}

long long fib_embed(int n) {
    if (n <= 1)
        return n;

    long long val = 1;
    long long prev = 1;
    long long pprev = 0;

    for (int i = 2; i < n; i++) {
        val = prev + pprev; // keep adding up
        pprev = prev;
        prev = val;
    }

    return val;
}

int main() {
    int n = 51;
    /* 1. recursive */
    // cout << fib(n) << endl;

    /* 2. tabulation */
    // cout << fib_tab(n) << endl;

    /* 3. memoisation */
    // vector<long long> memo(n + 1, -1);
    // cout << fib_memo(n, memo) << endl;
    // for (auto n : memo)
    //     cout << n << " ";
    // cout << endl;

    /* 4. efficient memory (embedded) */
    cout << fib_embed(n) << endl;
    return 0;
}