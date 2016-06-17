//
//  main.cpp
//  Visitor2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Man;
class Woman;

class Action{
public:
    virtual void getManConclusion(Man *) = 0;
    virtual void getWomanConclusion(Woman *) = 0;
};

class Success:public Action{
    void getManConclusion(Man *){
        cout<<"男人的成功背后都有一个伟大的女人"<<endl;
    }
    void getWomanConclusion(Woman *){
        cout<<"女人的成狗的背后都有一个失败的男人"<<endl;
    }
};

class Love:public Action{
    void getManConclusion(Man *){
        cout<<"男人恋爱的时候，不懂也要装懂"<<endl;
    }
    void getWomanConclusion(Woman *){
        cout<<"女人恋爱的时候，懂也要装不懂"<<endl;
    }
};

class Person{
public:
    virtual void accept(Action *) = 0;
};

class Man :public Person{
public:
    void accept(Action * visitor){
        visitor->getManConclusion(this);
    }
};

class Woman :public Person{
public:
    void accept(Action * visitor){
        visitor->getWomanConclusion(this);
    }
};

class ObjectStructure{
private:
    list<Person *> elements;
public:
    void attach(Person *element){
        elements.push_back(element);
    }
    void detach(Person *element){
        for (list<Person *>::iterator iter = elements.begin();iter!= elements.end(); ++iter) {
            if ((*iter) == element) {
                elements.erase(iter);
            }
        }
    }
    void display(Action *visitor){
        for (list<Person *>::iterator iter = elements.begin();iter!= elements.end(); ++iter) {
            (*iter)->accept(visitor);
        }
    }
};


int main(int argc, const char * argv[]) {
    ObjectStructure *os = new ObjectStructure();
    Success *s = new Success();
    os->display(s);
    
    Love *lv = new Love();
    os->display(lv);
 
    return 0;
}
