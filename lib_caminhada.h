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
 

#ifndef _LIB_CAMINHDA_
#define _LIB_CAMINHDA_

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> // needed to check bounding conditions
#include <errno.h>  // needed for error codes


typedef struct longArray_s {
	long  s; // size of memory alocation
	long  l; // lenght of the array
	long *a; // pointer to array of integers
} longArray_t;


typedef struct longArray2_s {
	long  s;         // size of memory alocation
	long  l;         // lenght of the array
	longArray_t **a; // pointer to vector of longArray_t pointers
} longArray2_t;

typedef struct graph_s {
	long         number_of_vertices;
	long         number_of_edges;
	longArray_t  *adjacency_array;
	long       **adjacency_matrix;
} graph_t;

// variables to be used in both functions
#define N 100000
longArray_t graph[N];
longArray_t cycles[N];
graph_t g;

// To check if there exists
// at least 1 hamiltonian cycle
int hasCycle;

long    length = 0;
long maxlength = 0; //size as in sum of edge lentgh
long maxsize   = 0; //size as in numbre of nodes
long maxcycle[1000];

void hamCycle(graph_t *graph);
void FindAllCycles(graph_t *graph, int pos, longArray_t *path, longArray_t *visited);
int isSafe(int v, graph_t *graph, longArray_t *path, int position);


#include "lib_caminhada.c"

#endif
