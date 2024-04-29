//
// Created by Святослав on 24.04.2024.
//

#pragma once
#include "Object.h"
#include "Castable.h"
#include "CommonTask.h"

struct taskID{
    int id;
};



template<class F>
class ArgTask1 : public VirtualTask {
    public:
        ~ArgTask1() = default;
        
        ArgTask1(F f) : functor(f) {
            calculatable = true;
        };
        
        void execute() {
            if (!k2.isReady) {
                k2 = (functor());
                k2.isReady = true;
            }
        }
        
    F functor;
};

template<class F, class T>
    
    class ArgTask2 : public VirtualTask {
        public:
            F functor;
            T t1;
            ~ArgTask2() = default;
            
            ArgTask2(F f, T t1_) : functor(f), t1(t1_) {};
            
            void execute() {
                if (!k2.isReady) {
                    
                    k2 = (functor(t1));
                    k2.isReady = true;
                    
                }
            }
        
        
};

template<class F, class T, class K>
    class ArgTask3 : public VirtualTask {
        public:
            ~ArgTask3() = default;
            
            ArgTask3(F f, T t1_, K k1_) : functor(f), t1(t1_), k1(k1_) {};
            
            void execute() {
                if (!k2.isReady) {
                    k2 = functor(t1, k1);
                    k2.isReady = true;
                }
                
            }
        bool calculatable = false;
        F functor;
        T t1;
        K k1;
};