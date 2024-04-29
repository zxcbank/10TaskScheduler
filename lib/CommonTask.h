//
// Created by Святослав on 29.04.2024.
//

#include "Object.h"
#pragma once

class VirtualTask {
    public:
        virtual ~VirtualTask() = default;
        virtual void execute() = 0;
        bool is_calculated =  false;
        bool calculatable = false;
        Object k2;
};