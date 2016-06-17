//
//  main.cpp
//  Adapter2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Player{
public:
    string name;
    Player(string name){
        this->name = name;
    }
    virtual void attack() = 0;
    virtual void defence() = 0;
};

class Forwards: public Player {
public:
    Forwards(string name):Player(name){}
    void attack(){
        cout<<name<<" forwards attack"<<endl;
    }
    void defence(){
        cout<<name<<" forwards defence"<<endl;
    }
};

class Center:public Player{
public:
    Center(string name):Player(name){}
    void attack(){
        cout<<name<<" center attack"<<endl;
    }
    void defence(){
        cout<<name<<" center defence"<<endl;
    }
};


class Backward:public Player{
public:
    Backward(string name):Player(name){}
    void attack(){
        cout<<name<<" backward attack"<<endl;
    }
    void defence(){
        cout<<name<<" backward defence"<<endl;
    }
};

class ForeignCenter{
public:
    string name;
    ForeignCenter(string name){
        this->name = name;
    }
    void myAttack(){
        cout<<name<<" Foreign center attack"<<endl;
    }
    void myDefence(){
        cout<<name<<" Foreign backward defence"<<endl;
    }
};

class Translator:public Player{
private:
    ForeignCenter *fc;
public:
    Translator(string name):Player(name){
        fc = new ForeignCenter(name);
    }
    void attack(){
        fc->myAttack();
    }
    void defence(){
        fc->myDefence();
    }

};


int main(int argc, const char * argv[]) {
    Player *p1 = new Center("li jun hong");
    p1->attack();
    p1->defence();
    
    Translator *t1 = new Translator("yao ming");
    t1->attack();
    t1->defence();
    return 0;
}
