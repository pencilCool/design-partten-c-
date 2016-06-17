//
//  main.cpp
//  command1
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Barbecuer{
public:
    void bakeMutton(){
        cout<<"bake the mutton"<<endl;
    }
    void bakeChickenWing(){
        cout<<"bake the chickenwing"<<endl;
    }
};

class Command{
protected:
    Barbecuer *receiver;
public:
    Command(Barbecuer *receiver){
        this->receiver = receiver;
    }
    virtual void executeCommand() = 0;
};

class BakeMuttonCommand: public Command{
public:
    BakeMuttonCommand(Barbecuer *receiver):Command(receiver){}
    void executeCommand(){
        receiver->bakeMutton();
    }
};

class BakeChikenWingCommand: public Command{
public:
    BakeChikenWingCommand(Barbecuer * receiver):Command(receiver){}
    void executeCommand(){
        receiver->bakeChickenWing();
    }
};

class Waiter{
private:
    Command *command;
public:
    void setOrder(Command *command){
        this->command = command;
    }
    void notify(){
        command->executeCommand();
    }
    
};

class Waiter2{
private:
    list<Command *>order;
public:
    void setOrder(Command *command){
        order.push_back(command);
    }
    void cancelOrder(Command *command){}
    void notify(){
        list<Command *>::iterator iter = order.begin();
        while (iter != order.end()) {
            (*iter)->executeCommand();
            iter++;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Barbecuer *boy = new Barbecuer();
    Command *bm1 = new BakeMuttonCommand(boy);
    Command *bm2 = new BakeMuttonCommand(boy);
    Command *bm3 = new BakeChikenWingCommand(boy);
    
    Waiter2 *girl = new Waiter2();
    
    girl->setOrder(bm1);
    girl->setOrder(bm2);
    girl->setOrder(bm3);
    
    girl->notify();
    
    Waiter *litterGirl = new Waiter();
    litterGirl->setOrder(bm1);
    litterGirl->notify();
    
    return 0;
}
