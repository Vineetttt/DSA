#include <stdio.h>
#include <limits.h>
#define I INT_MAX

// Creating a matrix for edges
// row 1 and row 2 denote the connection
// row 3 denotes the cost to establish the connection

int edge[3][9]=
    {{1,1,2,2,3,4,4,5,5},
     {2,6,3,7,4,5,7,6,7},
     {25,5,12,10,8,16,14,20,18}};
// cost for edge 1->2 is 25

// We will be using disjoint subset in the solution
// Creating a array for the same , neglect the 0th index
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

// Maintaining an array to check if the edge is previously present in the solution or no 
// 0 represents the edge is not included , 1 represents that the array is included
int included[9] = {0};

// Answer matrix 
int t[2][6];

// Functions to perform the Set Operations
void MyUnion(int u,int v) { 
    if(set[u]<set[v]) { 
        set[u]+=set[v]; 
        set[v]=u; 
    } 
    else{ 
        set[v]+=set[u]; 
        set[u]=v; 
    } 
} 
int find(int u) { 
    int x=u,v=0; 
    while(set[x]>0)
        x=set[x];  
    while(u!=x) { 
         v=set[u]; 
        set[u]=x; 
        u=v; 
    } 
    return x; 
}

int main(){
    // n is the number of vertices and e is the number of edges
    int i,j,k,u,v,min=I,n=7,e=9;
    i=0;
    while(i<n-1){
        // Finding the minimum cost edge
        min = I;
        for(j=0;j<e;j++){
            // included[j] == 0 will make sure that the same edges are not visited again
            if(included[j] == 0 && edge[2][j] < min){
                min = edge[2][j];
                u = edge[0][j];
                v = edge[1][j];
                // Recroding the value of j inside k to mark it as included 
                k = j;
            }
        }

        // Minimum cost edge is found after the for loop
        // Updating the answer matrix only if cycles are not formed after finding the minmum cost edge
        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;
            MyUnion(find(u),find(v));
            i++;
        }

        // Updating the included array with 1 for the edge which is included in the answer matrix
        included[k] = 1;
    }

    // Printing the answer
    for(i=0;i<n-1;i++){
        printf("(%d , %d)\n",t[0][i],t[1][i]);
    }
}