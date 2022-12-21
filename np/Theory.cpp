O(1) – constant-time
O(log_2(n)) – logarithmic-time
O(n) – linear-time
O(n^2) – quadratic-time
O(n^k) – polynomial-time
O(k^n) – exponential-time
O(n!) – factorial-time
where k is a constant and n is the input size.


easy-p
med-np
hard-np complete
hardest - nphard

				----------------------------------------------|
				|												|
|------------------------------------
|				|					|			-----			|
|	NP Hard		|					|			|p	|			|
|				|  npcomplete		|			|----			|
|				|					|							|
|				|					|							|
|---------------|-------------------   np 						|
				|
				-------------------------------------------------
soduku - np (can check in polynomail time )
Multiplication - n


p or polynomial
T(n) = O(C * n^{k}) where C > 0 and k > 0 where C and k are constants and n is input size. In general, for polynomial-time algorithms k is expected to be less than n

NP Algorithms
T(n) = O(C_1 * k^{C_2 * n}) where C_1 > 0, C_2 > 0 and k > 0 where C_1, C_2 and k are constants and n is the input size. T(n) is a function of exponential-time when at least C_1=1 and C_2=1. As a result, we get O(k^n). 
NP is a class of problems whose solution is verifiable in polynomial time on a deterministic Turing machine

NP-complete
A problem is NP-complete if it is both NP and NP-hard. NP-complete problems are the hard problems in NP.

nphard	
A problem is NP-hard if an algorithm for solving it can be translated into one for solving any NP-problem (nondeterministic polynomial time) problem. NP-hard therefore means "at least as hard as any NP-problem," although it might, in fact, be harder.
What does NP-hard mean?
– A lot of times you can solve a problem by reducing it to
a different problem. I can reduce Problem B to
Problem A if, given a solution to Problem A, I can easily
construct a solution to Problem B. (In this case,
"easily" means "in polynomial time.“).
• A problem is NP-hard if all problems in NP
are polynomial time reducible to it
