// [0] Add
// [0] Delete
// [0] Edit
// [0] Sort by name
// [0] Sort by shop
// [0] Print all goods
// [0] Print goods filtered by shop
//


#pragma once
#include <fstream>
using namespace std;

struct Goods
{
	char name[100];
	char shop[100];
	double price;
	double amount;
	char meas[20];
	int code;

	void print()
	{
		cout << "\n\n\tCode: " << code;
		cout << "\n\tName: " << name;
		cout << "\n\tShop: " << shop;
		cout << "\n\tPrice: " << price;
		cout << "\n\tAmount: " << amount;
		cout << "\n\tMeasurement: " << meas;
	}
};

char NameCorrector(char name)//Increases the first letters 
{
	if (name >= 97 && name <= 122)
	{
		name = name - 32;
	}
	return name;
}

void Add_f()
{
	Goods goods_s;

	cout << "\n\n\tEnter:\n\tName: ";	cin >> goods_s.name;
	goods_s.name[0] = NameCorrector(goods_s.name[0]);

	cout << "\tShop: ";					cin >> goods_s.shop;
	goods_s.shop[0] = NameCorrector(goods_s.shop[0]);

	cout << "\tPrice: ";				cin >> goods_s.price;
	cout << "\tAmount: ";				cin >> goods_s.amount;
	cout << "\tMeasurement: ";			cin >> goods_s.meas;
	goods_s.meas[0] = NameCorrector(goods_s.meas[0]);


	ifstream in;

	in.open("file.dat", ios::binary);

	in.seekg(0, ios::end);
	int size = in.tellg();
	size /= sizeof(Goods);
	in.seekg(0, ios::beg);
	in.close();

	goods_s.code = size + 1;

	ofstream out;

	out.open("file.dat", ios::binary | ios::app);

	if (!out.write((char*)&goods_s, sizeof(Goods)))
	{
		cerr << "\n\n\tWRITE ERROR!\n\n\n";
	}
	out.close();
}

Goods* Read_File_f(int& size)// and create array
{
	ifstream in;

	in.open("file.dat", ios::binary);

	in.seekg(0, ios::end);
	size = in.tellg();
	size /= sizeof(Goods);
	in.seekg(0, ios::beg);
	Goods* goods_a = new Goods[size];

	if (!in.read((char*)goods_a, size * sizeof(Goods)))
	{
		cerr << "\n\n\tREAD ERROR!\n\n\n";
	}
	in.close();
	return goods_a;
}

void Print_arr_f(Goods* goods_a, int& size)
{
	for (int i = 0; i < size; i++)
	{
		goods_a[i].print();
	}
}

void Print_goods_f()
{
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	Print_arr_f(goods_a, size);
	
	delete[] goods_a;
}

void Filter_by_shop_f()
{
	string in_shop;
	//char in_shop[100];
	cout << "\n\n\tEnter shop name: ";	cin >> in_shop;

	int size = 0;
	Goods* goods_a = Read_File_f(size);
	Goods* goods_sf_a = new Goods[size];
	int size_sf = 0;

	for (int i = 0; i < size; i++)
	{
		if (goods_a[i].shop == in_shop)
		{
			goods_sf_a[size_sf] = goods_a[i];
			size_sf++;
		}
	}

	Print_arr_f(goods_sf_a, size_sf);

	delete[] goods_sf_a;
	delete[] goods_a;
}

void Write_File_f(Goods* goods_a, int& size)
{
	ofstream out;

	out.open("file.dat", ios::binary);

	if (!out.write((char*)goods_a, size * sizeof(Goods)))
	{
		cerr << "\n\n\tWRITE ERROR!\n\n\n";
	}
	out.close();
}

void Delete_f()
{
	int code = 0;
	cout << "\n\n\tEnter goods code: ";	cin >> code;
	int size = 0;
	Goods* goods_a = Read_File_f(size);
	
	for (int i = 0; i < size; i++)
	{
		if (goods_a[i].code == code)
		{
			swap(goods_a[i], goods_a[size - 1]);
			size--;
		}
	}
	Goods* goods_edited_a = new Goods[size];

	for (int i = 0; i < size; i++)
	{
		goods_edited_a[i] = goods_a[i];
	}
	delete[] goods_a;

	Write_File_f(goods_edited_a, size);
	delete[] goods_edited_a;
}

void Edit_f()
{
	int code = 0;
	cout << "\n\n\tEnter goods code: ";	cin >> code;
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	for (int i = 0; i < size; i++)
	{
		if (goods_a[i].code == code)
		{
			char ch;
			cout << "\n\n\tEdit ";

			cout << "\n\tName: " << goods_a[i].name;			
			cout << "\n\tEdit name?\t(y/n)\n\t";	cin >> ch;
			if (ch == 'y')
			{
				cout << "\n\tEnter new name: ";	cin >> goods_a[i].name;
				goods_a[i].name[0] = NameCorrector(goods_a[i].name[0]);
			}

			cout << "\n\tShop: " << goods_a[i].shop;
			cout << "\n\tEdit shop?\t(y/n)\n\t";	cin >> ch;
			if (ch == 'y')
			{
				cout << "\n\tEnter new shop: ";	cin >> goods_a[i].shop;
				goods_a[i].shop[0] = NameCorrector(goods_a[i].shop[0]);
			}

			cout << "\n\tPrice: " << goods_a[i].price;
			cout << "\n\tEdit price?\t(y/n)\n\t";	cin >> ch;
			if (ch == 'y')
			{
				cout << "\n\tEnter new price: ";	cin >> goods_a[i].price;
			}

			cout << "\n\tAmount: " << goods_a[i].amount;
			cout << "\n\tEdit Amount?\t(y/n)\n\t";	cin >> ch;
			if (ch == 'y')
			{
				cout << "\n\tEnter new Amount: ";	cin >> goods_a[i].amount;
			}
			
			cout << "\n\tMeasurement: " << goods_a[i].meas;
			cout << "\n\tEdit Measurement?\t(y/n)\n\t";	cin >> ch;
			if (ch == 'y')
			{
				cout << "\n\tEnter new Measurement: ";	cin >> goods_a[i].meas;
				goods_a[i].meas[0] = NameCorrector(goods_a[i].meas[0]);
			}
		}
	}
	Write_File_f(goods_a, size);
	delete[] goods_a;
}

void Sort_By_Shop_f()
{
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	bool swaped = false;

	do
	{
		swaped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (goods_a[i].shop[0] > goods_a[i + 1].shop[0])
			{
				swap(goods_a[i], goods_a[i + 1]);
				swaped = true;
			}
		}
	} while (swaped);

	Write_File_f(goods_a, size);
	delete[] goods_a;
}

void Sort_By_Name_f()
{
	int size = 0;
	Goods* goods_a = Read_File_f(size);

	bool swaped = false;

	do
	{
		swaped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (goods_a[i].name[0] > goods_a[i + 1].name[0])
			{
				swap(goods_a[i], goods_a[i + 1]);
				swaped = true;
			}
		}
	} while (swaped);

	Write_File_f(goods_a, size);
	delete[] goods_a;
}