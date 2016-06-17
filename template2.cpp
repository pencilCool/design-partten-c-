//
//  main.cpp
//  template2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractClass{
public:
    void show(){
        cout<< "I am "<<GetName()<<endl;
    }
protected:
    virtual string GetName() = 0;
};

class Naruto:public AbstractClass{
protected:
    virtual string GetName(){
        return "火影史上最帅的六代目    ";
    }
};

class OnePice: public AbstractClass {
protected:
    virtual string GetName(){
        return "我是无恶不作的路飞";
    }
};

int main(int argc, const char * argv[]) {
    Naruto *man = new Naruto();
    man->show();
    
    OnePice *man2 = new OnePice();
    man2->show();
    
    
    return 0;
}
