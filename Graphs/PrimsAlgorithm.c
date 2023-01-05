#include <stdio.h>
#include <limits.h>
#define I INT_MAX

// Declaring the cost adjacency matrix where matrix[i][j] represent the cost for going from i->j or j->i
// Empty values are represented by the maximum integer
// Matrix starts from row 1 and column 1, skipping the 0th row and 0th column for simplicity
int cost[][8]= 
    {{I,I,I,I,I,I,I,I}, 
     {I,I,25,I,I,I,5,I}, 
     {I,25,I,12,I,I,I,10}, 
     {I,I,12,I,8,I,I,I}, 
     {I,I,I,8,I,16,I,14}, 
     {I,I,I,I,16,I,20,18}, 
     {I,5,I,I,I,20,I,I}, 
     {I,I,10,I,14,18,I,I}};

// near matrix which will be used to find the nearest vertices
// skipping the 0th index in the near array as well
int near[8]={I,I,I,I,I,I,I,I}; 
// Answer matrix which is used to generate the spanning tree
int t[2][6];

int main(){
    // i,j,k are variables to traverse the matrix
    // u,v represent the vertices
    // n represents the total number of vertices which is 7 here 
    int i,j,k,u,v,n=7,min=I;

    // Finding the minimum cost edge from the cost matrix
    for(i=1;i<=n;i++) { 
        for(j=i;j<=n;j++) { 
            if(cost[i][j]<min){ 
                min=cost[i][j]; 
                u=i; 
                v=j; 
            } 
        } 
    }
    // Storing the minimum cost edge in the answer matrix
    t[0][0] = u , t[1][0] = v;
    // Updating the indexes u and v in the near array to 0 as they are included in the solution matrix
    near[u] = near[v] = 0;

    // Initializing the near array to check whether each edge is nearer to u or nearer to v
    for(i=1;i<=n;i++){
        // if near[i] != 0 i.e. it is not included in the solution previously then check
        if(near[i] != 0){
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Including the remaining edges
    for(i=1;i<n-1;i++){
        // finding the minimum from the near array 
        min = I;
        for(j=1;j<=n;j++){
            // near[j] != 0 so that we do not come to the index which is already included in the answer
            if(near[j] != 0 && cost[j][near[j]] < min){
                k=j;
                min = cost[j][near[j]];
            }
        }
        // After finding the minimum we update the answer matrix
        t[0][i] = k;
        t[1][i] = near[k];
        // Updating the kth index of near array to 0 as it is included in the answer
        near[k] =0;

        // Check if the other vertices are nearer to k or not 
        for(j=1;j<=n;j++){
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }

    // Printing the solution
    for(i=0;i<n-1;i++){
        printf("(%d , %d)\n",t[0][i],t[1][i]);
    }

}