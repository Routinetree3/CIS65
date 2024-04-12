#pragma once
#include "unsorted.h"
#include "ItemType.h"

using namespace std;

class ItemScanner
{
public:
	/*************************************************************************
	******
	* Function Name: CreateInventroy
	* Parameters: ifstream &fileToRead
	* Return Value: UnsortedType
	* Purpose: Creates an Inventory List
	*************************************************************************
	******/
	UnsortedType CreateInventroy(ifstream& fileToRead);
	/*************************************************************************
	******
	* Function Name: EnterCustomerItems
	* Parameters:
	* Return Value: UnsortedType
	* Purpose: Handles entering of Items
	*************************************************************************
	******/
	UnsortedType EnterCustomerItems();
	/*************************************************************************
	******
	* Function Name: EnterCustomerItems
	* Parameters:
	* Return Value: UnsortedType
	* Purpose: Print the customers Recept
	*************************************************************************
	******/
	void PrintRecept(UnsortedType CustomerItems, UnsortedType Inventory, int CustomerNumber);

private:
	UnsortedType ItemInventory;
	UnsortedType CustomerList;
	float Tax = 1.3f;

public:
	UnsortedType GetCustomerList();				// Simple Getter for the Customers List
};

