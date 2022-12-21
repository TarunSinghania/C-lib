
1

If you think about it, the worst case for matching the pattern is the one in which you've to visit each index of the LPS array, when mismatch occurs. For example, pattern "aaaa" which creates LPS arrays as [0,1,2,3] makes it possible.

Now, for the worst case matching in the text, we want to maximize the such mismatches that forces us to visit all the indices of the LPS array. That would be a text with repeated pattern, but with the last character as a mismatch. For example, "aaabaaacaaabaaacaaabaaac".

Let the length of the text be n and that of pattern be m. Number of the occurences of such pattern in the text is n/m. And for each of these occurences, we are performing m comparisions. Not to forget that we are also traversing n characters of the text.

Therefore, the worst case time for KMP matching would be O(n + (n/m)*m), which is basically O(n).

Total worst case time complexity, including LPS creation, would be O(n+m).

two variables i, j 
string[i] and pattern[j]

So, for every iteration through the while loop, we can expect one of three things to occur:

    We find a match, and hence increment both i and j, hence k remains the same
    There is a mismatch but j > 0, so i does not change and hence we can say that k increases by at least 1 since k changes from i - j to i - LPS[j - 1]
    There is a mismatch but this time j = 0, hence i is incremented and k increases by 1.

  max number of decrements = (string length/pattern length)*pattern length = string length
  