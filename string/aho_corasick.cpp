//TO understand read : 
//https://www.youtube.com/watch?v=O7_w001f58c
//https://cp-algorithms.com/string/aho_corasick.html#construction-of-an-automaton
//http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf
//https://github.com/ekzhang/library/blob/master/aho_corasick.cpp
//understanding the concept of failure and out links is simple
//implementing the same using bfs is a bit confusing but can be understood as BFS traverses vertices in order of increasing length
//when we want to process a filure function for a node(x), we need to check failure fucntion of its parent parent->char x-> node, let the faulure node for parent be pf, then if we have pf->charx->some node y, the failure function of x will point to y 
//if pf ->charx doesnt have a node we recursively go to failure function of pf
//the idea is similar to KMP when we calculate LPS[i]  while(s[i]!= s[j]){ j = lps[j-1]}

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define MAXN 100013
int N; // size of dictionary
string dict[MAXN];
string text;

#define MAXM 100013
int M; // number of states in the automation
int g[MAXM][26]; // the normal edges in the trie
int f[MAXM]; // failure function
LL out[MAXM]; // output function
//in this implementation instead of storing the next output node, we store the number of output nodes

int aho_corasick() {
    memset(g, -1, sizeof g);
    memset(out, 0, sizeof out);

    int nodes = 1;

    // build the trie (normal isnertion)
    for (int i = 0; i < N; i++) {
        string& s = dict[i];
        int cur = 0;

        for (int j = 0; j < s.size(); j++) {
            if (g[cur][s[j] - 'a'] == -1) {
                g[cur][s[j] - 'a'] = nodes++;
            }
            cur = g[cur][s[j] - 'a'];
        }
        out[cur]++;
    }
    //if we do not see a character at root node -> again go back to root
    for (int ch = 0; ch < 26; ch++) {
        if (g[0][ch] == -1) {
            g[0][ch] = 0;
        }
    }

    // BFS to calculate out and failure functions
    memset(f, -1, sizeof f);
    queue<int> q;
    for (int ch = 0; ch < 26; ch++) {
        if (g[0][ch] != 0) {//we have a transition from 0 to that node
            //failure for node at depth 1 means root, out will remain same
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (!q.empty()) {
        //we have failure link for this node (we call it parent node)
        int state = q.front();
        q.pop();

        //we will now go to child nodes which we can visit from this node and calulate their fail and out
        for (int ch = 0; ch < 26; ch++) {
            if (g[state][ch] == -1) continue;

            //longest suffix which was also a prefix for the parent node
            int fail = f[state];
            //recursively go back till we have a suffix which has the current child node transition
            while (g[fail][ch] == -1) {
                fail = f[fail];
            }
           
            f[g[state][ch]] = g[fail][ch];
            out[g[state][ch]] += out[g[fail][ch]];

            q.push(g[state][ch]);
        }
    }

    return nodes;
}

LL search() {
    // Using the Aho-Corasick automation, search the text.
    int state = 0;
    LL ret = 0;
    for (char c : text) {
        while (g[state][c - 'a'] == -1) {
            state = f[state];
        }
        state = g[state][c - 'a'];
        ret += out[state];
    }
    // It's that simple!
    return ret;
}

int main() {
    // make I/O faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("aho_corasick.in", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dict[i];
    }
    cin >> text;

    M = aho_corasick();
    LL result = search();

    cout << result << endl;
    return 0;
}