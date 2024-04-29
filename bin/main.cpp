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
    
    
    
    if (d != 0) {
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}