// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <algorithm>   

unsigned int Digraph::noVertices()
{
	return 0;
}

unsigned int Digraph::noEdges()
{
	return 0;
}

void Digraph::resetEdges()
{
	for (unsigned int i = 0; i < numberOfVertices; ++i)
		for (unsigned int j = 0; j < numberOfVertices; ++j)
			distMatrix[i][j] = 4294967295; //infinite constant
}

void Digraph::addEdge(int source, int dest, int wt)
{
	distMatrix[source][dest] = wt;
}

//
void Digraph::delEdge(int source, int dest)
{
	distMatrix[source][dest] = 999999;
}

//return 1 if edge, else 0 
int Digraph::isEdge(int source, int dest)
{
	return distMatrix[source][dest]<4294967295;
}

//return final distance
int Digraph::dijkstra(int source, int dest) // 7 & 5
{
	//shortest distance from source and previous vertex
	std::map<int, int> table; 
	
	//Initialize table
	for(int i=0; i<numberOfVertices; i++){
		table.insert(std::pair<int, int> (4294967295, NULL));
	}
	table[source]=std::pair<int, int> (0,0); //d[source] = 0
	
	//Check  Edges from current node
	isEdge(int source, int dest);



	return 0;
}
