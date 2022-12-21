 
/**
	A directed graph has an Eulerian cycle if and only if every node has an
	in-degree equal to its out-degree, and all of its nodes with nonzero degree
	belong to a single strongly connected component.
 
	A directed graph has an Eulerian path if and only if it is strongly connected and
	each vertex except 2 have the same in-degree as out-degree, and one of those 2
	vertices has out-degree with one greater than in-degree (this is the start vertex),
	and the other vertex has in-degree with one greater than out-degree (this is the end vertex).
 
	The code below works for both cases. For Euler Path, make sure that you call the function
	with the appropriate start vertex.
**/
 
std::vector<int> find_path_directed(std::vector<int> adj[], int u) {
  std::vector<int> stack, curr_edge(MAXN), res;
  stack.push_back(u);
  while (!stack.empty()) {
    u = stack.back();
    stack.pop_back();
    while (curr_edge[u] < (int)adj[u].size()) {
      stack.push_back(u);
      u = adj[u][curr_edge[u]++];
    }
    res.push_back(u);
  }
  std::reverse(res.begin(), res.end());
  return res;
}

or see ashish gupta