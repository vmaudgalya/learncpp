//
//  Evaluator.hpp
//  Evaluator
//
//  Created by Maudgalya, Varun on 4/17/16.
//  Copyright © 2016 Maudgalya, Varun. All rights reserved.
//

#ifndef Evaluator_hpp
#define Evaluator_hpp
#include <string>
#include <stdio.h>

using namespace std;

class Evaluator {
public:
    Evaluator(string);
    void processFile();
private:
    string filename;
};

#endif /* Evaluator_hpp */
