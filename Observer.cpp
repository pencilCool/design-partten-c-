//
//  main.cpp
//  Observer
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;

class Observer{
protected:
    string name;
    Subject *sub;
public:
    Observer(string name,Subject *sub){
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};

class StockObserver: public Observer {
public:
    StockObserver(string name,Subject *sub):Observer(name,sub){}
    void update();
};

class NBAObserver: public Observer{
public:
    NBAObserver(string name,Subject *sub):Observer(name,sub){}
    void update();
};

class Subject{
protected:
    list<Observer *> observers;
public:
    string action;
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class Secretary: public Subject{
    void attach (Observer *observer){
        observers.push_back(observer);
    }
    void detach(Observer *observer){
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end()){
            if ((*iter) == observer) {
                observers.erase(iter);
            }
            ++ iter;
        }
    }
    void notify(){
        list<Observer *>::iterator iter = observers.begin();
        while (iter!= observers.end()) {
            (*iter)->update();
            iter++;
        }
    }
};

void StockObserver::update(){
    cout<<name<<" recevie the message "<<sub->action<<endl;
    if (sub->action =="boss is comming") {
        cout<<" close the stock windows "<<endl;
    }
}

void  NBAObserver::update(){
    cout<<name<<" recevie the message "<<sub->action<<endl;
    if (sub->action == "boss is comming") {
        cout<<" close the nba on live "<<endl;
    }
}



int main(int argc, const char * argv[]) {
    Subject *dwq = new Secretary();
    Observer *xs = new NBAObserver("xiaoshuai",dwq);
    Observer *zy = new NBAObserver("zouyue",dwq);
    Observer *lm = new StockObserver("limin",dwq);
    
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);
    
    dwq->action = "go to eat!";
    dwq->notify();
  
    cout<<endl;
    
    dwq->action= "boss is comming";
    dwq->notify();
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
