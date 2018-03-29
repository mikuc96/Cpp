
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

void draw(vector<int> a);
vector<int> get_data();


int main()
{
	cout<<endl;
    cout<<"Podaj dane pierwszego zbioru: ";
    vector<int> a= get_data();
    cout<<"Podaj dane drugiego zbioru: ";
    vector<int> b= get_data();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    cout<<endl;
    vector<int> suma;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(suma));
    cout<<"Union | A u B |: ";
    draw(suma);


    cout<<"Intersection | A n B | : ";
    vector<int> iloczyn;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(iloczyn));
    draw(iloczyn);

    cout<<"Difference | A/B | : ";
    vector<int>diff;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff));
    draw(diff);

    cout<<"Symmetric difference | (A/B) u (B/A) | : ";
    vector<int>symmetric;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(symmetric));
    draw(symmetric);

    cout<<endl;     
}

void draw(vector<int> a)
{
        for(int i:a) 
        	{
        		cout<<i<<" ";  
        	}
        cout<<endl;
}

vector<int> get_data()
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