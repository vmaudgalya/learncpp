//
//  Evaluator.cpp
//  Evaluator
//
//  Created by Maudgalya, Varun on 4/17/16.
//  Copyright © 2016 Maudgalya, Varun. All rights reserved.
//

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "Evaluator.hpp"


using namespace std;

Evaluator::Evaluator(string filename) {
    this->filename = filename;
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void printVector(vector<string> tokens) {
    for (auto i = tokens.begin(); i != tokens.end(); ++i) {
        cout << *i << " ";
    }
}

// trim from start
static inline string &ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline string &rtrim(string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline string &trim(string &s) {
    return ltrim(rtrim(s));
}

void Evaluator::processFile() {
    map <string, vector<string>> lhsToRhs;
    map <string, int> variableValues;
    string line;
    ifstream myfile;
    myfile.open(filename);
    
    if(!myfile.is_open()) {
        cout << "Failure to open file!" << endl;
        exit(EXIT_FAILURE);
    }
    
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            vector<string> splitLine = split(line, '=');
            vector<string> rhs = split(splitLine[1], '+');
            vector<string>::iterator rhsit = rhs.begin();
            for (rhsit=rhs.begin();rhsit!=rhs.end();++rhsit) {
                trim(*rhsit);
            }
            lhsToRhs.insert(pair<string, vector<string>>(trim(splitLine[0]), rhs));
        }
        myfile.close();
    }
    
    int currentValue = 0;
    int rules = lhsToRhs.size();
    while (variableValues.size() < rules) {
        map<string, vector<string>>::iterator it = lhsToRhs.begin();
        for (it=lhsToRhs.begin(); it!= lhsToRhs.end(); ++it) {
            if (variableValues.count(it->first) == 1) {
                continue; // if its already there, skip it
            }
            int number = 0;
            bool error = false;
            vector<string>::iterator vit;
            for(vit=it->second.begin(); vit!=it->second.end(); ++vit){
                try {
                    currentValue = stoi(*vit); // attempt to parse the number and add it to number
                    number += currentValue;
                } catch (invalid_argument& e) { // this means its a variable
                    map<string, int>::iterator pos = variableValues.find(*vit);
                    if (pos == variableValues.end()) {
                        error = true;
                        break; // it wasn't processed yet
                    } else {
                        number += pos->second;
                    }
                }
            }
            if (!error) {
                variableValues.insert(pair<string, int>(it->first, number));
            }
        }
    }
    
    map<string, int>::iterator fit;
    for (fit=variableValues.begin(); fit!=variableValues.end(); ++fit){
        cout << fit->first << " = " << fit->second << endl;
    }
    
}