//
//  main.cpp
//  Decorator
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    string m_strName;
public:
    Person(string strName){
        m_strName = strName;
    }
    Person(){}
    virtual void show(){
        cout<<"decorator is :"<<m_strName<<endl;
    }
};

class Finery:public Person {
protected:
    Person *m_componet;
public:
    void decorate(Person *componet){
        m_componet = componet;
    }
    virtual void show(){
        m_componet->show();
    }
};

class TShirts:public Finery{
public:
    virtual void show(){
        m_componet->show();
        cout<<"T shirt"<<endl;
    }
};

class BigTrouser:public Finery {
public:
    virtual void show()
    {
        m_componet->show();
        cout<<"Big Trouser"<<endl;
    }
};

class Bikini:public Finery {
public:
    virtual void show(){
        m_componet->show();
        cout<<"Bikini !!"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Person *p = new Person("xiao li");
    BigTrouser *bt = new BigTrouser();
    TShirts *ts = new TShirts();
    
    bt->decorate(p);
    bt->show();
    
    ts->decorate(bt);
    ts->show();
    
    Bikini *bi = new Bikini();
    bi->decorate(ts);
    bi->show();
    return 0;
}









