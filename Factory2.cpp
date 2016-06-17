//
//  main.cpp
//  Factory2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class LeiFeng{
public:
    void sweep(){
        cout<<"sweep"<<" "<<endl;
    }
    void wash(){
        cout<<"wash"<<" "<<endl;
    }
};

class Student: public LeiFeng{
    
};

class Volunter: public LeiFeng{
    
};

class SimpleFactory{
public:
    static LeiFeng *createLeiFeng(string str){
        LeiFeng *lf;
        lf = NULL;
        if (str == "studeng") {
            lf = new Student();
        }
        if (str == "volunteer") {
            lf = new Volunter();
        }
        return lf;
    }
};

class IFactory{
public:
     LeiFeng *createLeiFeng();
};

class StuFactory:public IFactory{
    static LeiFeng *createLeiFeng(){
        return new Student();
    }
};

class VolFactory:public IFactory{
    static LeiFeng *createLeiFeng(){
        return new Volunter();
    }
};





int main(int argc, const char * argv[]) {
    
    
    
    
    
    
    return 0;
}
