//
// Created by Святослав on 24.04.2024.
//

#pragma once
#include <memory>

class Object {
    
    class Base {
        public:
            virtual ~Base() = default;
            
    };
    
    template<class T>
    class Derived: public Base {
        public:
            T value;
            
            Derived(const T& arg) : value(arg) {}
            
            Derived& operator=(const T& arg) {
                value = arg;
                return *this;
            }
        };
    
    public:
        template <class T>
        Object(const T& arg) : pb(std::make_unique<Derived<T>>(arg)) {};
        
        Object() = default;
        
        template <class T>
        Object& operator=(const T& arg) {
            pb.reset(new Derived<T>(arg));
            return *this;
        }
        
        template <class T>
        const T& get() {
            return dynamic_cast<Derived<T>*>(pb.get())->value;
        }
        
        ~Object() = default;
        bool isReady = false;
    private:
        std::unique_ptr<Base> pb;
};