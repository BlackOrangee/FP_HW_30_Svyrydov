// There is a list of products. For each product, its name, the name of the store where the product is sold, 
// the unit price of the product in hryvnias and its quantity with an indication of the unit of measurement are indicated 
// (for example, quantity: 100 pcs., unit of measurement: package of 20 kg). 
// Write a program that performs the following actions:
// 
// ● Adjusting the list from the keyboard(adding, removing, editing information);
// ● Sorting by product name or store name;
// ● Displaying product information on the screen
// ● Display of information about goods sold in the store, the name of which is entered from the keyboard.
// 

#include <iostream>
#include "Logic.h"
#include "Menu.h"
using namespace std;

int main()
{
	for (;;)
		menu();
}
