//
// Created by Святослав on 29.04.2024.
//
#pragma once

#include "Object.h"
#include "CommonTask.h"
#include <vector>

template <class T>
class Castable {
    const int index;
    const std::vector<VirtualTask*>& list;
    
    public:
        
        Castable () = default;
        Castable ( const Castable& ) = default;
        
        Castable (int index, std::vector<VirtualTask*>& tasks) : index(index), list(tasks) {}
        
        Castable& operator=(const Castable& other) = default;
        
        operator const T& () const {
            return list[index]->k2.get<T>();
        }
};


