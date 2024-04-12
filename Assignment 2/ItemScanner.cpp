
#include "ItemScanner.h"
#include "iostream"
#include <fstream>
#include <string>

UnsortedType ItemScanner::CreateInventroy(ifstream& fileToRead)
{
	ItemType Item;								// delcare item object
	UnsortedType outList;						// delcare list

	int counter = 0;
	while (fileToRead.good() && counter < 200) // loop through the inventory file, transferting data to an unsorted list
	{
		//initialize local variable
		int ItemNumber = 0;
		string ItemDiscription = " ";
		float ItemPrice = 0;
		char ItemTaxable = 'N';

		switch (counter) //Using counter to switch variable types
		{
		case 0:
			fileToRead >> ItemNumber;        // transfer data from the file
			Item.SetItemNumber(ItemNumber);  // set the value on the item class
			cout << ItemNumber << " | ";     // print the value to the counsole
			break;							 // Repeat for other data types
		case 1:
			fileToRead >> ItemDiscription;
			Item.SetItemDescription(ItemDiscription);
			cout << ItemDiscription << " | ";
			break;
		case 2:
			fileToRead >> ItemPrice;
			Item.SetPrice(ItemPrice);
			cout << ItemPrice << " | ";
			break;
		case 3:
			fileToRead >> ItemTaxable;
			Item.SetTaxAble(ItemTaxable);
			cout << ItemTaxable << " | ";
			cout << endl;
			break;
		default:
			break;
		}
		counter++;
		if (counter == 4)					//once counter reaches threshold... reset
		{
			counter = 0;
			outList.PutItem(Item);			//store the initalized item to the list
		}
	}
	
	return outList;
}

UnsortedType ItemScanner::EnterCustomerItems()
{
	cout << "Please insert item number then amount" << endl;
	cout << "insert 0 when compleate" << endl;
	cout << "------------------------------------------------------" << endl;

	//initialize local variable
	int ItemNumber = 9999;
	float ItemAmount = 0;
	ItemType CurrentItem;
	UnsortedType List;

	// loop requests for information about the customers items
	while (ItemNumber != 0)
	{
		cin >> ItemNumber;				//Request Item Number
		if (ItemNumber == 0)			//Check if break input
		{
			break;	
		}
		cin >> ItemAmount;					//Request Amount of that Item
		cout << "----------" << endl;
		CurrentItem.SetItemNumber(ItemNumber);		//Set data to the Item
		CurrentItem.SetAmount(ItemAmount);
		List.PutItem(CurrentItem);					//Add Item to List
	}
	return List;
}

void ItemScanner::PrintRecept(UnsortedType CustomerItems, UnsortedType Inventory, int CustomerNumber)
{
	cout << endl << "To 'Receipts.out' file:" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Customer " << CustomerNumber << endl;
	cout << "Length " << CustomerItems.GetLength() << endl;
	cout << "------------------------------------------------------" << endl;

	//initialize local variable
	ofstream ReceiptsFile("Receipts.out");
	float TotalValue = 0.f;
	float UntaxedValue = 0.f;

	for (int i = 0; i < CustomerItems.GetLength(); i++)
	{
		bool found = false;
		ItemType CustomerItem = CustomerItems.GetNextItem();
		ItemType CurrentItem = Inventory.GetItem(CustomerItem, found);											// Search for the customers Item in the Item List
		if (found)
		{
			cout << CurrentItem.GetDiscription() << "   " << CurrentItem.GetPrice() << "   @   ";				// Print Inital Item Information to console and file
			ReceiptsFile << CurrentItem.GetDiscription() << "   " << CurrentItem.GetPrice() << "   @   ";

			float NewPrice = 0;

			if (CurrentItem.GetAmount() > 0)								 							// Check to see if there are more then 1 items
			{
				NewPrice = CurrentItem.GetAmount() * CurrentItem.GetPrice();							// If so calculate the price
				if (CurrentItem.GetTaxAble() == 'T' || CurrentItem.GetTaxAble() == 't')					// Check if Item is taxable
				{
					NewPrice = NewPrice * Tax;															// If so... calculate the tax and add it to the outputs
					cout << endl << "|" << NewPrice << "|";
					ReceiptsFile << endl << "|" << NewPrice << "|";
				}
				else
				{
					cout << NewPrice;																	// Print out untaxed value
				}																
			}
			else
			{
				if (CurrentItem.GetTaxAble() == 'T' || CurrentItem.GetTaxAble() == 't')					// Check if Item is taxable
				{
					cout << CurrentItem.GetPrice() * Tax;												// If so... calculate the tax and add it to the outputs
					ReceiptsFile << CurrentItem.GetPrice() * Tax;
				}
				else																					// if not then add price to the outputs
				{
					cout << CurrentItem.GetPrice();
					ReceiptsFile << CurrentItem.GetPrice();
				}
			}
			cout << endl;
		}
		else
		{
			cout << "----------" << CustomerItem.GetItemNumber() << " Not Found " << "----------";				// if Item is not found, inform the user
			ReceiptsFile << "----------" << CustomerItem.GetItemNumber() << " Not Found " << "----------";
		}
		cout << endl;
		ReceiptsFile << endl;
	}
	ReceiptsFile.close();
}

UnsortedType ItemScanner::GetCustomerList()
{
	return CustomerList;
}

