//
//  main.cpp
//  Delegate
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class SchoolGirl{
public:
    string name;
};

class IGiveGift{
public:
    virtual void giveDolls()=0;
    virtual void giveFlowers()=0;
};

class Pursuit:public IGiveGift{
private:
    SchoolGirl mm;
public:
    Pursuit(SchoolGirl m){
        mm = m;
    }
    void giveDolls(){
        cout<<mm.name<<" give you a doll"<<endl;
    }
    void giveFlowers(){
        cout<<mm.name<<" give you a flower"<<endl;
    }
};

class Proxy:public IGiveGift {
private:
    Pursuit gg;
public:
    Proxy(SchoolGirl mm):gg(mm){
        
    }
    void giveDolls(){
        gg.giveDolls();
    }
    
    void giveFlowers(){
        gg.giveFlowers();
    }
};

int main(int argc, const char * argv[]) {
    SchoolGirl lijiaojiao;
    lijiaojiao.name = "lijiaojiao";
    Pursuit zhaojiayi(lijiaojiao);
    Proxy delegate(lijiaojiao);
    delegate.giveDolls();
    return 0;
}
