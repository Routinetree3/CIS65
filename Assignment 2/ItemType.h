// The following declarations and definitions go into file 
// ItemType.h. 
#pragma once

#include <fstream>
#include <string>

const int MAX_ITEMS = 50;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;

  /*************************************************************************
  ******
  * Functions Names: Data Setters
  * Parameters: int ItemNumber, std::string ItemString ,float ItemPrice ,char ItemTaxAble, int ItemAmount
  * Return Value: void
  * Purpose: Sets the values of the Item
  *************************************************************************
  ******/
  void SetItemNumber(int ItemNumber);
  void SetItemDescription(std::string ItemString);
  void SetPrice(float ItemPrice);
  void SetTaxAble(char ItemTaxAble);
  void SetAmount(float ItemAmount);

  /*************************************************************************
  ******
  * Function Name: Data Getters
  * Parameters:
  * Return Value: int, std::string, float, char, int
  * Purpose: Getters for the Items values
  *************************************************************************
  ******/
  int GetItemNumber();
  std::string GetDiscription();
  float GetPrice();
  char GetTaxAble();
  float GetAmount();

private:
	int ProductNumber = 0;
	std::string Discription;
	float Price = 0;
	char TaxAble;
	float Amount = 0;
};
 
