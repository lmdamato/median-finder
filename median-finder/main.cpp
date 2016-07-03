//
//  main.cpp
//  median-finder
//
//  Copyright © 2016 Luigi Damato. All rights reserved.
//

#include "median_finder.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int arr[] = {1,-2,5,3,7,1,0,-3,9,8,5,-12,2,3,9,9,9,9,9,9,9};
    median_finder<int> mf;
    
    for (int i : arr)
    {
        mf.add(i);
        cout << "Current median is: " << mf.get() << endl;
    }
    
    return 0;
}
