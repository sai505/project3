// test_dijkstra.cpp
// c. 2017 T. O'Neil, C. Reilly

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.hpp"

using std::ifstream;

int main() {
	Digraph g;
	ifstream dataFile;
	int numPoints, p, q, r;
	string city;

	dataFile.open("nqmq.dat");
	dataFile >> numPoints;
	std::cout << "menu:" << std::endl;
	for (int i = 0; i < numPoints; i++) {
		dataFile >> city;
		g.addVertex(city);
		std::cout << i << " : " << city << std::endl; //menu
	}	
	g.resetEdges();
	dataFile >> p; // source
	dataFile >> q; // destination
	dataFile >> r; // weight

	while (p > -1) {
		g.addEdge(p, q, r);
		g.addEdge(q, p, r);
		dataFile >> p;
		dataFile >> q;
		dataFile >> r;
	}
	dataFile.close();

		int start, end;
		std::cout << std::endl;
		std::cout << "From:";
		std::cin >> start;
		std::cout << "To:";
		std::cin >> end;
		std::cout << endl;
		p = g.dijkstra(start, end);
		std::cout << std::endl;
		std::cout << "Distance: " << p << " Miles" << std::endl;
}
