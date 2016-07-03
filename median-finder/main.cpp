//
//  main.cpp
//  median-finder
//
//  Created by Luigi Damato 2 on 7/3/16.
//  Copyright © 2016 Luigi Damato 2. All rights reserved.
//

#include "median_finder.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    int arr[] = {1,5,3,7,1,0,9,8,5,2,3};
    median_finder<int> mf;
    
    for (int i : arr)
    {
        mf.add(i);
        std::cout << "Current median is: " << mf.get() << std::endl;
    }
    
    return 0;
}
