#include "Fx.h"

auto draw(vector<int> a)
{
        for(auto i:a) cout<<i<<" ";  
        cout<<endl;
}

auto get_data()
{
    vector<int> v;
    string line;
    int number;
    getline(cin, line);
    istringstream stream(line);

        while (stream >> number)
            v.push_back(number);

    return v;
}

auto union_sets(auto a, auto b)
{
	vector <int> suma;
    for(auto i:a)  suma.push_back(i);
    for(auto i:b) suma.push_back(i);
    sort(suma.begin(),suma.end());

    int prev;
    for(int i=0; i<suma.size()-1;i++)
    {
        if(suma.at(i)==suma.at(i+1))
        {
            suma.erase(suma.begin() + (i));  
        }
    }
    return suma;

}
auto intersections(auto a, auto b)
{
    vector<int> multi;
    
    for(auto i:a)
    {
        for(auto j:b)
        {
            if(i==j)
            {
                multi.push_back(i);        
            }
        }
    }
    return multi;
}

auto difference(auto a, auto b){
    vector<int> diff;
    for(int i:a){
        int lock=0;
        for(int j:b){
            if(i==j) lock=1;
        }
        if(lock==1) continue;
        diff.push_back(i);
    }
    return diff;
}
