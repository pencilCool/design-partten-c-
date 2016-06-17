//
//  main.cpp
//  Memento
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Memo {
public:
    string state;
    Memo(string state){
        this->state = state;
    }
};

class Originator {
public:
    string state;
    void setMemo(Memo *memo){
        state = memo->state;
    }
    Memo *createMemo(){
        return new Memo(state);
    }
    void show(){
        cout<<state<<endl;
    }
};

class Caretaker{
public:
    vector<Memo * >memo;
    void save(Memo *memo){
        (this->memo).push_back(memo);
    }
    Memo *getState(int i){
        return memo[i];
    }
    
};

int main(int argc, const char * argv[]) {
    Originator *og = new Originator();
    Caretaker *ct = new Caretaker();
    og->state = "on";
    og->show();
    ct->save(og->createMemo());
    
    og->state = "off";
    og->show();
    ct->save(og->createMemo());
    
    og->state = "middle";
    og->show();
    ct->save(og->createMemo());
    
    og->setMemo(ct->getState(2));
    og->show();
    
    return 0;
}
