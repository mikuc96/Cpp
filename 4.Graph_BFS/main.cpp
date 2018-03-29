#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

struct Node
{
	string color;
	int parent;
	vector <int> neighbors;  
	Node(string color){ this->color=color;}
	auto assign_color(string color){ color=color;}		
};

class Graph
{
	int amounth_of_edges, amounth_of_nodes, temp;
	vector<Node> nodes;
	vector <int> path;
	queue<int> que; 
	
public:
	Graph(int amounth_of_edges, int amounth_of_nodes)
	{
		this->amounth_of_edges=amounth_of_edges;
		this->amounth_of_nodes=amounth_of_nodes;		
		vector<Node>node2(amounth_of_nodes+1,*(new Node("white")));
		nodes=node2;		
	}
	auto get_pairs()
	{
		int a,b;
		for(int i=0;i<amounth_of_edges;i++)
		{
			cin>>a>>b;
			nodes[a].neighbors.push_back(b); 
			nodes[b].neighbors.push_back(a);
		}	 
	}

	auto BFS(int start, int end)
	{
   		que.push(start); 
		while(!que.empty()) 
		{
			temp = que.front(); 
			if(temp == end)
			{
	            int c = end;
	            while (c != start)
	            {
		            path.push_back(c);
		            c = nodes[c].parent;
	            }
	            path.push_back(start);
	            reverse(path.begin(),path.end());
				return path; 
			} 
			que.pop(); nodes[temp].assign_color("black");

			for(int i=0; i<nodes[temp].neighbors.size();i++)
			{
				if(nodes.at(nodes[temp].neighbors[i]).color.compare("black")!=false)
				{
					que.push(nodes[temp].neighbors[i]);
					nodes.at(nodes[temp].neighbors[i]).assign_color("brown");
	                if (nodes[nodes[temp].neighbors[i]].parent == 0) nodes[nodes.at(temp).neighbors[i]].parent = temp;
				}
			}			
		} 		 
	}
};

int main()
{
	int amounth_of_edges, amounth_of_nodes,start,end;
	cout<<"Enter amounth of nodes: "; cin>>amounth_of_nodes; 
	cout<<"Enter amounth of edges: "; cin>>amounth_of_edges; 
	Graph *g= new Graph(amounth_of_edges, amounth_of_nodes);
	g->get_pairs();
	cout<<"Enter start and end of path: "; cin>>start>>end; 
	auto path=g->BFS(start,end);
	cout<<"================================="<<endl;
	cout<<"Shortest distance | "<<path.size()-1<<endl;
	cout<<"Shortest path     | "; for(auto i:path){ cout<<i<<" ";}cout<<endl;
	cout<<"================================="<<endl;
}