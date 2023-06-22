#pragma once
using namespace std;

enum e_Menu
{
	Edit_m = 1, Sotr, Print, Filter
};

enum e_Edit_menu
{
	Add = 1, Delete, Edit
};

enum e_Sort_menu
{
	By_Shop = 1, By_Name
};

void Edit_menu()
{
	int menu = 0;
	cout << "\n\n\tEdit Menu\n\n\t1 -- Add\n\t2 -- Delete\n\t3 -- Edit\n\t";	cin >> menu;

	switch ((e_Edit_menu)menu)
	{
	case Add:
		Add_f();
		break;
	case Delete:
		Delete_f();
		break;
	case Edit:
		Edit_f();
		break;
	default:
		break;
	}
}

void Sort_menu()
{
	int menu = 0;
	cout << "\n\n\tSort Menu\n\n\t1 -- Sort by shop name\n\t2 -- Sort by goods name\n\t";	cin >> menu;

	switch ((e_Sort_menu)menu)
	{
	case By_Shop:
		Sort_By_Shop_f();
		break;
	case By_Name:
		Sort_By_Name_f();
		break;
	default:
		break;
	}
}

void menu()
{
	int menu = 0;
	cout << "\n\n\tMain Menu\n\n\t1 -- Edit\n\t2 -- Sotr\n\t3 -- Print\n\t4 -- Filter by shop\n\t";	cin >> menu;

	switch ((e_Menu)menu)
	{
	case Edit_m:
		Edit_menu();
		break;
	case Sotr:
		Sort_menu();
		break;
	case Print:
		//Read_and_Print_File_f();
		Print_goods_f();
		break;
	case Filter:
		//Read_Filter_and_Print_File_f();
		Filter_by_shop_f();
		break;
	default:
		break;
	}
}
