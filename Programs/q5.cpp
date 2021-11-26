#include<iostream>

#define INFINITY 9999
#define MAX 10


void dijkstra(int G[MAX][MAX],int n,int startnode);

int main(){

    int G[MAX][MAX],n,u;

    std:: cout<< "Enter no. of vertices:";
    std:: cin>> n;

    std:: cout<< "\nEnter the adjacency matrix:\n";
 

    for(int i= 0; i< n; i++){
        for(int j= 0;j< n; j++){
            std:: cin>> G[i][j];
        }
    }

    std:: cout<< "\nEnter the starting node:";
    std:: cin>> u;

    dijkstra(G,n,u);

return 0;
}


void dijkstra(int G[MAX][MAX], int n, int startnode){

    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode;
 
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
 
    for(int i= 0; i< n; i++){
        for(int j= 0; j< n; j++){
            
            if(G[i][j]==0){
                cost[i][j]=INFINITY;
            }
            else{
                cost[i][j]=G[i][j];
            }
        }
    }
        
    //initialize pred[],distance[] and visited[]
 
    for(int i= 0; i< n; i++){
        distance[i]= cost[startnode][i];
        pred[i]= startnode;
        visited[i]= 0;
    }
 
    distance[startnode]= 0;
    visited[startnode]= 1;
    count= 1;

    while(count< n-1){
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(int i= 0; i< n; i++){
            if(distance[i]<mindistance && !visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        }

        //check if a better path exists through nextnode         
        visited[nextnode]=1;
        for(int i= 0; i< n; i++){
            if(!visited[i]){
                if(mindistance+cost[nextnode][i] < distance[i]){
                    distance[i]= mindistance + cost[nextnode][i];
                    pred[i]= nextnode;
                }
            }
            count++;
        }

 
        //print the path and distance of each node

        int x;
        for(int i= 0; i< n; i++){
            if(i!=startnode){
                std:: cout<<"\nDistance of node"<<i<<"="<<distance[i];
                std:: cout<<"\nPath="<<i;
            }
            x= i;
        }

        do{
            x= pred[x];
            std:: cout<<"<-"<<x;
        }while(x!=startnode);
    }
}