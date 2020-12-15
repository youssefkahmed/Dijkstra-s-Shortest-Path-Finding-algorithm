#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <vector>
#include "Graph.h"
using namespace std;

int main(){

	unordered_map<string,Graph> MyList;
	char choice;
	int vertex;
	string src, dest;
	string graphName;
	int weight;

	while(true){
		   
		    cout << "A for Add Graph" << endl;
			cout << "U for Update Graph" << endl;
			cout << "E for Add Edge" << endl;
			cout << "C for Calculate Path" << endl;
			cout << "P for Print Graph" << endl;
			cout << "D for Delete Graph" << endl;
			cout << "G for Number Of Graphs" << endl;
			cout << "X To Exit" << endl;

			cin >> choice;
			
			// add new graph

			if(choice == 'a' || choice == 'A'){
			
		    system("CLS");
			Graph *Map = new Graph();

			cout << "Enter The Graph Name" << endl;
			cin >> graphName;

			cout << "How many Nodes in your Graph" << endl;
			cin >> vertex;

			cout << "Please Enter Source, Destination, and Weight for " << vertex << " node(s)" << endl;

				for(int i = 0; i < vertex; i++){
					cin >> src >> dest >> weight;
					Map->addEdge(src,dest,weight);
				}

				cout << "Graph Is Added Successfully" << endl << endl;
				MyList[graphName] = *Map;
			}

			// Update existing graph

			else if(choice == 'u' || choice == 'U'){
			system("CLS");

			cout << "Which Graph Do You Want To Update?" << endl;
			cin >> graphName;
			unordered_map<string,Graph>::iterator update = MyList.find(graphName);

			cout << "Enter The Source, Destination, And The New distanceance" << endl;
			cin >> src >> dest >> weight;
			update->second.updateGraph(src,dest,weight);
			}

			// Add an Edge to an existing graph

			if(choice == 'e' || choice == 'E'){
			
		    system("CLS");

			cout << "Enter The Graph Name" << endl;
			cin >> graphName;

			unordered_map<string,Graph>::iterator newEdge = MyList.find(graphName);

			cout << "Please Enter Source, Destination, and Weight" << endl;
			cin >> src >> dest >> weight;

			if(newEdge->second.findSource(src))
			{
				cout << "Source Already Exists!" << endl;
			}
			
			else{
			
				newEdge->second.addEdge(src,dest,weight);
				cout << "Edge Is Added Successfully" << endl << endl;
			}
			}

			// Print a graph

			else if(choice == 'p' || choice== 'P'){
			system("CLS");
            
			cout << "Which Graph Do You Want To Display?" << endl;
			cin >> graphName;

			unordered_map<string,Graph>::iterator Pit = MyList.find(graphName);

			if (Pit != MyList.end()){
				Pit->second.printGraph(); cout << endl << endl;}

			else {
			    cout << "Graph Not Found!" << endl;
			}

      
			}

			// Calculate Shortest Path In A Graph

			else if(choice == 'c' || choice == 'C'){
		    system("CLS");

			cout << "Which Graph Do You Want Calculate The Shortest Path For?" << endl;
			cin>>graphName;
			unordered_map<string,Graph>::iterator calculate = MyList.find(graphName);

			cout << "Enter The Source And Destination" << endl;
			cin >> src >> dest;

			
			if (calculate->second.findSource(src) && calculate->second.findSource(dest))
			{
			calculate->second.Dijkstra(src,dest);
			}

			else {
			   cout << "No Possible Path For The Provided Parameters!!!" << endl;
			}
			

			cout <<endl;
		
			}
			// Delete A Graph

			else if(choice == 'D' || choice == 'd'){
				system("CLS");
				
				cout << "Which Graph Do You Want To Delete?" << endl;
				cin>>graphName;

				unordered_map<string,Graph>::iterator deletePTR = MyList.find(graphName);

				if (deletePTR != MyList.end()){
					MyList.erase(deletePTR->first);}

				else { cout << "Graph Not Found!" << endl;}
			}
		

			else if(choice == 'g' || choice == 'G')
			{
				system("CLS");

				cout << "The Number Of Graphs In Your List Is: " << MyList.size() << endl;
			
			}

			else if(choice == 'x' || choice == 'X')
			{
				return 0;
			
			}
		
	}



	return 0;
}