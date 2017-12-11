g++ --std=c++11 Digraph.cpp
g++ --std=c++11 test_dijkstra.cpp *.o --o digraph.out
rm -f *.o
rm -f *~
rm -f \#*
