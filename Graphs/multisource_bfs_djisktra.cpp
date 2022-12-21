BFS:

multi-source bfs  : push all source at once in queue with distance 0

Another way to think about multiple sources that's potentially nicer to code is to add a fake source with edges to all the real sources, then BFS as normal, then subtract 1 from all the distances.


Djisktra :


Same for Djisktra