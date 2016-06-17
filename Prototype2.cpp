//
//  main.cpp
//  Prototype2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Prototype{
private:
    string str;
public:
    Prototype(string s){
        str = s;
    }
    Prototype(){
        str = " ";
    }
    void show(){
        cout<<str<<endl;
    }
    virtual Prototype *clone() = 0;
    
};

class ConcretePrototype1: public Prototype{
public:
    ConcretePrototype1(){};
    ConcretePrototype1(string s):Prototype(s){};
    virtual Prototype *clone(){
        ConcretePrototype1 *p = new ConcretePrototype1();
        *p = *this;
        return p;
    }
};

class ConcretePrototype2: public Prototype {
public:
    ConcretePrototype2(string str):Prototype(str){}
    ConcretePrototype2(){};
    virtual Prototype *clone(){
        ConcretePrototype2 *p = new ConcretePrototype2();
        *p = *this;
        return p;
    }
    
};




int main(int argc, const char * argv[]) {
    ConcretePrototype1 *test1 = new ConcretePrototype1("xiao wang");
    ConcretePrototype2 *test2 = (ConcretePrototype2 *)test1->clone();
    test1->show();
    test2->show();
    return 0;
}
