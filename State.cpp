//
//  main.cpp
//  State
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Work;
class State;
class ForenonnSate;

class State{
public:
    virtual void writeProgram(Work *) = 0;
};

class Work{
public:
    int hour;
    State *current;
    Work();
    void writeProgram(){
        current->writeProgram(this);
    }
};

class EveningState:public State{
public:
    void writeProgram(Work *w){
        cout<<" current time: "<<w->hour<<" feel good ! "<<endl;
    }
};

class AfternoonState:public State{
public:
    void writeProgram(Work *w){
        if (w->hour<19) {
            cout<<" current time: "<<w->hour<<" after an afternoon nap ,work with high efficiency "<<endl;
        }else{
            w->current = new EveningState();
            w->writeProgram();
        }
    }
    
};

class ForenonnSate:public State{
public:
    void writeProgram(Work *w){
        if (w->hour<12) {
            cout<<" current time "<<w->hour<<" morning feel good "<<endl;
        }else{
            w->current = new AfternoonState();
            w->writeProgram();
        }
    }
};

Work::Work(){
    current =new ForenonnSate();
}



int main(int argc, const char * argv[]) {
    Work *w = new Work();
    w->hour = 12;
    w->writeProgram();
    return 0;
}
