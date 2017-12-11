// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <algorithm>   
#include <map>
struct table {
	table( int distance = 32767,  int previous = NULL) { d = distance; prev = previous; }
	unsigned int d;
	unsigned int prev;
};

void path(std::vector<int> & path) {

}

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
	for (unsigned int i = 0;i < numberOfVertices;++i)
		for (unsigned int j = 0;j < numberOfVertices;++j)
			distMatrix[i][j] = 32767; //infinite constant
}

void Digraph::addEdge(int source, int dest, int wt)
{
	distMatrix[source][dest]= wt;
}

void Digraph::delEdge(int source, int dest)
{
}

//return weight if edge and unvisited, else 0 
int Digraph::isEdge(int source, int dest)
{
	return distMatrix[source][dest] < 32767 ? distMatrix[source][dest] : 0;
}

//return final distance
int Digraph::dijkstra(int source, int dest) // 7 & 5
{
	int current=source; //current vertex
	std::vector<int> neighbors;
	neighbors.resize(numberOfVertices);
	std::vector<int> path;


	//table contains d[source] and previous vertex
	table* t_p = new table;
	std::vector<table*> t_vector;
	t_vector.resize(numberOfVertices);	
	
	//path
	path.push_back(current);

	//Initialize table & neighbors & vertex
	for (int i = 0; i < numberOfVertices; ++i) {
		t_vector[i] = new table;
		neighbors[i] = 32767;
		Node *ptr = vertex[i];
		ptr->setStatus(NOT_VISITED);

	}
	t_vector[source] = new table (0,source); //d[source] = 0

	//Update Table until reach destination 
	do {
		//Check Edges: Loop Through column of DisMatrix at Source Row
		for (int it = 0; it < numberOfVertices; ++it) {
			if (isEdge(current, it) != 0) {
				Node *ptr = vertex[it];
				if (ptr->getStatus() == 0 && t_vector[it]->d > t_vector[current]->d + isEdge(current, it)) {
					t_vector[it]->d = t_vector[current]->d + isEdge(current, it);
					t_vector[it]->prev = current;
				}
				//Store d[neighnors]
				if (ptr->getStatus() == 0)
				neighbors[it] = isEdge(current, it);
			}
		}
		//update minimum d[neighnors] to current && Mark visited
		Node *ptr = vertex[current];
		ptr->setStatus(VISITED);
		std::vector<int>::iterator min = (std::min_element(neighbors.begin(), neighbors.begin()+ numberOfVertices));
		current = std::distance(neighbors.begin(), min);
		for (int i = 0; i < numberOfVertices; ++i) {
			neighbors[i] = 32767;
		}

	} while (current != dest);

	//output start & end point & path
	Node *start = vertex[source];
	Node *end = vertex[dest];
	std::cout << start->getName() << " to " << end->getName() << std::endl;
	std::cout << endl;
	std::cout << "Path:" << std::endl;
	int n = dest;
	path.push_back(n);
	while (n != source) {
		n=t_vector[n]->prev;
		path.push_back(n);
	}
	for (int i = path.size()-1; i > 0; --i) {
		Node *ptr = vertex[path[i]];
		std::cout << ptr->getName() << std::endl;
	}

	

	//memory deallocate
	path.clear();

	return t_vector[dest]->d;
}
