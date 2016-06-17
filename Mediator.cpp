//
//  main.cpp
//  Mediator
//
//  Created by Tang yuhua on 16/6/15.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

class Mediator;
class ConcreteColleaue1;
class ConcreteColleaue2;

class Colleague{
protected:
    Mediator *mediator;
public:
    Colleague(Mediator *mediator){
        this->mediator = mediator;
    }
};

class ConcreteColleaue1:public Colleague {
    public :
    ConcreteColleaue1(Mediator *mediator):Colleague(mediator){}
    void send(string message);
    void notify(string message){
        cout<<"同事1得到消息:" <<message<<endl;
    }
};

class ConcreteColleaue2:public Colleague {
    public :
    ConcreteColleaue2(Mediator *mediator):Colleague(mediator){}
    void send(string message);
    void notify(string message){
        cout<<"同事2得到消息:" <<message<<endl;
    }
};

class Mediator {
public:
    virtual void send(string name, Colleague *colleague) = 0;
};

class ConcreteMediator:public Mediator {
public:
    ConcreteColleaue1 *colleague1;
    ConcreteColleaue2 *colleague2;
public:
    void send(string message, Colleague *colleague){
        if (colleague == colleague1) {
            colleague2->notify(message);
        }else{
            colleague1->notify(message);
        }
    }
};

void ConcreteColleaue1::send(string message){
    mediator->send(message, this);
}

void ConcreteColleaue2::send(string message){
    mediator->send(message, this);
}


int main(int argc, const char * argv[]) {
    ConcreteMediator *m = new ConcreteMediator();
    ConcreteColleaue1 *c1 = new ConcreteColleaue1(m);
    ConcreteColleaue2 *c2 = new ConcreteColleaue2(m);
    m->colleague1 = c1;
    m->colleague2 = c2;
    
    c1->send("吃放了");
    c2->send("去");
    
    
    
    
    
    return 0;
}
