#pragma once

#include <iostream>
#include <typeinfo>

template <class T>
struct StaticObject
{
    static T & getInstance()
    {
      static T t;
      std::cout << "static object " << typeid(T).name() << " at " << &t << " = "<< t << std::endl;
      return t;
    }
};
