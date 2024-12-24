#include "class.h"

Class::Class(int value) : _value(value) {}
int Class::getValue() const { return _value; }
void Class::setValue(int value) { _value = value; }
bool Class::isRed() const { return _value == 0xff0000; };
