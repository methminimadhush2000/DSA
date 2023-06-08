#include<bits/stdc++.h>
using namespace std;

#define v 6

int minVertex(int key[], bool mstSet[]){
    int minimum = INT_MAX;
    int min_vertex;

    for(int i=0;i<v;++i){
		if(mstSet[i]==false && key[i]<minimum)
		{
			min_vertex = i;
			minimum = key[i];
		}
	}
	return min_vertex;
}

int calculateTotalWeight(int graph[v][v], int parent[v]) {
    int totalWeight = 0;
    for (int i = 1; i < v; i++)
        totalWeight += graph[i][parent[i]];
    return totalWeight;
}

void findMST(int graph[v][v]){
    int parent[v];
    int key[v];
    bool mstSet[v];  // to represent the vertices include in the MST

    for(int i=0; i<v; i++)
        key[i]= INT_MAX , mstSet[i]= false;

    parent[0] = -1;
    key[0] = 0;

    for(int j=0; j<v-1; j++){
        int u= minVertex(key,mstSet);
        mstSet[u]=true;
        for(int k=0; k<v; k++){
            if(graph[u][k]!=0 && mstSet[k] == false && graph[u][k]<key[k]){
                parent[k]=u;
                key[k]=graph[u][k];
            }
        }
    }

    // calculate the total weight of the MST
    int Tot_weight = calculateTotalWeight(graph, parent);

    //Print MST
	cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";

    // print the calculated weight
    cout << "Total Weight: " << Tot_weight << endl;

}

int main(){
    int graph[v][v] = { {0, 3, 0, 0, 0, 1},
						{3, 0, 2, 1, 10, 0},
						{0, 2, 0, 3, 0, 5},
						{0, 1, 3, 0, 5, 0},
						{0, 10, 0, 5, 0, 4},
						{1, 0, 5, 0, 4, 0} };

    findMST(graph);
    return 0;
}