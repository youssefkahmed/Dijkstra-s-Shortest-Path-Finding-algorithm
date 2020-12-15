#include "Graph.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <set>

Graph::Graph(void)
{
	
}


bool Graph::findSource(string src){
	
	unordered_map<string,list<pair<string,int>>>::iterator it = Map.find(src);

	if (it != Map.end())
	{
		return true;
	}

	else {
	    return false;
	}
}

void Graph::addEdge(string src, string dest, int weight){
	
	Map[src].push_back(make_pair(dest,weight));
	Map[dest].push_back(make_pair(src,weight));

}

void Graph::printGraph(){

	for(auto i : Map){

		cout <<i.first<<": ";

		for(auto j : i.second){
			
			cout << "(" << j.first << "," << j.second << ") ";
		}

		cout << endl;
	}
}	

void Graph::updateGraph(string src, string dest, int weight)
{
	unordered_map<string,list<pair<string,int>>>::iterator it = Map.find(src);

	if (it == Map.end())
	{
		cout << "Source Not Found" << endl;
	}


	else{

    list<pair<string,int>>::iterator iter;

		for(iter = it->second.begin(); iter != it->second.end(); iter++){
			if(iter->first == dest){
				Map[src].erase(iter);
				break;
			}
		}
		
	
	Map[src].push_back(make_pair(dest,weight));

	unordered_map<string,list<pair<string,int>>>::iterator it2 = Map.find(dest);
    list<pair<string,int>>::iterator iter2;

		for(iter2 = it2->second.begin(); iter2 != it2->second.end(); iter2++){
			if(iter2->first == src)
				Map[dest].erase(iter2);
				break;
		}

	Map[dest].push_back(make_pair(src,weight));
	}
}

void Graph::Dijkstra(string src, string desti){
	
	unordered_map<string,int> distance;
	
	for (auto i : Map){
		distance[i.first]= INT_MAX;
	}
	
	set<pair<int,string>> s;
	distance[src]=0;
	s.insert(make_pair(0,src));
	
	while (!s.empty()){
		auto pair = *(s.begin());
		string destTown = pair.second;
		int townWeight = pair.first;
		s.erase(s.begin());
		
		for(
			auto neighboursNodes : Map[destTown]){
			if(townWeight+neighboursNodes.second < distance[neighboursNodes.first] ){
				string dest = neighboursNodes.first;
				auto it = s.find(make_pair(distance[dest],dest));
				
				if(it!=s.end())
					s.erase(it);

				distance[dest]=townWeight+neighboursNodes.second;
				s.insert(make_pair(distance[dest],dest));

			}


		}
	}


	if (distance[desti] != INT_MAX){

	cout <<distance[desti]<<endl;

	for(auto j : distance){
		
		if(j.second<distance[desti]){
			cout <<j.first<<" ";
		}
	}
	cout <<desti;
	}

	else {
	
	   cout << "No Possible Path" << endl;
	}


}


Graph::~Graph(void)
{
}