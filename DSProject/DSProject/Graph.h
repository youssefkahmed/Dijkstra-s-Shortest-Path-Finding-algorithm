#pragma once
#include <unordered_map>
#include<list>
#include <string>
using namespace std;

class Graph
{
	unordered_map<string,list<pair<string,int>>> Map;

public:
	void addEdge(string src, string dest, int weight);
	void printGraph();
	void Dijkstra(string src, string desti);
	void updateGraph(string, string, int);
	bool findSource(string src);
	Graph(void);
	~Graph(void);
};