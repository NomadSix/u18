//
// Created by Devon on 9/26/2018.
//

#ifndef ASCII_ITEM_H
#define ASCII_ITEM_H

#include <string>

class Item
{
public:
    //Default
    Item (std::string name, std::string desctiption, int value);
    //Outputs item name
    std::string name() const;
    //Returns item description
    std::string description() const;
    //returns the value of item
    int value() const;

private:
    std::string _name;
    std::string _descrip;
    int _value;
};

#endif //ASCII_ITEM_H
