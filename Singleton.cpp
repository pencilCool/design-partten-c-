//
//  main.cpp
//  Singleton
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Singleton{
private:
    int i;
    static Singleton *instance;
    Singleton(int i){
        this->i = i;
    }
public:
    static Singleton *getInstance(){
        return instance;
    }
    void show(){
        cout<<i<<endl;
    }
};

Singleton *Singleton::instance = new Singleton(8899);

class A:public Singleton{
};


int main(int argc, const char * argv[]) {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = A::getInstance();
    s1->show();
    s2->show();
    cout<<(s1==s2)<<endl;
    return 0;
}
