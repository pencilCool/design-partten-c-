//
//  main.cpp
//  Visitor1
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>

#include <list>
#include <string>
using namespace std;

class Person{
public:
    string action;
    virtual void getConclusion() = 0;
};

class Man:public Person {
public:
    void getConclusion(){
        if (action == "success") {
            cout<<"成功的男人背后，都有一个伟大的女人"<<endl;
        }
        if (action=="dating") {
            cout<<"男人在恋爱的过程中，凡事都要不懂装懂"<<endl;
        }
    }
};

class Woman:public Person {
public:
    void getConclusion(){
        if (action == "success") {
            cout<<"成功的女人背后，都有一个失败的男人"<<endl;
        }
        if (action=="dating") {
            cout<<"女人在恋爱的过程中，凡事都要懂也要装不懂"<<endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    list<Person *> persons;
    
    Person *man1 = new Man();
    man1->action = "success";
    persons.push_back(man1);
    
    Person *woman1 = new Woman();
    woman1->action = "success";
    persons.push_back(woman1);
    
    Person *man2 = new Man();
    man2->action = "dating";
    persons.push_back(man2);
    
    Person *woman2= new Woman();
    woman2->action = "dating";
    persons.push_back(woman2);
    
    list<Person *>::iterator iter = persons.begin();
    while (iter != persons.end()) {
        (*iter)->getConclusion();
        ++iter;
    }
    return 0;
}
