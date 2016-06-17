//
//  main.cpp
//  Facade
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Sub1{
public:
    void f1(){
        cout<<"sub systerm 1"<<endl;
    }
};

class Sub2{
public:
    void f2(){
        cout<<"sub systerm 2"<<endl;
    }
};


class Sub3{
public:
    void f3(){
        cout<<"sub systerm 3"<<endl;
    }
};


class Sub4{
public:
    void f4(){
        cout<<"sub systerm 4"<<endl;
    }
};

class Facade{
private:
    Sub1 *s1;
    Sub2 *s2;
    Sub3 *s3;
    Sub4 *s4;
    
public:
    Facade(){
        s1 = new Sub1();
        s2 = new Sub2();
        s3 = new Sub3();
        s4 = new Sub4();
    }
    
    void method(){
        s1->f1();
        s2->f2();
        s3->f3();
        s4->f4();
    }
};






int main(int argc, const char * argv[]) {
    Facade *f = new Facade();
    f->method();
    return 0;
}
