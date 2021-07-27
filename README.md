# Introduction
------------

The program consists of modeling and implementing, by Branch & Bound, the Maximum Walk problem, aka longest path in a directed weighted graph.
The problem is NP complete therefore the bruteforce approach is necesary.

## Brench And Bound
The folowing log represents the execution whith the branch and bound opmizations uncommented.
Most of the opmizations bound happen right afther the recursive call of the deep search function.
Olny some of  them happen during main search function.
More especificaly olny the last two bound wore choped from the main search function in this log.

Another silent optimzasiton was comenting the line 395 ```//visited->a[i] = false;``` in the file ```lib_caminhada.h```.
This improvement makes the program ignore some of the previously searched nodes.
To better understand this change it is necessary to observe the visited array values and compare before and afther the change.

Before the bound optimization the search function run 60 times for the input file 2.
Afther the bound optimization the search function run only 18 times for the input file 2.
It is 3.3 times faster in this particular case.

Before and Afther the optimizations the Time Complexity O(N!) and Space Complexity O(N²) stays the same because the improvements are not garanteed to work on every node of every graph.


```c
time ./caminhada <input2.in >output2.out
number_of_vertices = 6

 Adjacency Matrix:
6:{
0:{ 0, 1, 1, 0, 0, 0}
1:{ 1, 0, 0, 1, 0, 0}
2:{ 1, 0, 0, 1, 0, 0}
3:{ 0, 1, 1, 0, 1, 0}
4:{ 0, 0, 0, 1, 0, 1}
5:{ 0, 0, 0, 0, 1, 0}
}

 Adjacency Array:
6:{
0:{2,  3}
1:{1,  4}
2:{1,  4}
3:{2,  3,  5}
4:{4,  6}
5:{5}
}
void hamCycle(graph_t *graph)
FindAllCycles, pos:1, path[1]: 0                    , visited:100000,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:2, path[2]: 1-> 1                , visited:110000,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:3, path[3]: 1-> 2-> 3            , visited:110100,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:4, path[4]: 1-> 2-> 4-> 2        , visited:111100,  1-> 2-> 4-> 3-> 1          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:4, path[4]: 1-> 2-> 4-> 4        , visited:110110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:2, path[2]: 1-> 2                , visited:101000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 1-> 3-> 3            , visited:101100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 1-> 3-> 4-> 1        , visited:111100,  1-> 3-> 4-> 2-> 1          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:4, path[4]: 1-> 3-> 4-> 4        , visited:101110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:1, path[1]: 1                    , visited:110000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 2-> 3                , visited:110100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 2-> 4-> 2            , visited:111100,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:3, path[3]: 2-> 4-> 4            , visited:110110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:1, path[1]: 2                    , visited:111000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 3-> 3                , visited:111100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 3-> 4-> 4            , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:1, path[1]: 3                    , visited:111100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 4-> 4                , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.

FindAllCycles, pos:1, path[1]: 4                    , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4

BRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.


BRENCH AND BOUND OPTIMIZATION2: graph->adjacency_array[v:5].l:1 < 2, skipp next set of recursive executions because they will not find longest cycle.
BRENCH AND BOUND OPTIMIZATION2: If the degree of the vertex is lass than two (aka zero or one) skipp.

4
1 2 4 3 1
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 1588maxresident)k
0inputs+8outputs (0major+70minor)pagefaults 0swaps
```
### Input
It starts with the number of places, n. Then we have n-1 lines,
representing an n × n symmetric matrix, A = [aij ], with the bonds and
the weights. This matrix is represented only by values aij with
i < j. That is, the first line has n−1 numbers, representing the values of a12, a13, . . . , a1n; the second line has the values of a23, . . . , a2n;
line i has the values ai(i+1), . . . , aye. The main diagonal values
are 0 (that is, aii = 0, for all 1 ≤ i ≤ n). If aij = 0, with i 6 = j
(off the main diagonal) then there is no connection between place i
and place j. The time to traverse a connection between places i and j and
given by aij . The starting place is place 1.

### Output
A line with the value of the maximum walk total time. In followed by a line with the sequence of places traveled. place 1 it must be the first and the last.

# Compile
To compile typing ```make compile``` on terminal. To compile, run tests and log test results type ```make all```, or just ```make```.
The important most files are ```caminhada2.c``` where there is the main funcion; ```lib_caminhada.h``` and ```lib_caminhada.c``` is where the auxiliary library is implemented;


### Graph and its representations
The following two are the most commonly used representations of a graph. 
1. Adjacency Matrix 
2. Adjacency List 
There are other representations also like, Incidence Matrix and Incidence List. The choice of graph representation is situation-specific. It totally depends on the type of operations to be performed and ease of use.

#### Adjacency Matrix
Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.
Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).
Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.
#### Adjacency List 
An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph. 


# Examples
------------

Example of lp solve input
An example, taken from another problem, can be seen below.

```c
4
1 1 0
5 1
1
```


## EX1
to run this example type make run on terminal

### Input 1
```c
4
1 1 0
5 1
1
```

### Output 1
```c
7
1 2 3 1
```

### Solution 1 by pl_solve

## EX2
to run this example type make run2 on terminal

### Input 2
```c
6
1 1 0 0 0
0 1 0 0
1 0 0
1 0
1
```

### Output 2
```c
4
1 2 4 3 1
```

### Execution Log 1
```c
time ./caminhada <input.in >output.out
number_of_vertices = 4

 Adjacency Matrix:
4:{
0:{ 0, 1, 1, 0}
1:{ 1, 0, 5, 1}
2:{ 1, 5, 0, 1}
3:{ 0, 1, 1, 0}
}

 Adjacency Array:
4:{
0:{2,  3}
1:{1,  3,  4}
2:{1,  2,  4}
3:{2,  3}
}
void hamCycle(graph_t *graph)
FindAllCycles, pos:1, path[1]: 0            , visited:1000,                     , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:2, path[2]: 1-> 1        , visited:1100,                     , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:3, path[3]: 1-> 2-> 2    , visited:1110,  1-> 2-> 3-> 1      , Common     , lenght: 7, maxlenght: 7, MaxCycle[4]: 1 2 3 1
FindAllCycles, pos:4, path[4]: 1-> 2-> 3-> 3, visited:1111,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:3, path[3]: 1-> 2-> 3    , visited:1101,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:4, path[4]: 1-> 2-> 4-> 2, visited:1111,  1-> 2-> 4-> 3-> 1  , Hamiltonian, lenght: 4, maxlenght: 7, MaxCycle[4]: 1 2 3 1
FindAllCycles, pos:2, path[2]: 1-> 2        , visited:1010,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:3, path[3]: 1-> 3-> 1    , visited:1110,  1-> 3-> 2-> 1      , Common     , lenght: 7, maxlenght: 7, MaxCycle[4]: 1 2 3 1
FindAllCycles, pos:4, path[4]: 1-> 3-> 2-> 3, visited:1111,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:3, path[3]: 1-> 3-> 3    , visited:1011,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:4, path[4]: 1-> 3-> 4-> 1, visited:1111,  1-> 3-> 4-> 2-> 1  , Hamiltonian, lenght: 4, maxlenght: 7, MaxCycle[4]: 1 2 3 1
FindAllCycles, pos:1, path[1]: 1            , visited:1100,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:2, path[2]: 2-> 2        , visited:1110,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:3, path[3]: 2-> 3-> 3    , visited:1111,  2-> 3-> 4-> 2      , Common     , lenght: 7, maxlenght: 7, MaxCycle[4]: 1 2 3 1
FindAllCycles, pos:2, path[2]: 2-> 3        , visited:1101,                     , No Cycle   , lenght: 0, maxlenght: 7
FindAllCycles, pos:3, path[3]: 2-> 4-> 2    , visited:1111,  2-> 4-> 3-> 2      , Common     , lenght: 7, maxlenght: 7, MaxCycle[4]: 1 2 3 1
7
1 2 3 1
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 1640maxresident)k
0inputs+8outputs (0major+72minor)pagefaults 0swaps
```

### Execution Log 2
```c
time ./caminhada <input2.in >output2.out
number_of_vertices = 6

 Adjacency Matrix:
6:{
0:{ 0, 1, 1, 0, 0, 0}
1:{ 1, 0, 0, 1, 0, 0}
2:{ 1, 0, 0, 1, 0, 0}
3:{ 0, 1, 1, 0, 1, 0}
4:{ 0, 0, 0, 1, 0, 1}
5:{ 0, 0, 0, 0, 1, 0}
}

 Adjacency Array:
6:{
0:{2,  3}
1:{1,  4}
2:{1,  4}
3:{2,  3,  5}
4:{4,  6}
5:{5}
}
void hamCycle(graph_t *graph)
FindAllCycles, pos:1, path[1]: 0                    , visited:100000,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:2, path[2]: 1-> 1                , visited:110000,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:3, path[3]: 1-> 2-> 3            , visited:110100,                             , No Cycle   , lenght: 0, maxlenght: 0
FindAllCycles, pos:4, path[4]: 1-> 2-> 4-> 2        , visited:111100,  1-> 2-> 4-> 3-> 1          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:4, path[4]: 1-> 2-> 4-> 4        , visited:110110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 1-> 2-> 4-> 5-> 5    , visited:110111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 1-> 2                , visited:101000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 1-> 3-> 3            , visited:101100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 1-> 3-> 4-> 1        , visited:111100,  1-> 3-> 4-> 2-> 1          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:4, path[4]: 1-> 3-> 4-> 4        , visited:101110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 1-> 3-> 4-> 5-> 5    , visited:101111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:1, path[1]: 1                    , visited:010000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 2-> 0                , visited:110000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 2-> 1-> 2            , visited:111000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 2-> 1-> 3-> 3        , visited:111100,  2-> 1-> 3-> 4-> 2          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:5, path[5]: 2-> 1-> 3-> 4-> 4    , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:6, path[6]: 2-> 1-> 3-> 4-> 5-> 5, visited:111111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 2-> 3                , visited:010100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 2-> 4-> 2            , visited:011100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 2-> 4-> 3-> 0        , visited:111100,  2-> 4-> 3-> 1-> 2          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:3, path[3]: 2-> 4-> 4            , visited:010110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 2-> 4-> 5-> 5        , visited:010111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:1, path[1]: 2                    , visited:001000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 3-> 0                , visited:101000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 3-> 1-> 1            , visited:111000,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 3-> 1-> 2-> 3        , visited:111100,  3-> 1-> 2-> 4-> 3          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:5, path[5]: 3-> 1-> 2-> 4-> 4    , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:6, path[6]: 3-> 1-> 2-> 4-> 5-> 5, visited:111111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 3-> 3                , visited:001100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 3-> 4-> 1            , visited:011100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 3-> 4-> 2-> 0        , visited:111100,  3-> 4-> 2-> 1-> 3          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:3, path[3]: 3-> 4-> 4            , visited:001110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 3-> 4-> 5-> 5        , visited:001111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:1, path[1]: 3                    , visited:000100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 4-> 1                , visited:010100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 4-> 2-> 0            , visited:110100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 4-> 2-> 1-> 2        , visited:111100,  4-> 2-> 1-> 3-> 4          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:2, path[2]: 4-> 2                , visited:001100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 4-> 3-> 0            , visited:101100,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 4-> 3-> 1-> 1        , visited:111100,  4-> 3-> 1-> 2-> 4          , Common     , lenght: 4, maxlenght: 4, MaxCycle[5]: 1 2 4 3 1
FindAllCycles, pos:2, path[2]: 4-> 4                , visited:000110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 4-> 5-> 5            , visited:000111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:1, path[1]: 4                    , visited:000010,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 5-> 3                , visited:000110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 5-> 4-> 1            , visited:010110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 5-> 4-> 2-> 0        , visited:110110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 5-> 4-> 2-> 1-> 2    , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 5-> 4-> 2            , visited:001110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 5-> 4-> 3-> 0        , visited:101110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 5-> 4-> 3-> 1-> 1    , visited:111110,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 5-> 5                , visited:000011,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:1, path[1]: 5                    , visited:000001,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:2, path[2]: 6-> 4                , visited:000011,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:3, path[3]: 6-> 5-> 3            , visited:000111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 6-> 5-> 4-> 1        , visited:010111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 6-> 5-> 4-> 2-> 0    , visited:110111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:6, path[6]: 6-> 5-> 4-> 2-> 1-> 2, visited:111111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:4, path[4]: 6-> 5-> 4-> 2        , visited:001111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:5, path[5]: 6-> 5-> 4-> 3-> 0    , visited:101111,                             , No Cycle   , lenght: 0, maxlenght: 4
FindAllCycles, pos:6, path[6]: 6-> 5-> 4-> 3-> 1-> 1, visited:111111,                             , No Cycle   , lenght: 0, maxlenght: 4
4
1 2 4 3 1
0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 1576maxresident)k
0inputs+8outputs (0major+71minor)pagefaults 0swaps
```


### Sources Used in this project
https://www.geeksforgeeks.org/print-all-the-cycles-in-an-undirected-graph/
https://www.geeksforgeeks.org/print-all-hamiltonian-cycles-in-an-undirected-graph/
https://www.geeksforgeeks.org/queue-linked-list-implementation/
https://github.com/coldwarrior5/Graph-analyser
