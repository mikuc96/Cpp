#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;


auto get_data()
{
    vector<int> v;
    v.push_back(0);
    string line;
    int number;
    getline(cin, line);
    istringstream stream(line);

        while (stream >> number)
            v.push_back(number);
    return v;
}

auto draw(vector<int> a)
{
	for(int i:a)
	{
		cout<<i<<" ";
	}
}

auto left_index   (auto i){return (2*i);}
auto right_index (auto i){return ((2*i) + 1);}
auto father_index(auto i){return i/2;}

void fix_heap(vector<int> *a)
{
	int size=a->size()-1;
	int max,left,right;	
	int height=log2(size);

	while(height)
	{
			for(int i=1;i<=father_index(size);i++)
			{
				left=left_index(i);
				right=right_index(i);

				if(left<=size && a->at(left)>a->at(i))
				{		
				  max=left;
				} else max=i;

				if(right<=size && a->at(right) > a->at(max)) max=right;
				if(max!=i) swap(a->at(i),a->at(max));
			}
		height--;
	}
}

int get_root(vector<int> *a)
{
	int size=a->size()-1;
	int root;
	if(size>1)
	{
		root=a->at(1);
		swap(a->at(1),a->at(size));
		a->pop_back();
		fix_heap(a);
	}else 
	{
		root=a->at(1);
		a->pop_back();
	} 
	size--;
	return root;
}

void add_element(vector<int> *a, int element)
{
	a->push_back(element);
	fix_heap(a);
}
auto heap_sort(vector<int> *a)
{
	int size=a->size()-1;
	vector<int> sorted;
	for(int i=1; i<=size;i++)
	{
		sorted.push_back(get_root(a));
	}
	return sorted;
}

int main()
{
	int x,root,element;
	vector<int> sorted;
	cout<<"Enter data: ";
	auto a=get_data();

	cout<<"====================="<<endl;
	cout<<"1.Fix_heap"<<endl;
	cout<<"2.Get_root"<<endl;
	cout<<"3.Add element"<<endl;
	cout<<"4.Heap_Sort"<<endl;
	cout<<"5.Draw"<<endl;
	cout<<"6.Exit"<<endl;
	cout<<"====================="<<endl;

	while(true)
	{	cin>>x;
		switch(x)
		{
			case 1:
			cout<<"Fixed heap: ";
				fix_heap(&a);
				draw(a);
				cout<<endl;
				break;

			case 2:
				root=get_root(&a);
				cout<<"Root: "<<root<<endl;
				break;

			case 3:
				element;
				cout<<"Enter element: ";cin>>element;
				add_element(&a, element);
				break;
			case 4:

				sorted= heap_sort(&a);
			    reverse(sorted.begin(),sorted.end());
				cout<<"Sorted: ";
				draw(sorted);
				break;	

			case 5:
				cout<<"-------------------------------"<<endl;
				draw(a);cout<<endl;		
				cout<<"-------------------------------"<<endl;
				break;

			case 6:
			    exit(0);
		}
	}	
}