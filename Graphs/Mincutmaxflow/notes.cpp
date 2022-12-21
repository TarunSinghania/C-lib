all examples tested on cf problem : https://codeforces.com/problemset/problem/546/E
quick revise : william fiset https://youtu.be/LdOnanfc5TM
for through revise : Tim Roughgarden Lectures on youtube, https://youtu.be/dorq_YA6plQ
    
todo: add edmund karp and dinic code

note : 
    methods to get max flow : 
        ford fulkerson
        edmonds karp 
        dinic
    concepts to know
    augumenting flow redidual graph blocking flow 
            
for ford fulkerson : 
    construct graph with residual edges 
    till time you get augementing flow(any additional flow keep going)
        find using dfs, can use any method - O(maxFlow*Edges)
        
for edmonds karp 2:
    augmenting flow is found using bfs, i.e shortest O(E^2*Ln(F)*ln(v));
    lnf - means base e
for edmond karp 1: 
    augmenting flow using fattest path, modified djisktra as below 
    0(E^2*V)
        
      
max augmenting flow at each step
        maxaugmenting flow at each step : 
            given a directed graph find a path(no vertice visited twice) such that we reach from s to t where the minimum of all edge weights is maximum 
        Widest Path Problem djisktra :
                 https://www.geeksforgeeks.org/widest-path-problem-practical-application-of-dijkstras-algorithm/
                 priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >q
                 max(min(widest_dist[u], weight(u, v)), widest_dist[v]) 