//
//  median_finder.cpp
//  median-finder
//
//  Copyright © 2016 Luigi Damato. All rights reserved.
//

#include "median_finder.hpp"
#include <iostream>

template<class T>
median_finder<T>::median_finder()
{
}

template<class T>
void median_finder<T>::add(const T& elem)
{
    if (elem || elem == 0)
    {
        if (size() < 2)
        {
            if (_left.empty()) _left.push(elem);
            else if (elem >= _left.top())
                _right.push(elem);
            else
            {
                _right.push(_left.top());
                _left.pop();
                _left.push(elem);
            }
            
//            _debug();
            
            return;
        }

        T smaller = _left.top();
        T bigger = _right.top();
        
        if (elem < smaller)
            _left.push(elem);
        else if (elem > bigger)
            _right.push(elem);
        else if (_left.size() < _right.size())
            _left.push(elem);
        else _right.push(elem);
        
        if (_left.size() > _right.size())
        {
            _right.push(_left.top());
            _left.pop();
        }
        else if (_right.size() > _left.size())
        {
            _left.push(_right.top());
            _right.pop();
        }
    }
    
//    _debug();
}

template<class T>
double median_finder<T>::get()
{
    if (_left.size() > _right.size())
        return _left.top();
    if (_right.size() > _left.size())
        return _right.top();
    
    T t1 = _left.top(),
      t2 = _right.top();
    
    return (t1 + t2) / 2.0;
}

template<class T>
size_t median_finder<T>::size()
{
    return _left.size() + _right.size();
}

template<class T>
void median_finder<T>::_debug()
{
    std::queue<T> q_left;
    std::queue<T> q_right;

    while (!_left.empty())
    {
        q_left.push(_left.top());
        _left.pop();
    }
    
    while (!_right.empty())
    {
        q_right.push(_right.top());
        _right.pop();
    }
    
    std::cout << std::endl << "LEFT QUEUE" << std::endl;
    while (!q_left.empty())
    {
        std::cout << q_left.front() << std::endl;
        _left.push(q_left.front());
        q_left.pop();
        
    }
    
    std::cout << std::endl << "RIGHT QUEUE" << std::endl;
    while (!q_right.empty())
    {
        std::cout << q_right.front() << std::endl;
        _right.push(q_right.front());
        q_right.pop();
        
    }
    
}

template class median_finder<int>;
template class median_finder<float>;
template class median_finder<double>;
template class median_finder<unsigned>;
template class median_finder<long>;
