#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node 
{
public:
    enum Color { white, gray, black };
    Color color = Color::white;
    string name;
    multimap<int, shared_ptr<Node>> n;
    shared_ptr<Node> parent;
    int distance = 0;
    int last_visit = 0;
    bool inf = true;
};

class Graph 
{
public:
    unordered_map<string, shared_ptr<Node>> nodes;
    void addNode(string name)
    {
        auto node = make_shared<Node>();
        node->name = name;
        nodes[name] = node;
    }
    void addNeighbor(string parent, string kid, int distance) 
    {
        shared_ptr<Node> k = getRoot(kid);
        shared_ptr<Node> p = getRoot(parent);
        if (p == nullptr || k == nullptr) {
            cout << "error";
            return;
        }
        p->n.insert(pair<int, shared_ptr<Node>>(distance, k));

    }
    
    shared_ptr<Node> getRoot(string name) 
    {
        shared_ptr<Node> x = nullptr;
        try {
            x = nodes.at(name);
        }
        catch (std::out_of_range &e) {
            return nullptr;
        }
        return x;

    }
    void dijkstra(string start) 
    {
        shared_ptr<Node> st = getRoot(start);
        if (st == nullptr) {
            cout << "Error" << start;
            return;
        }
        multimap<int, shared_ptr<Node>> list;
        multimap<int, shared_ptr<Node>>::iterator it;
        st->inf = false;
        list.insert(pair<int, shared_ptr<Node>>(0, st));
        while (!list.empty()) 
        {
            it = list.begin();
            auto elem = it;

            for (auto &i : elem->second->n) {
                if (i.second->inf == true || i.second->distance > elem->second->distance + i.first) {
                    i.second->inf = false;
                    i.second->distance = elem->first + i.first;
                    i.second->parent = elem->second;
                    list.insert(pair<int, shared_ptr<Node>>(i.second->distance, i.second));
                }
            }

            list.erase(it);
        }
    }
    void dispDistance()
    {
        vector<pair<string,string>> out;
        for (auto& i : nodes) 
        {
            string name =  i.second->name;
            string dst;
            if (i.second->inf) dst =  "∞";
            else dst = to_string(i.second->distance);
            out.push_back(pair<string,string>(name,dst));
        }

        sort(out.begin(), out.end(),
             [](const auto & a, const auto & b) -> bool
             {
                 return a.first < b.first;
             });

        for (auto& i : out) {
            cout << i.first << " " << i.second << endl;
          }
    }
};

int main(int argc, char* argv[]) {

    string dest;
    auto graph = make_shared<Graph>();
    ifstream myfile("input.txt");

    if (!myfile) {
        cout << "Nie można otworzyć pliku" << endl;
        return -1;
    }
    int total_nodes = 0;
    myfile >> total_nodes;
    string a, b;

    for(int i=0; total_nodes > i; i++) {
        myfile >> a;
        graph->addNode(a);
    }
    string line;
    int total_connection;
    myfile>>dest;
    myfile >> total_connection;
    int distance;
    for(int i=0; total_connection > i; i++) {
        myfile >> a >> b >> distance;
        graph->addNeighbor(a, b, distance);
    }
    graph->dijkstra(dest);
    graph->dispDistance();
}