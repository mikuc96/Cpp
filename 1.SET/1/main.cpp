
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#include "Fx.cpp"

int main()
{
	cout<<endl;
    cout<<"Podaj dane pierwszego zbioru: ";
    auto a= get_data();
    cout<<"Podaj dane drugiego zbioru: ";
    auto b= get_data();
    cout<<endl;
    vector<int> suma=union_sets(a,b);
    cout<<"Union | A u B |: ";
    draw(suma);


    cout<<"Intersection | A n B | : ";
    vector<int> iloczyn=intersections(a,b);
    draw(iloczyn);

    cout<<"Difference | A/B | : ";
    vector<int>diff=difference(a,b);
    draw(diff);

     cout<<"Symmetric difference | (A/B) u (B/A) | : ";
    draw(difference(suma,iloczyn));

    cout<<endl;     
}

