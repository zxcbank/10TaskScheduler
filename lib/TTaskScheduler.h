//
// Created by Святослав on 24.04.2024.
//

#pragma once

#include "Object.h"
#include "task.h"
#include <vector>
#include <stack>
#include "Castable.h"

bool mama() {
    return true;
}

class TTaskScheduler {
    private:
        std::vector<VirtualTask*> tasks;
        std::vector<std::vector<size_t>> graph; //depends on
        std::vector<size_t> order; //
    public:
        TTaskScheduler() = default;
        ~TTaskScheduler() = default;
        
        template<class T>
        Castable<T> getFutureResult(int id_) {
            
            if (graph.size () <= id_) {
                graph.resize(id_ + 1);
            }
            graph.resize(graph.size() + 1);
            
            graph[graph.size() - 1].push_back(id_);
            return Castable<T>(id_, tasks);
        }
        
        void dfs(int v0) {
            int sz = (graph.size() == 0) ? 0 : graph[v0].size();
            for (int i = 0; i < sz; ++i) {
                int v = graph[v0][i];
                order.push_back(v);
                dfs(v);
            }
        }
        
        template<class F>
        [[maybe_unused]] int add (F func) {
            tasks.push_back(new ArgTask1<F>(func));
            return tasks.size() - 1;
        }

        template<class F, class T>
        [[maybe_unused]] int add (F func, T t1) {
            
            tasks.push_back(new ArgTask2<F, T>(func, t1));
            return tasks.size() - 1;
        }
        
        template<class F, class T, class K>
        [[maybe_unused]] int add (F func, T t1, K k1) {
            tasks.push_back(new ArgTask3<F, T, K>(func, t1, k1));
            return tasks.size() - 1;
        }
        
        void executeAll() {
            for (size_t i = 0; i < tasks.size(); ++i) {
                tasks[i]->execute();
                tasks[i]->is_calculated = true;
            }
        }
        
        template<class T>
        T getResult(int id) {
            if (!tasks[id]->is_calculated) {
                dfs(id);
                for (int i = order.size() - 1; i >= 0; --i) {
                    tasks[order[i]]->execute();
                    tasks[order[i]]->is_calculated = true;
                }
                tasks[id]->execute();
                tasks[id]->is_calculated = true;
            }
            order.clear();
            return tasks[id]->k2.get<T>();
        }
        
};