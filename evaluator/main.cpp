//
//  main.cpp
//  Evaluator
//
//  Created by Maudgalya, Varun on 4/17/16.
//  Copyright © 2016 Maudgalya, Varun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Evaluator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    char filename[50];
    cin.getline(filename, 50);
    
    Evaluator e(filename);
    e.processFile();
    return 0;
}
