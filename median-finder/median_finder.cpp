//
//  median_finder.cpp
//  median-finder
//
//  Copyright © 2016 Luigi Damato. All rights reserved.
//

#include "median_finder.hpp"

template<class T>
median_finder<T>::median_finder(const T& first)
{
    if (first != NULL)
    {
        _left.push(first);
    }
}

template<class T>
void median_finder<T>::add(const T& elem)
{
    if (elem != NULL)
    {
        T smaller = _left.top();
        T bigger = _right.top();
        
        if (elem < smaller)
            _left.push(elem);
        else _right.push(elem);

        if (_left.size() - _right.size() > 1)
        {
            _right.push(_left.top());
            _left.pop();
        } else if (_right.size() - _left.size() > 1)
        {
            _left.push(_right.top());
            _right.pop();
        }
    }
}

template<class T>
T median_finder<T>::get()
{
    if (_left.size() > _right.size())
        return _left.top();
    if (_right.size() > _left.size())
        return _right.top();
    
    T t1 = _left.top(),
      t2 = _right.top();
    
    return (t1 + t2) / 2;
}

template<class T>
size_t median_finder<T>::size()
{
    return _left.size() + _right.size();
}
