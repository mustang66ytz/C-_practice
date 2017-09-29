#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include "inventory.h"
using namespace std;

struct ListItem
{
	string name;
	int amount;
	ListItem()
	 : name("non"),
	   amount(0)
	{}

	ListItem(const string& t, int n)
	 : name(t),
	   amount(n)
	{
	}

};



class Inventory
{
	
public:
	Inventory();

	
	void Update(string t, int n);

	void ListByName();	
	
	void ListByQuantity();

private:
	
	vector<ListItem> items;
	
	// TODO:You provide this.
};


Inventory::Inventory()
 : items(0){
	items.reserve(10);
}


void Inventory::Update(string t, int n)
{

	bool foundItem = false;
	int num = items.size();

	cout<<"the size of the vector is "<<num<<endl;

	for (int i = 0; i < num; i++) {
		if (items.at(i).name == t){
			items.at(i).amount += n;
			foundItem = true;
		}
	}

	if (!foundItem){
		//ListItem caocaocao(t, n);
		items.push_back(ListItem(t,n));
	}
	
		
}

void Inventory::ListByName()
{
	int i;
	int len = items.size();
	for (i=0; i<len; i++)
	{
		cout<<items[i].name<<" "<<items[i].amount<<endl;
	}
}


void Inventory::ListByQuantity()
{
	int i;
	int len = items.size();
	for (i=0; i<len; i++)
	{
		cout<<items[i].name<<" "<<items[i].amount<<endl;
	}
}


int main()
{
	

	
	int i = 0, amount;
	bool toStop = false;
	string flag; 
	string name;
	Inventory invent;


	while(true)
	{
		cout<<"Enter the "<<i<<"th item's name and amount:"<<endl;
		cout<<"Enter 'q' to quit, 'c' to continue "<<endl;
		cin>>flag;
		if(flag == "q")
		break;
		else if (flag == "c")
		{	cin>>name>>amount;
			// Inventory invent(name, amount);
			invent.Update(name, amount);
			//cout<<invent.name<<endl;
		}
		i++;

	}
	
	cout<<"finish loading"<<endl;
	//Inventory item(Listitem);
	invent.ListByName();
	invent.ListByQuantity();
//	cout<<items[0].amount<<endl;
	
}

