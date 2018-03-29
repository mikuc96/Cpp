#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


#define enter cout<<endl
struct Node
{
    char color;
    int value,d,f;
    vector<pair<int, Node*>> neighbors;
    Node *parent;
    Node(int value) {this->value=value;}
};

class Graph {
    unordered_map<int, Node*> nodes;
    vector<int>path;
    int amounth_of_nodes,amounth_of_edges,time,counter,a,b;
    vector<Node>list;
public:
    Graph(int amounth_of_nodes, auto matrix)
    {
    	this->amounth_of_nodes=amounth_of_nodes;
      
		for(int i=0;i<amounth_of_nodes;i++) addNode(i);
	    for(int i=0;i<amounth_of_nodes;i++)
        {
            for(int j=0;j<amounth_of_nodes;j++) if(matrix[i][j]==1) addNeighbor(i,j);
        } 
        counter=1;        time=0;
    }

    void addNode(int value)
    {
        auto node = new Node(value);
        nodes[value] = node;
    }

    void addNeighbor(int a, int b)
    {
        Node *f = nodes.at(a);
        Node *t = nodes.at(b);
        pair<int, Node *> edge = make_pair(1, t);
        f->neighbors.push_back(edge);
    }

    auto DFS()
    {
        for(auto &i:nodes) i.second->color='w';
        for(auto &i:nodes) if(i.second->color=='w')  dfsVisit(i.second);
        return list;
    }

    void dfsVisit(Node *ve){
        ++time;
        bool lock=0;
        ve->d=time;
        ve->color='g';
        Node* ve2;
        ve2=ve;
        list.push_back(*ve);

        for(auto i: ve->neighbors)
        {
            if(i.second->color=='w')
            {

                i.second->parent=ve;
                dfsVisit(i.second);
            }
            if(i.second->color=='g')
            {
            	lock=1;
                cout<<"Cycle:"<<counter<<"    |PATH: ";
                int temp=i.second->value;
                path.push_back(i.second->value);
                path.push_back(ve->value);

                while(ve2->parent!=i.second)
                {
                    if (ve2->parent == NULL) break;
                	path.push_back(ve2->parent->value);
                    ve2 = ve2->parent;
                }
                if((path[0]==path[1])==false) path.push_back(temp);
                reverse(path.begin(), path.end());
                for(auto i:path) cout<<i<<" ";
                cout<<"|"<<endl;
            	path.clear();
                counter++;
            }
        }
        ve->color='b';
        ++time;
        ve->f=time;
    }

};

vector<vector<int>> createMatrix(int a, double p)
{
    vector<vector<int>>Matrix;
    vector<int> temp;
    for(int i=0;i<a;i++) temp.push_back(0);
    for(int j=0;j<a;j++)
    {
        Matrix.push_back(temp);
    }

    for(int i=0;i<a;i++)
    {
            for(int j=0;j<i;j++)
            {
                int r=rand()%100; 
                if(r<=(p*100)) Matrix.at(i).at(j)=1;
                else Matrix.at(i).at(j)=0;          
            }
    }
    return Matrix;
}

auto lamba_print=[](auto m){for(auto i:m){for(auto j:i) cout<<j<<" "; cout<<endl; }};


int main()
{
    double size,p,a,b;
    cin>>size>>p;
    auto mat=createMatrix(size,p);
    size=mat.size();
    Graph *graph = new Graph(size, mat);
    auto list=graph->DFS();
    lamba_print(mat);
    sort( list.begin(), list.end(), []( Node & a, Node & b )->bool { return a.d > b.d; });
    for(auto i:list) cout<< "Node:"<<i.value<<"  "<<"d:"<<i.d<<endl;

}
