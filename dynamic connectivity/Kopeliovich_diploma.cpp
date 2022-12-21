For the dynamic connectivity problem, there is a simple offine solution in O(k log k) time, where k is the total number of queries. This Decision in 1992 proposed by David Eppstein, detailed description can be found in the article [3].

for the dynamic 2-edge-connectivity problem, the best online solution proposed in 2000 by Mikkel Thorup [4]. Change Request the graph is processed in O(log3 n log log n) time. Onine Solutions, asymptotically superior data does not exist.This work describes a simple Offine solution to the problem dynamic 2-edge-connectivity problem running in O(k log k) time, where k is total number of requests. In addition to the new O(k log k) algorithm for dynamic 2-edge-connectivity problem.
In this work, various approaches to the construction of Offline Solutions to dynamic graph problems. 




2.1 Statement of the problem
In this work, we will talk about the tasks of searching for the connectivity component
and component of edge biconnection in dynamically varying unoriented columns. Column G is called 〈V, E〉, where V the set of vertices of the graph, E ⊂ V × V the set of edges of the graph. |V|
let us denote za n, |E| let's designate za m.
Column Change Requests:
1. Add an edge
2. Remove the rib
Such queries, following the terminology introduced in the English language
Literature, will be called update-queries.
Queries to the current state of the data structure:
1. For two vertices, determine whether they lie in one component
connectivity (and, correspondingly, edge biconnectivity).
2. For the column, say how much the connectivity component is in it (ribbon
biconnectivity).
Such requests will be called get requests.


2.2 Symbols

The total number of requests (both update requests and get requests) in the future
symbolize k.For the simplicity of estimating the complexity time of the algorithms described below,

Let's assume that graph is initially empty. If we want to
it originally already had m ribs, you can add them by making additional update requests to add.

In some algorithms for analyzing the complexity, I useinverse Akkerman function. The reason for its appearance in my workApplication of SOM (system of non-intersecting plurality). Howknown from [1], the amortization time per request for this structuredata is α(n, m). In this work, for the sake of brevity and beauty, the formulasI will use the notation α in the future.At work, use the terms offine task, online task.

When designing data structures that respond to user queries
one of two situations is possible:
1. All requests are known in advance. In such a case, this is offline a problem.
2. Before answering the next request, you must answer
on the previous one. In that case, this is an online task.


2.3 English terms

In the course of all work, you will use the names of tasks,
borrowed from the English literature.
Tasks included in support
1. Connectivity component
2. Edgewise Biconnection Component
3. Minimum by weight core tree
on dynamically changing graphs, in English literature
called, respectively
1. fully dynamic connectivity
2. fully dynamic 2-edge connectivity
3. fully dynamic minimum spanning tree
The term minimum core tree by weight for the sake of brevity
MST symbol (short for minimum spanning tree)



2.4 Briefly about the following chapters
The work consists of several chapters. The division into chapters is done so
the way that you should read the chapters in sequence.
In chapter [3] the history of the study of the problem is described in detail. In the chapter
[4] Describes the auxiliary data structures used in the Solutions to the challenges of fully dynamic connectivity and 2-edge-connectivity.
In chapter [5] there is a clear description of the format of the input data of the algorithms,
which will solve the problems of fully dynamic connectivity and 2-edge-
connectivity.
Later in chapter [6] the solutions known to me o ine are described in detail fully
dynamic connectivity problem. At the end of this chapter [6.5] is a description
new o ine algorithm.
Finally, in chapter [7] the most interesting part of the work is presented.
new offine solution to the fully dynamic 2-edge-connectivity problem. Â òîæå
In the chapter, in part [7.1], the optimal solution of the problem is described in the case when
The ribs are only added to the head.

Chapater 3 discussed old work time complexity
chapter 4 , shows dsu and rolback operation is possible if we reverse steps

this is just to mimic disconnect(a,b) after connect(a,b).b
when connect(a,b) is run we can store all operations in memory on a stack and then undo them
for disconnect(a,b).

note: this is not like we can disconnect(a,b) at any time, as at a random point we wont know what will happen will these result in two componets or just one.

But if order of connects is presevered we can unorder or go back in time 

connect(a,b) connect(b,c) connect(a,c) connect(a,d)
 
we can then go back if we undo memory operations in order for connect(a,d) connect(a,c) connect(b,c) connect(a,b)



5 Input data format
In this chapter, we will define the format of the input data and make the first step in solving an arbitrary problem from the area of dynamic graphs
Let's convert the format of the input data to a form convenient for work.So, the input data. Two kinds of update-query steps."ADD a b", "DEL a b". Guaranteed that the moment you step"DEL a b" query, there is an edge in the graph. Necessary after eachupdate-query to know the current number of connectivity components (or, respectively, edge-to-edge) and be able to respond to a get-request.GET a b" are vertices a and b in the same connection component (or,correspondence, edge biconnection). Let the total number of queries (both get and update) be k. Inquiries.

let's enumerate by numbers from 0 to k −1 (q0, q1, . . . , qk−1). Says that we have k + 1 instant of time (at the i-th instant of time, all update queries with numbers from 0 to i−1). Budem also says that i-th occurrence of the event at time i. 
We solve the problem offine, i.e. all inquiries are available to us in advance.

Therefore, all update queries can be modified by the following edge ha bi at time L add, at time
R delete. L Request number "ADD a b". R request number "DEL a b" at the moment of time k + 1.
Now we have a pair of requests ADD, DEL instead of a pair of requests ha, b, L, Ri
add an edge ha, bi so that it is present at all times from
L+1 to R inclusive. This transformation of update queries, if
we used subcount sort, which took us O(k + n) time.
New update queries will also be called query edges.
As a result, we have queries of type get (q.type = get), and queries-edges
(q.type = update). There are properties q.a, q.b of the number in update-queries
vertices, which connects the edge and q.L, q.R moments of time when
The edge adds and removes, respectively.
Query array input q.

todo