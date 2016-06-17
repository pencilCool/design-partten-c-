//
//  main.cpp
//  Interpret
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Context;

class AbstractExpression{
public:
    virtual void interpret(Context *) = 0;
};

class TerminalExpression:public AbstractExpression{
public:
    void interpret(Context *context){
        cout<<"terminal interpret"<<endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
