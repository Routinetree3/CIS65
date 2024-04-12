// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"


ItemType::ItemType()
{ 
    ProductNumber = 0;
    Discription = "";
    Price = 0;
    TaxAble = 'N';
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (ProductNumber < otherItem.ProductNumber)
    return LESS;
  else if (ProductNumber > otherItem.ProductNumber)
    return GREATER;
  else return EQUAL;
}

void ItemType::Print(std::ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    out << ProductNumber << Discription << Price << TaxAble;
}

void ItemType::SetItemNumber(int ItemNumber)
{
    ProductNumber = ItemNumber;
}

void ItemType::SetItemDescription(std::string ItemString)
{
    Discription = ItemString;
}

void ItemType::SetPrice(float ItemPrice)
{
    Price = ItemPrice;
}

void ItemType::SetTaxAble(char ItemTaxAble)
{
    TaxAble = ItemTaxAble;
}

void ItemType::SetAmount(float ItemAmount)
{
    std::cout << ItemAmount;
    Amount = ItemAmount;
    std::cout << " : " << Amount << std::endl;
}

int ItemType::GetItemNumber()
{
    return ProductNumber;
}

std::string ItemType::GetDiscription()
{
    return Discription;
}

float ItemType::GetPrice()
{
    return Price;
}

char ItemType::GetTaxAble()
{
    return TaxAble;
}

float ItemType::GetAmount()
{
    std::cout << Amount;
    return Amount;
}