// space [2^n][n]
// time [2^n][n]

//https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
//The cell dp[j][i] checks if there is a path that visits each vertex in subset represented by mask i and ends at vertex j.

function check_using_dp(adj[][], n)
    for i = 0 to 2n
        for j = 0 to n
            dp[j][i] = false
    for i = 0 to n
        dp[i][2i] = true
    for i = 0 to 2n
        for j = 0 to n
            if jth bit is set in i
                for k = 0 to n
                    if j != k and kth bit is set in i and adj[k][j] == true
                        if dp[k][ i  XOR 2j ] == true  

                            dp[j][i]=true
                            break
    for i = 0 to n
        if dp[i][2n-1] == true
            return true
    return false