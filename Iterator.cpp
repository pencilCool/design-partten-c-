//
//  main.cpp
//  Iterator
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Iterator;

class Aggregate{
public:
    virtual Iterator *createIterator() = 0;
};

class Iterator{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
};

class ConcreteAggregate:public Iterator{
public:
    virtual void first(){
    }
    virtual void next(){
    
    }
    virtual bool isDone(){
        return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
