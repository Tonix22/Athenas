https://codeforces.com/contest/1637/problem/D?f0a28=1
//////////////////////////////////////////////////////////////////////////////

1. Find new formula
2. New formula change the problem to find minimun sum(A)^2 + sum(B)^2. 
3. This is a new problem because you don't need to square the sum of both anymore
4. Now you can concentrate in the total sum difference and find all possibilites, which in turn finds all 
    possible arrangements between the two arrays.
5. To find all difference you need to find a difference and then add it to all the previous ones and OR it in a bool array
    by doing this you ensure, the influence of one change is merged with any other change
    5.1 you can make a proof that following this prodecure you account for every combination of sum of differences
6. You can also do this by adding into a map or a queue. and every time iterating to the whole map. It can be ordered
7. You are effectively calculating all the possible combinations, but you are not recalculating EACH time the sum, you just add it to your search space
8. Then go to the ordered map of differences and add them to a max min sum. 
9. So you can add to the min and substract from the max using always positive integers (in both operands) we can order maxSum and minSum. (this is only more
    important when you can only have positive numbers and indexes, like an array. but since a map can have negatives it isn't as important)
10. Regardless of sign you always add the difference to one array and substract it from the other. To have the effect of swaping.
annex: another way of representing it is with a matrix, that display all the possible selections. like the one for the longest palindromic substring


You have to search (consider) all combinations always(combinatory is a huge deal in dp, because of overlapping substructures)
the important thing is find an optimal way to calculate those combinations.

You are not asked for each combination, but for the value of the sum of each combination.

For example the maximun palindromic substring when going back to its memo is to consider
how all other combinations affect the current one. Same for levishtein distance
produce value is not the same as producing the solution!! saying which combinations of arrays is minimun is different 
to saying the actual minimun

the common pattern of reading ther last index, is because the previous index contains the information of all the previous combinations at that poing
