#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
	string color;
	int val; 
	Node(int val, string color)
	{
		this->val=val;
		this->color=color;
	}
};
struct Edge
{
	int start_point,end_point;
	char classification;
	Edge()
	{
		classification='C';
	}	
};
class Cycles
{

	int amounth_of_nodes,amounth_of_edges;
	vector<Node> p;
	vector<vector<Node>> graph;
	vector<Edge>edges;
	bool * visited;
	stack<int> S,T;

public:
	Cycles(int amounth_of_nodes, int amounth_of_edges)
	{
		this->amounth_of_nodes=amounth_of_nodes;
		this->amounth_of_edges=amounth_of_edges;

		for(auto i=0;i<amounth_of_nodes;i++) graph.push_back(*(new vector<Node>));
		for(auto i=0;i<amounth_of_edges;i++) edges.push_back(*(new Edge()));
		visited = new bool [amounth_of_nodes]; 

	}

	auto set_neighbors_list()
	{
		int a,b;
		for(auto i = 0; i < amounth_of_edges; i++)
		{
			cin>>a>>b;
			graph[a].push_back(*(new Node(b, "white")));
			edges[i].start_point=a; 	
			edges[i].end_point=b;	
		}
	}

	bool DFSfindCycle(vector<vector<Node>> graph, int start_node, int actuall_node, stack<int> & S, bool * visited)
	{
		visited[actuall_node] = true;  
		S.push(actuall_node);              
		p = graph[actuall_node];                   
		for(Node i:p)
		{	 
			if(i.color.compare("white")) 	  	i.color="brown"; 
			if(i.color.compare("brown")) 	  	i.color="black";
			if(i.val == start_node) return true;      
			if(!visited[i.val] && DFSfindCycle(graph,start_node,i.val,S,visited)) return true;
		}
		S.pop();                       
		return false;
	}
		void find_cycles()
		{
			for(int i = 0; i < amounth_of_nodes; i++)           
			{
				for(int j = 0; j < amounth_of_nodes; j++) visited[j] = false;         

				if(!DFSfindCycle(graph,i,i,S,visited)) cout << i << " - no cycle\n"; 
				else
				{
					T.push(i);
					while(!S.empty())           
					{
						T.push(S.top()); S.pop();
					}

					while(!T.empty())            
					{
						cout << T.top() << " "; T.pop();
					}
					cout << endl;
				}
			}
		}
};

int main()
{
  
  int amounth_of_nodes,amounth_of_edges;
  cout<<"Podaj liczbę wierzchołków i krawędzi:";
  cin >> amounth_of_nodes >> amounth_of_edges;    
  Cycles *cycles=new Cycles(amounth_of_nodes,amounth_of_edges);
  cycles->set_neighbors_list();
  cycles->find_cycles();
} 
