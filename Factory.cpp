//
//  main.cpp
//  Factory
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Operation{
public:
    double numberA,numberB;
    virtual double getResult(){
        return 0;
    }
};

class addOperation: public Operation{
    double getResult(){
        return numberA + numberB;
    }
};

class subOperation: public Operation{
    double getResult(){
        return numberA - numberB;
    }
};

class mulOperation: public Operation{
    double getResult(){
        return numberA * numberB;
    }
};
class divOperation: public Operation{
    double getResult(){
        return numberA / numberB;
    }
};

class AddFactory{
public:
    static Operation *createOperation(){
        return new addOperation();
    }
};

class SubFactory{
public:
    virtual Operation *createOperation(){
        return new subOperation();
    }
};

class MulFactory{
public:
    static Operation *createOperation(){
        return new mulOperation();
    }
};

class DivFactory{
public:
    static Operation *createOperation(){
        return new divOperation();
    }
};




int main(int argc, const char * argv[]) {
    Operation *oper = MulFactory::createOperation();
    oper->numberA = 9;
    oper->numberB = 99;
    cout<<oper->getResult()<<endl;
    return 0;
}
