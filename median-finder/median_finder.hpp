//
//  median_finder.hpp
//  median-finder
//
//  Copyright © 2016 Luigi Damato. All rights reserved.
//

#ifndef median_finder_hpp
#define median_finder_hpp

#include <queue>
#include <vector>
#include <functional>

template<class T>
class median_finder {
    
private:
    std::priority_queue<T, std::vector<T>, std::less<T>>    _left;
    std::priority_queue<T, std::vector<T>, std::greater<T>> _right;

    void _push(const T& elem);
    bool _is_balanced();
    void _balance();
    void _debug();

public:
    median_finder();
    void add(const T& elem);
    double get();
    size_t size();
};

#endif /* median_finder_hpp */
