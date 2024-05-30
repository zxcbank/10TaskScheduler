//
// Created by Святослав on 22.04.2024.
//

#include <iostream>
#include <valarray>
#include "lib/TTaskScheduler.h"

int determinant(int a1, int a2, int b1, int b2) {
    TTaskScheduler scheduler;
    int x1, x2;
    
    auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
    auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
    auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
    
    scheduler.executeAll();
    return scheduler.getResult<int>(det);
}

int main() {
    float a = 1;
    float b = -2;
    float c = 0;
    
    TTaskScheduler scheduler;
    
    auto id1 = scheduler.add([](float a, float c){return -4 * a * c;}, a, c);
    
    auto id2 = scheduler.add([](float b, float v){return b * b + v;}, b, scheduler.getFutureResult<float>(id1));
    
    auto id3 = scheduler.add([](float b, float d){return -b + std::sqrt(d);}, b, scheduler.getFutureResult<float>(id2));
    
    auto id4 = scheduler.add([](float b, float d){return -b - std::sqrt(d);}, b, scheduler.getFutureResult<float>(id2));
    
    auto id5 = scheduler.add([](float a, float v){return v/(2*a);}, a, scheduler.getFutureResult<float>(id3));
    
    auto id6 = scheduler.add([](float a, float v){return v/(2*a);},a, scheduler.getFutureResult<float>(id4));
    
    ++id6;
    
    scheduler.executeAll();
    std::cout << scheduler.getResult<float>(id5) << ' ';
    std::cout << scheduler.getResult<int>(id6);
    
    return 0;
}