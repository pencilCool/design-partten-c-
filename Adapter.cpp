//
//  main.cpp
//  Adapter
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Adaptee{
public:
    virtual void myRequest(){
        cout<<"real interface"<<endl;
    }
};
        
class Target{
public:
    virtual void request() = 0;
    virtual ~Target(){
        cout<<"Target delete"<<endl;
    }
};

class Adapter: public Target{
private:
    Adaptee adaptee;
public:
    void request(){
        cout<<"Adapter send request"<<endl;
        adaptee.myRequest();
    }
};


int main(int argc, const char * argv[]) {
    Target *target = new Adapter();
    target->request();
    delete target;
    return 0;
}
