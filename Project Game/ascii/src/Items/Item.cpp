//
// Created by Devon on 9/26/2018.
//

#include "Item.h"

Item::Item(std::string name, std::string desctiption, int value) :
                                                                    _name(name),
                                                                    _descrip(desctiption),
                                                                    _value(value)
{
}

std::string Item::name() const
{
    return _name;
}

std::string Item::description() const
{
    return _descrip;
}

int Item::value() const
{
    return _value;
}
