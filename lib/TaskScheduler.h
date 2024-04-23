//
// Created by Святослав on 22.04.2024.
//


#pragma once

#include <iostream>
#include <vector>

class vertex {
    public:
        vertex() = default;
        bool is_calculated = false;
        
        virtual ~vertex() = default;
};

template <class T0>
    class vertex1 : public vertex {
        public:
            T0 param0;
            
            explicit vertex1(T0 param0__) : param0(param0__) {};
        
    };

template <class T0, class T1>
    class vertex2 : public vertex {
        public:
            T0 param0;
            T1 param1;
            
            explicit vertex2(T0 param0__, T1 param1__) : param0(param0__), param1(param1__) {};
    };

template <class T0, class T1, class T2>
    class vertex3 : public vertex {
        public:
            T0 param0;
            T1 param1;
            T2 param2;
            
            explicit vertex3(T0 param0__, T1 param1__, T2 param2__) : param0(param0__), param1(param1__), param2(param2__) {};
    };

class TTaskScheduler {
    public:
        std::vector<vertex*> tasks;
        
        TTaskScheduler() = default;
        
        template<class T0>
        vertex* add(T0 param0) {
            vertex1<T0>* newTask = new vertex1(param0);
            tasks.push_back(static_cast<vertex*>(newTask));
            return static_cast<vertex*>(newTask);
        }
        
        template<class T0, class T1>
        vertex* add(T0 param0, T1 param1) {
            vertex2<T0, T1>* newTask = new vertex2(param0, param1);
            tasks.push_back(static_cast<vertex*>(newTask));
            return static_cast<vertex*>(newTask);
        }
        
        template<class T0, class T1, class T2>
        vertex* add(T0 param0, T1 param1, T2 param2) {
            vertex3<T0, T1, T2>* newTask = new vertex3(param0, param1, param2);
            tasks.push_back(static_cast<vertex*>(newTask));
            return static_cast<vertex*>(newTask);
        }
        
        void executeAll() {
        
        }
        template <class A>
        void* getFutureResult(vertex* j) {
        
        }
        
        template <class A>
        void* getResult(vertex* j) {
        
        }
        
        ~TTaskScheduler() = default;
};

bool mama() {
    
    return true;
}


