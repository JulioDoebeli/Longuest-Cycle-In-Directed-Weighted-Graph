/*
 * caminhada.c
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
#include <stdio.h>  
#include <stdlib.h>
#include <string.h> // needed for reading input file

#include <limits.h> // needed to check bounding conditions
#include <errno.h>  // needed for error codes

#include "lib_caminhada.h"
#include "lib_caminhada.c"

// Driver Code
int main(){
	fscanf_directed_adjacency_array(stdin);
    
    
    hamCycle(&g);
}
