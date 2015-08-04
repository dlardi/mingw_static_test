# mingw_static_test
Test for explicit instantiation in different modules

I use gcc-5.1.0 on Windows (mingw-w64 build). I have the following template class:

template <class T>
struct StaticObject
{
   static T & getInstance()
   {
     static T t;
     std::cout << "static object " << typeid(T).name() << " at " << &t << " = "<< t <<std::endl;
     return t;
   }
};

What i want to achieve is to have one instance of say StaticObject<int> through my EXE and several DLLs modules with use of explicit instantiation.
So in one of my DLLs (inst.dll) i have explicit instantiation of StaticObject<int> - inst.cpp:

\#include "static_object.h"

template struct StaticObject<int>;

And there is \#include "externs.h" in each source file that use this static object to prevent it from implicit instantiation - externs.h :

\#pragma once

\#include "static_object.h"

extern template struct StaticObject<int>;

There is calls to StaticObject<int>::getInstance() in EXE and DLL modules and what i get is different behavior with optimisation turned on and off. 
It works as expected:
1) with optimisation turned off and 
2) with following flags: "-Ox -fno-inline", where 'x' is one of optimisation levels 1,2,3.

And it doesn't work with any (1,2,3) level of optimisation turned on, so i get instances of StaticObject<int> in each DLL and EXE.
