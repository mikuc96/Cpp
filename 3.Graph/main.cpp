#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>  
using namespace std;

struct Pair
{
	int a,b;
	string color;
	Pair(int a, int b, string color)
	{
		this->a=a;
		this->b=b;
		this->color=color;
	}
	void print(){ cout<<a<<" "<<b<<", color:  "<<color<<endl; }
};
struct List
{
    int value;
    List *next;
};

class Graph
{
	int amounth_of_edges;
	int amounth_of_nodes;
	vector <Pair> pairs; 
	vector <vector<int>> matrix;
	vector<int> *neighborhood_list;

public:
	Graph(int amounth_of_edges, int amounth_of_nodes)
	{
		this->amounth_of_edges=amounth_of_edges;
		this->amounth_of_nodes=amounth_of_nodes;
		vector <vector<int>> temp(amounth_of_nodes, vector<int>(amounth_of_nodes));
		matrix=temp;
	}
	void get_pairs()
	{
		int i=0;
		int x,y;
		int number =(rand() % 3 ) ;
		int counter=amounth_of_edges;

		while(counter>0)
		{
			number =(rand() % 3 ) ;
			cout<<"Enter: "<<i+1<<" pair and color:"; cin>>x>>y;
			if(number==0) pairs.push_back(*(new Pair(x,y,"r")));
			if(number==1) pairs.push_back(*(new Pair(x,y,"g")));
			if(number==2) pairs.push_back(*(new Pair(x,y,"b")));
			
			counter--;i++;
		}
	}
	void create_neighborhood_matrix()
	{
		int x,y;
		for(auto i:pairs)
		{
			x=i.a; y=i.b;
			matrix[x-1][y-1]=1;	
			matrix[y-1][x-1]=1;	
		}	
	}
	void create_neighborhood_list()
	{
		neighborhood_list = new vector<int>[amounth_of_nodes+1];   
		int a, b; 
		for(int i=1; i<=amounth_of_edges; i++)       
		{			
			a=pairs[i-1].a;
			b=pairs[i-1].b;
			neighborhood_list[a].push_back(b);
			neighborhood_list[b].push_back(a);
		}
	}
	void draw_matrix()
	{
		for(int i=0; i<amounth_of_nodes;i++)
		{
			for(int j=0; j<amounth_of_nodes;j++) 
				{
					cout<<matrix[i][j]<<" ";
				}
			cout<<endl;
		}
	}
	void draw_pairs()
	{
		for(auto i:pairs)
		{
			i.print();
		}
	}
	void draw_neighborhood_list()
	{
		for(int i=1; i<=amounth_of_nodes; i++)     
		{
			cout<< "Neighbors node " << i << ": ";
			for(vector<int>::iterator it = neighborhood_list[i].begin(); it != neighborhood_list[i].end(); ++it) 
			{
				cout << *it << "  ";
			}
			cout<<endl;
		}	
	}
};

int main()
{
	int amounth_of_edges;
	int amounth_of_nodes;
	cout<<"Enter amounth of nodes: ";cin>>amounth_of_nodes;
	cout<<"Enter amounth of edges: ";cin>>amounth_of_edges;
	Graph *g= new Graph(amounth_of_edges, amounth_of_nodes);
	g->get_pairs();

	g->create_neighborhood_matrix();
	cout<<"=========================="<<endl;
	cout<<"Neighborhood_matrix"<<endl;
	g->draw_matrix();
	cout<<"=========================="<<endl;;
	cout<<"Neighborhood_list"<<endl;
	g->create_neighborhood_list();
	g->draw_neighborhood_list();
	cout<<"==========================";
	cout<<endl<<"Neighborhood_list"<<endl;
	g->draw_pairs();
	cout<<"=========================="<<endl;;
}