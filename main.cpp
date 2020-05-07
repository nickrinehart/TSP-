#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std; 
  
int TSP(pair<int,string> graph[][5], int start) 
{ 
	fstream write;
	write.open("final.txt");	
	write << "Here are all paths with miles attached." << endl << endl;
    vector<int> vertex; 
    for (int i = 0; i < 5; i++) 
	
        if (start != i) 
            vertex.push_back(i); 
  		
    
    int shortest = INT_MAX; 
    do {  
        int distance = 0; 
        int pos = start; 
        for (int i = 0; i < vertex.size(); i++) { 
            distance += graph[pos][vertex[i]].first; 
			write << graph[pos][vertex[i]].second << " -> " ;
            pos = vertex[i]; 
        } 
        distance += graph[pos][start].first; 
  		write << graph[pos][start].second << ": " << distance << " total miles" << endl;
        
        shortest = min(shortest, distance); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
	write.close();
    return shortest; 

}
int main() 
{  
	
    pair <int , string> graph[][5] = { 
		{ make_pair( 0 , "Reno")  , make_pair(439 , "vegas") ,make_pair(519, "salt lake city") , make_pair(218, "san francisco") , make_pair(704, "seattle") }, 
		{ make_pair( 439 , "Reno")  , make_pair(0 , "vegas") ,make_pair(421, "salt lake city") , make_pair(569, "san francisco") , make_pair(1115, "seattle") }, 
		{ make_pair( 519 , "Reno")  , make_pair(421 , "vegas") ,make_pair(0, "salt lake city") , make_pair(736, "san francisco") , make_pair(829, "seattle") }, 
		{ make_pair( 218 , "Reno")  , make_pair(569 , "vegas") ,make_pair(736, "salt lake city") , make_pair(0, "san francisco") , make_pair(808, "seattle") }, 
		{ make_pair( 704 , "Reno")  , make_pair(1115 , "vegas") ,make_pair(829, "salt lake city") , make_pair(808, "san francisco") , make_pair(0, "seattle") }, 
		}; 
    int start = 0;
	int distance = TSP(graph, start);
	int gallons = distance / 40; // assume 40 mpg
	float cost = gallons * 2.311; // price per gallon
    cout << "The minimum distance is " << distance << " miles" << endl; 
	cout << "You will use " << gallons << " gallons" << endl;
	cout << "The total cost is " << cost << " USD " << endl;
    return 0; 
} 

