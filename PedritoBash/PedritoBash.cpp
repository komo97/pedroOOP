// PedritoBash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DLinkedList.h"
#include <iostream>
#include <string>

typedef struct MenuItem {
	MenuItem()
	{
		contents = NULL;
	}
	MenuItem(std::string n, MenuItem* _parent) : MenuItem()
	{
		name = n;
		parent = _parent;
	}
	DLinkedList<MenuItem>* contents;
	std::string name;
	MenuItem* parent;

}MenuItem;

bool operator==(const MenuItem& lhs, const MenuItem& rhs)
{
	return (lhs.name == rhs.name);
}

bool operator!=(const MenuItem& lhs, const MenuItem& rhs)
{
	return !(lhs.name == rhs.name);
}

std::ostream& operator << (std::ostream& lhs, const MenuItem& rhs)
{
	lhs.write(rhs.name.c_str(),rhs.name.size());
	return lhs;
}

int hash(std::string word)
{
	int h = 0;
	while (word != "")
	{
		h += (int)word.back() % 30;
		word.pop_back();
	}
	return h;
}

unsigned int ListContains(DLinkedList<MenuItem>* menu,const std::string& item)
{
	DNode<MenuItem>* ref = NULL;
	ref = menu->GetHead();
	unsigned int count = 0;
	while (ref != NULL)
	{
		if (ref->element.name == item)
			return count;
		ref = ref->next;
		++count;
	} 
	return -1;

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	DLinkedList<MenuItem>* menuItems = new DLinkedList<MenuItem>(MenuItem("root",NULL));
	MenuItem *root, *selection = root = &menuItems->GetHead()->element;
	std::string selectOption, itemOption;
	int val;
	unsigned int sel;
	const int cd1 = hash("cd");
	const int cd2 = hash("-c");
	const int add1 = hash("add");
	const int add2 = hash("-a");
	const int rem1 = hash("rem");
	const int rem2 = hash("-r");
	const int show1 = hash("ls");
	const int show2 = hash("-l");
	const int help1 = hash("help");
	const int help2 = hash("-h");

	std::cout << "Use help 0 for instructions." << std::endl;
	while (1)
	{
 		std::cin >> selectOption >> itemOption;
		
 		val = hash(selectOption);
		if (itemOption == "")
			continue;
		else if (val == cd1 || val == cd2)
		{
			if (itemOption == "last")
			{
				if (selection->parent == NULL)
					continue;
				selection = &selection->parent->contents->
					Search(MenuItem(selection->name, selection->parent))->last->element;
				std::cout << "\"" << selection->name << "\" is selected." << std::endl;
				continue;
			}
			else if (itemOption == "next")
			{
				if (selection->parent == NULL)
					continue;
				selection = &selection->parent->contents->
					Search(MenuItem(selection->name, selection->parent))->next->element;
				std::cout << "\"" << selection->name << "\" is selected." << std::endl;
				continue;
			}
			else if (itemOption == "back")
			{
				if (selection->parent == NULL )
					continue;
				selection = selection->parent;
				std::cout << "\"" << selection->name << "\" is selected." << std::endl;
				continue;
			}
			if (selection->contents == NULL)
			{
				std::wcout << "Directory is empty." << std::endl;
				continue;
			}
			sel = ListContains(selection->contents, itemOption);
			if (sel == -1)
			{
				std::cout << "No element with that name exists." << std::endl;
				continue;
			}
			selection = &selection->contents->GetAtIndex(sel)->element;
			std::cout << "\"" << selection->name << "\" is selected." << std::endl;
		}
		else if (val == add1 || val == add2)
		{
			if (itemOption == "last" || itemOption == "next"
				|| itemOption == "back")
			{
				std::cout << "Can't add element with that name." << std::endl;
				continue;
			}
			if (selection->contents == NULL)
			{
				selection->contents = new DLinkedList<MenuItem>(MenuItem(itemOption,selection));
				std::cout << "Menu option added to " << selection->name << "." << std::endl;
				continue;
			}
			if (ListContains(selection->contents, itemOption) != -1)
			{
				std::cout << "Element already exists." << std::endl;
				continue;
			}
			if (selection == root)
			{
				selection->contents->Insert(MenuItem(itemOption,selection));
				std::cout << "Menu option added to Root." << std::endl;
				continue;
			}
			selection->contents->Insert(MenuItem(itemOption,selection));
			std::cout << "Menu option added to " << selection->name << "." << std::endl;
		}
		else if (val == rem1 || val == rem2)
		{
			if (selection->contents == NULL)
			{
				std::cout << "Current directory is empty." << std::endl;
				continue;
			}
			else if (ListContains(selection->contents, itemOption) == -1 || 
				itemOption == "last" || itemOption == "next" || itemOption == "back")
			{
				std::cout << "Element does not exist in the current directory." << std::endl;
				continue;
			}
			else if (selection == root)
			{
				selection->contents->Remove(MenuItem(itemOption,selection));
				std::cout << "Menu option removed from Root." << std::endl;
				continue;
			}
			selection->contents->Remove(MenuItem(itemOption,selection));
			std::cout << "Menu option removed from " << selection->name << "." << std::endl;
		}
		else if (val == show1 || val == show2)
		{
			if (itemOption == "0")
			{
				std::cout << "-----------------\n";
				if (selection->contents != NULL)
					selection->contents->PrintAll();
				std::cout << "-----------------\n";
				continue;
			}
			std::cout << "Only available parameter is 0" << std::endl;

		}
		else if (val == help1 || val == help2)
		{
			if (itemOption == "0")
			{
				std::cout << "cd/-c X: Change directory." << std::endl
					<< "   X: next = Next element in current dir." << std::endl
					<< "   X: las = Last element in current dir." << std::endl
					<< "   X: back = Up one dir." << std::endl
					<< "add/-a name: Adds a directory to the current directory." << std::endl
					<< "rem/-r name: Removes a directory from the current directory." << std::endl
					<< "ls/-l 0: Shows directories in current directory." << std::endl
					<< "help/-h 0: Shows help." << std::endl;
				continue;
			}
			std::cout << "Only available parameter is 0" << std::endl;
		}
		else
		{
			std::wcout << "Unknown command." << std::endl;
		}
	}
    return 0;
}

