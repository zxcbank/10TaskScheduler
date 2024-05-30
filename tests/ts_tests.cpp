//
// Created by Святослав on 22.04.2024.
//

//#include <valarray>
#include <valarray>
#include "lib/TTaskScheduler.h"

#include "gtest/gtest.h"

TEST(TaskScheduler11, mamaTest) {
    bool a = mama();
    ASSERT_TRUE(a);
}

TEST(TaskScheduler, test1) {
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
    
    scheduler.executeAll();
    

    ASSERT_EQ(scheduler.getResult<float>(id5), 2);
    ASSERT_EQ(scheduler.getResult<float>(id6), 0);
}

TEST(TaskScheduler, SLE) {
    TTaskScheduler scheduler;
    std::function<int(int, int , int, int)> det = [&scheduler](int a1, int a2, int b1, int b2)-> int {
        int x1, x2;
        
        auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
        auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
        auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
        
        scheduler.executeAll();
        return scheduler.getResult<int>(det);
    } ;
    
    int a1 = 2, b1 = 4;
    int a2 = 0, b2 = 9;
    
    
    int f1 = 30, f2 = 239;
    
    auto d = det(a1, a2, b1, b2);
    auto x = det(f1, f2, b1, b2) / float(d);
    auto y = det(a1, a2, f1, f2) / float(d);
    
    ASSERT_FLOAT_EQ(x, -38.1111);
    ASSERT_FLOAT_EQ(y, 26.555555);
}

TEST(TaskScheduler, SLE2) {
    TTaskScheduler scheduler;
    std::function<int(int, int , int, int)> det = [&scheduler](int a1, int a2, int b1, int b2)-> int {
        int x1, x2;
        
        auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
        auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
        auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
        
        scheduler.executeAll();
        return scheduler.getResult<int>(det);
    } ;
    
    int a1 = 4, b1 = 5;
    int a2 = 2, b2 = 3;
    
    
    int f1 = 9, f2 = 5;
    
    auto d = det(a1, a2, b1, b2);
    auto x = det(f1, f2, b1, b2) / float(d);
    auto y = det(a1, a2, f1, f2) / float(d);
    
    ASSERT_FLOAT_EQ(x, 1);
    ASSERT_FLOAT_EQ(y, 1);
}

TEST(TaskScheduler, SLE3) {
    TTaskScheduler scheduler;
    std::function<int(int, int , int, int)> det = [&scheduler](int a1, int a2, int b1, int b2)-> int {
        int x1, x2;
        
        auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
        auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
        auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
        
        scheduler.executeAll();
        return scheduler.getResult<int>(det);
    } ;
    
    int a1 = 40, b1 = 5;
    int a2 = 2, b2 = 30;
    
    
    int f1 = 91, f2 = 54;
    
    auto d = det(a1, a2, b1, b2);
    auto x = det(f1, f2, b1, b2) / float(d);
    auto y = det(a1, a2, f1, f2) / float(d);
    
    ASSERT_FLOAT_EQ(x, 2.0672269);
    ASSERT_FLOAT_EQ(y, 1.6621848);
}

TEST(TaskScheduler, SLE4) {
    TTaskScheduler scheduler;
    std::function<int(int, int , int, int)> det = [&scheduler](int a1, int a2, int b1, int b2)-> int {
        int x1, x2;
        
        auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
        auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
        auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
        
        scheduler.executeAll();
        return scheduler.getResult<int>(det);
    } ;
    
    int a1 = 4456450, b1 = 5355465;
    int a2 = 2324, b2 = 305465;
    
    
    int f1 = 956756751, f2 = 557567674;
    
    auto d = det(a1, a2, b1, b2);
    auto x = det(f1, f2, b1, b2) / float(d);
    auto y = det(a1, a2, f1, f2) / float(d);
    
    ASSERT_FLOAT_EQ(x, -3.3265731);
    ASSERT_FLOAT_EQ(y, 9.0600729);
}

TEST(TaskScheduler, SLE5) {
    TTaskScheduler scheduler;
    std::function<int(int, int , int, int)> det = [&scheduler](int a1, int a2, int b1, int b2)-> int {
        int x1, x2;
        
        auto det1 = scheduler.add([](int a1, int b2){return a1 * b2;}, a1, b2);
        auto det2 = scheduler.add([](int a2, int b1){return a2 * b1;}, a2, b1);
        auto det = scheduler.add([](int x1, int y1){return x1 - y1;}, scheduler.getFutureResult<int>(det1), scheduler.getFutureResult<int>(det2));
        
        scheduler.executeAll();
        return scheduler.getResult<int>(det);
    } ;
    
    int a1 = 44550, b1 = 53465;
    int a2 = 24, b2 = 3065;
    
    
    int f1 = 9566751, f2 = 557674;
    
    auto d = det(a1, a2, b1, b2);
    auto x = det(f1, f2, b1, b2) / float(d);
    auto y = det(a1, a2, f1, f2) / float(d);
    
    ASSERT_FLOAT_EQ(x, -3.6517754);
    ASSERT_FLOAT_EQ(y, -8.5391617);
}

TEST(TaskScheduler, getRes1) {
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
    
    scheduler.executeAll();
    
    
    ASSERT_EQ(scheduler.getResult<float>(id3), 4);
}

TEST(TaskScheduler, getRes2) {
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
    
    scheduler.executeAll();
    
    
    ASSERT_EQ(scheduler.getResult<float>(id1), 0);
}

TEST(TaskScheduler, getRes3) {
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
    
    ASSERT_EQ(scheduler.getResult<float>(id1), 0);
}

TEST(TaskScheduler1, test1) {
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
    
    scheduler.executeAll();
    
    ASSERT_EQ(scheduler.getResult<float>(id5), 2);
    ASSERT_EQ(scheduler.getResult<float>(id6), 0);
}

//gg