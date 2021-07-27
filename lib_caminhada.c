/*
 * lib_caminhada.h
 * 
 * Copyright 2021 jcld14 <jcld14@jcld14-Virtual-Machine>
 * Julio Doebeli
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */



#ifndef _LIB_CAMINHDA_C_
#define _LIB_CAMINHDA_C_


#include "lib_caminhada.h"

void intArrayInitialize(longArray_t* A) {
	A->s=0;
	A->l=0;
	A->a=NULL;
}


longArray_t* longArrayAlloc() {
	longArray_t *A = (longArray_t*)malloc(sizeof(longArray_t));
	A->s=0;
	A->l=0;
	A->a=NULL;
	return A;
}

longArray2_t* longArray2Alloc() {
	longArray2_t *A = (longArray2_t*)malloc(sizeof(longArray2_t));
	A->s=0;
	A->l=0;
	A->a=NULL;
	return A;
}


int push_back(longArray_t *A, long itg) {
	if (A->s<=0 && A->l<=0 && A->a==NULL) {
		A->a = (long*)malloc(sizeof(long)*2);
		if (A->a == NULL)
			return -1;
		A->s=2;
		A->l=1;
		A->a[0] = itg;
		return 1;
	}
	
	if (A->s > A->l) {
		A->a[A->l] = itg;
		A->l++;
		return 2;
	}
	
	if (A->s == A->l) {
		A->a = (long*)realloc(A->a, sizeof(long)*(A->s+4));
		if (A->a == NULL)
			return -3;
		A->s = A->s +4;
		A->a[A->l] = itg;
		A->l+=1;
		return 3;
	}
	return 0;
}

int push_back2(longArray2_t *A, long index, long itg) {
	//op 1: size of longArray2_t is 0
		//detection 1: (A->s)<=0 or
		//detection 2: (A->a)==NULL
	if (A->s<=0 || A->a==NULL) {
		A->a = (longArray_t**)malloc(sizeof(longArray_t*)*(index+1));
		if (A->a == NULL)
			return -1;
		A->s=(index+1);
		A->l=(index);
		for (int i=0; i<(A->s); i++){
			A->a[i] = NULL;
		}
		if (A->a[index] == NULL)
			A->a[index] = longArrayAlloc();
		if (A->a[index] == NULL)
			return -2;
		push_back(A->a[index], itg);
		return 1;
	}
		
	//op 2: (0<=index) && (index<=length)
	if ((0)<=index && index<(A->l)) {
		if (A->a[index] == NULL)
			A->a[index] = longArrayAlloc();
		if (A->a[index] == NULL)
			return -3;
		if (push_back(A->a[index], itg) < 0){
			return -4;
		}
		return 2;
	}
	
	//op 3: (length<index) && (index<size)
	if ((A->l)<=index && index<(A->s)) {
		if (index > (A->l+1)){
			return -5;
		}
		if (A->a[index] == NULL){
			A->a[index] = longArrayAlloc();
		}
		if (A->a[index] == NULL){
			return -6;
		}
		if (push_back(A->a[index], itg) < 0){
			return -7;
		}
		A->l = index;
		return 3;
	}
	
		
	//op 3: (index==size+1)
	if (A->s == A->l) {
		A->a = (longArray_t**)realloc(A->a, sizeof(longArray_t*)*(A->s+4));
		if (A->a == NULL)
			return -8;
		if (A->a[index] == NULL){
			A->a[index] = longArrayAlloc();
		}
		if (A->a[index] == NULL){
			return -9;
		}
		if (push_back(A->a[index], itg) < 0){
			return -10;
		}
		A->l = index;
		return 3;
	}
	return 0;
}

long pop_back( longArray_t *A) {
	if (A->l > 0) {
		A->l--;
		return A->a[A->l+1];
	} else {
		return 0;
	}
}

void print_long_array(long *A, long n) {
	if (A==NULL) {
		fprintf(stderr,"{NULL}");
		return;
	}
	fprintf(stderr,"{");
	for (long i = 0; i < n-1; i++) {
		fprintf(stderr," %ld,", A[i]);
	}
	if (n > 1)
		fprintf(stderr," %ld", A[n-1]);
	fprintf(stderr,"}\n");
}

void print_long_matrix(long **M, long n, long m) {
	if (M==NULL) {
		fprintf(stderr,"{NULL}");
		return;
	}
	fprintf(stderr,"%ld:{\n",n);
	for (long i = 0; i < n; i++) {
		fprintf(stderr,"%ld:",i);	
		print_long_array(M[i], m);
	}
	fprintf(stderr,"}\n");
}

void print_intArray( longArray_t *A) {
	if (A==NULL) {
		fprintf(stderr,"A{NULL}");
		return;
	}
	fprintf(stderr,"{");
	for (long i = 0; i < A->l; i++) {
		if (i != 0)
			fprintf(stderr," ");
		fprintf(stderr,"%ld",A->a[i]);
		if (i != A->l - 1)
			fprintf(stderr,", ");
	}
	fprintf(stderr,"}\n");	
}

void print_n_intArray(long number_of_arrays, longArray_t *A) {
	fprintf(stderr,"%ld:{\n", number_of_arrays);
	for (long i = 0; i <number_of_arrays; i++) {
		fprintf(stderr,"%ld:",i);	
		print_intArray(&A[i]);
	}
	fprintf(stderr,"}\n");	
}

// Function to mark the vertex with different colors for different cycles
void dfs_cycle(graph_t g, long u, long p, long *color, long *mark, long *par, long *cyclenumber){
	longArray_t *graph = g.adjacency_array;
    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {
        cyclenumber++;
        long cur = p;
        mark[cur] = *cyclenumber;
 
        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
            mark[cur] = *cyclenumber;
        }
        return;
    }
    par[u] = p;
    // partially visited.
    color[u] = 1;
    // simple dfs on graph
    //for (long v : graph[u]) 
    for (long i=0; i< graph[u].l; i++){
		long v = graph[u].a[i];
        // if it has not been visited previously
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(g, v, u, color, mark, par, cyclenumber);
    }
    // completely visited.
    color[u] = 2;
}
 
// add the edges to the graph
void addEdge(long u, long v){
    push_back(&graph[u],v);
    push_back(&graph[v],u);
}
 
// Function to print the cycles
void printCycles(long edges, long *mark, long *cyclenumber){
    // push the edges that into the
    // cycle adjacency list
    for (long i = 1; i <= edges; i++) {
        if (mark[i] != 0)
			fprintf(stderr,"cycles[mark[i]]\n");
            push_back(&cycles[mark[i]],i);
    }
 
    // print all the vertex with same cycle
    for (long i = 1; i <= *cyclenumber; i++) {
        // Print the i-th cycle
        fprintf(stderr,"Cycle Number %ld:",i);
        /*cout << "Cycle Number " << i << ": ";
        for (long x : cycles[i])
			cout << x << " ";
        cout << endl;*/
        print_intArray(&cycles[i]);
    }
}


long fscanf_directed_adjacency_array(FILE *f){
	long count = fscanf(f,"%ld", &g.number_of_vertices);
	fprintf(stderr,"number_of_vertices = %ld\n", g.number_of_vertices);
	
	g.adjacency_array = (longArray_t*)malloc((g.number_of_vertices+1) * sizeof(longArray_t));
	for (long i = 0; i < g.number_of_vertices; i++){
		intArrayInitialize(&g.adjacency_array[i]);
	}
	
	g.adjacency_matrix = (long**)malloc((g.number_of_vertices+1) * sizeof(long*));
	for (long i = 0; i < g.number_of_vertices+1; i++){
		g.adjacency_matrix[i] = (long*)malloc((g.number_of_vertices+1) * sizeof(long));
	}
	
	long maxX = g.number_of_vertices-1;
	g.number_of_edges = 0;
	for (long i = 0; i < maxX; i++){
		long maxY = maxX-i;
		//adjacency_matrix main diagonal
		g.adjacency_matrix[i][i] = 0;
		for (long j = 0; j < maxY; j++){
			long distance;
			count += fscanf(f, "%ld", &distance);
			
			// Add Edge (u->v) and (v->u) to adjacency_matrix
			long u = i;
			long v = i+j+1;
			g.adjacency_matrix[u][v] = distance;
			g.adjacency_matrix[v][u] = distance;
			
			if(distance > 0){
				// Add Edge (u->v) and (v->u) to adjacency_array
				//fprintf(stderr,"i:%ld j:%ld d:%ld\n",i,j,distance);
				push_back(&g.adjacency_array[u],v+1);
				push_back(&g.adjacency_array[v],u+1);
				g.number_of_edges++;
			}
		}
	}
	
	fprintf(stderr,"\n Adjacency Matrix:\n");
	print_long_matrix(g.adjacency_matrix, g.number_of_vertices, g.number_of_vertices);
	
	fprintf(stderr,"\n Adjacency Array:\n");
	print_n_intArray(g.number_of_vertices, g.adjacency_array);
	return count;
}



// Function to check if a vertex v can be added at index position in the Cycle
int isSafe(int v, graph_t *graph, longArray_t *path, int position) {
	// If the degree of the vertex is lass than two (aka zero or one).
	if (graph->adjacency_array!=NULL)
	if (graph->adjacency_array[v].l < 2) {
		fprintf(stderr, "\nBRENCH AND BOUND OPTIMIZATION: graph->adjacency_array[v:%d].l:%ld < 2, skipp next set of recursive executions because they will not find longest cycle.\n",v,graph->adjacency_array[v].l);
		fprintf(stderr, "BRENCH AND BOUND OPTIMIZATION: If the degree of the vertex is lass than two (aka zero or one) skipp.\n\n");
		return false;
	}
	
	// If the vertex is adjacent to the vertex of the previously added vertex
	if (graph->adjacency_matrix[path->a[position-1]][v] == 0)
		return false;

	// If the vertex has already been included in the path
	for (int i = 0; i < position; i++)
		if (path->a[i] == v)
			return false;
	
	// Both the above conditions are not true, return true
	return true;
}

// Function to find all possible
// hamiltonian cycles
void hamCycle(graph_t *graph){
fprintf(stderr,"void hamCycle(graph_t *graph)\n");
	// Initially value of int flag is false
	hasCycle = false;
	
	// Store the resultant path
	longArray_t *path = longArrayAlloc();
	//path.add(0);
	
	// Keeps the track of the visited vertices
	longArray_t *visited = longArrayAlloc();
	//int[] visited = new int[graph->number_of_vertices];

	for (int i = 0; i < graph->number_of_vertices; i++)
		push_back(visited,0);

	for (int i = 0; i < graph->number_of_vertices; i++) {
		//Set Start vertice
		push_back(path,i);
		visited->a[i] = true;
		// Function call to find all hamiltonian cycles
	
		// If the degree of the vertex is lass than two (aka zero or one).
		if (graph->adjacency_array!=NULL)
		if (graph->adjacency_array[i].l < 2) {
			fprintf(stderr, "\nBRENCH AND BOUND OPTIMIZATION2: graph->adjacency_array[v:%d].l:%ld < 2, skipp next set of recursive executions because they will not find longest cycle.\n",i,graph->adjacency_array[i].l);
			fprintf(stderr, "BRENCH AND BOUND OPTIMIZATION2: If the degree of the vertex is lass than two (aka zero or one) skipp.\n\n");
			pop_back(path);
			continue;
		}
		
		FindAllCycles(graph, 1, path, visited);
		//Unset Start vertice
		//visited->a[i] = false;
		pop_back(path);
	}
	
	if (!hasCycle) {
		// If no Hamiltonian Cycle
		// is possible for the
		// given graph
		fprintf(stderr,"No Hamiltonian Cycle possible ");
	}
	
	
	fprintf(stdout,"%ld\n",maxlength);
	for (int i = 0; i < maxsize-1; i++)
		fprintf(stdout,"%ld ",maxcycle[i]);
	fprintf(stdout,"%ld\n",maxcycle[maxsize-1]);
	
	fprintf(stderr,"%ld\n",maxlength);
	for (int i = 0; i < maxsize-1; i++)
		fprintf(stderr,"%ld ",maxcycle[i]);
	fprintf(stderr,"%ld\n",maxcycle[maxsize-1]);
}

// Recursive function to find all cycles containing start node
void FindAllCycles(graph_t *graph, int pos, longArray_t *path, longArray_t *visited){
	fprintf(stderr,"FindAllCycles");
	fprintf(stderr,", pos:%d",pos);
	fprintf(stderr,", path[%ld]:",path->l);
	for (int i=0; i<path->l-1;i++)
		fprintf(stderr,"%2ld->",path->a[i]+1);
	fprintf(stderr,"%2ld",path->a[path->l-1]);
	for (int i = path->l; i < graph->number_of_vertices; i++)
		fprintf(stderr,"    ");
	fprintf(stderr,", visited:");
	for (int i=0; i<graph->number_of_vertices;i++)
		fprintf(stderr,"%ld",visited->a[i]);
	fprintf(stderr,", ");
	// If all vertices are included in Hamiltonian Cycle
	// If there is an edge from the last vertex to the source vertex
	if (graph->adjacency_matrix[path->a[path->l-1]][path->a[0]]!= 0){
		// Include source vertex into the path and print the path
		push_back(path,path->a[0]);
		
		if (pos == graph->number_of_vertices) {
			for (int i = 0; i < path->l-1; i++)
				fprintf(stderr,"%2ld->",path->a[i]+1);		
			fprintf(stderr,"%2ld  ",path->a[path->l-1]+1);
			fprintf(stderr,", Hamiltonian");
			
			length=0;
			for (int i = 0; i < path->l-1; i++){
				length += graph->adjacency_matrix[path->a[i]][path->a[i+1]];
			}
			fprintf(stderr,", lenght:%2ld",length);
			if(length > maxlength) {
				maxlength = length;
				maxsize   = pos+1;
				for (int i = 0; i < maxsize; i++){
					maxcycle[i] = path->a[i]+1;
				}
			}
			fprintf(stderr,", maxlenght:%2ld",maxlength);
			fprintf(stderr,", MaxCycle[%ld]:",maxsize);
			for (int i = 0; i < maxsize; i++){
					fprintf(stderr,"%2ld",maxcycle[i]);
			}
		} else if(pos>2){
			for (int i = 0; i < path->l-1; i++)
				fprintf(stderr,"%2ld->",path->a[i]+1);
			fprintf(stderr,"%2ld  ",path->a[path->l-1]+1);
			for (int i = path->l; i <= graph->number_of_vertices; i++)
				fprintf(stderr,"    ");
			fprintf(stderr,", Common     ");
			
			length=0;
			for (int i = 0; i < path->l-1; i++){
				length += graph->adjacency_matrix[path->a[i]][path->a[i+1]];
			}
			fprintf(stderr,", lenght:%2ld",length);
			if(length > maxlength) {
				maxlength = length;
				maxsize   = pos+1;
				for (int i = 0; i < maxsize; i++){
					maxcycle[i] = path->a[i]+1;
				}
			}
			fprintf(stderr,", maxlenght:%2ld",maxlength);
			fprintf(stderr,", MaxCycle[%ld]:",maxsize);
			for (int i = 0; i < maxsize; i++){
					fprintf(stderr,"%2ld",maxcycle[i]);
			}
		} else {
			for (int i = 0; i <= graph->number_of_vertices; i++)
				fprintf(stderr,"    ");
			fprintf(stderr,", No Cycle   ");
			fprintf(stderr,", lenght:%2d",0);
			fprintf(stderr,", maxlenght:%2ld",maxlength);
		}
			
		// Remove the source vertex added
		pop_back(path);
		// Update the hasCycle as true
		hasCycle = true;
	} else {
		for (int i = 0; i <= graph->number_of_vertices; i++)
			fprintf(stderr,"    ");
		fprintf(stderr,", No Cycle   ");
		fprintf(stderr,", lenght:%2d",0);
		fprintf(stderr,", maxlenght:%2ld",maxlength);
	}
	fprintf(stderr,"\n");
	if (pos == graph->number_of_vertices)
		return;
	// Try different vertices as the next vertex
	for (int v = 0; v < graph->number_of_vertices; v++){
		// Check if this vertex can be added to Cycle
		if (isSafe(v, graph, path, pos) && !visited->a[v]){
			push_back(path,v);
			visited->a[v] = true;
			// Recur to construct rest of the path
			FindAllCycles(graph, pos + 1, path, visited);
			// Remove current vertex from path and process other vertices
			visited->a[v] = false;
			pop_back(path);
		}
	}
}

#endif

