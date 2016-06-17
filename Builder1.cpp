//
//  main.cpp
//  Builder1
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
public:
    virtual void createHead() = 0;
    virtual void createHand() = 0;
    virtual void createBody() = 0;
    virtual void createFoot() = 0;
};

class ThinPerson:public Person {
    virtual void createHead() {
        cout<<"Thin head"<<endl;
    }
    virtual void createHand(){
        cout<<"Thin Hand"<<endl;
    }
    virtual void createBody(){
        cout<<"Thin body"<<endl;
    }
    virtual void createFoot(){
        cout<<"Thin foot"<<endl;
    }
};

class FatPerson: public Person {
    
    virtual void createHead() {
        cout<<"fat head"<<endl;
    }
    virtual void createHand(){
        cout<<"fat Hand"<<endl;
    }
    virtual void createBody(){
        cout<<"fat body"<<endl;
    }
    virtual void createFoot(){
        cout<<"fat foot"<<endl;
    }
};

class Director {
private:
    Person *p;
public:
    Director(Person *temp){
        p = temp;
    }
    void create(){
        p->createHand();
        p->createBody();
        p->createHead();
        p->createFoot();
    }
};

int main(int argc, const char * argv[]) {
    Person *p = new FatPerson();
    Director *d = new Director(p);
    d->create();
    delete d;
    delete p;
    return 0;
}
