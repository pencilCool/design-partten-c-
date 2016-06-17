//
//  main.cpp
//  Command2
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Receiver{
public:
    void action(){
        cout<<"execute the request"<<endl;
    }
};

class Command{
protected:
    Receiver *receiver;
public:
    Command(Receiver *receiver){
        this->receiver = receiver;
    }
    virtual void execute() = 0;
};

class ConcreteCommand:public Command{
public:
    ConcreteCommand(Receiver *receiver):Command(receiver){}
    void execute(){
        receiver->action();
    }
};

class Invoker{
private:
    Command *command;
public:
    void setCommand(Command *command){
        this->command = command;
    }
    void  executeCommand(){
        command->execute();
    }
};

int main(int argc, const char * argv[]) {
    Receiver *r = new Receiver();
    Command *c = new ConcreteCommand(r);
    Invoker *i = new Invoker();
    i->setCommand(c);
    i->executeCommand();
    return 0;
}
