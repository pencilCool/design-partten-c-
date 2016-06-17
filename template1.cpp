//
//  main.cpp
//  template1
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class TestPaper{
public:
    void question1(){
        cout<<"1+1"<<answer1()<<endl;
    }
    void question2(){
        cout<<"1*1"<<answer2()<<endl;
    }
    
    virtual string answer1(){
        return "";
    }
    virtual string answer2(){
        return "";
    }
    virtual ~TestPaper(){
        cout<<" testpaper delete"<<endl;
    }
};

class TestPaperA:public TestPaper{
public:
    string answer1(){
        return  "2";
    }
    string answer2(){
        return  "1";
    }
};

class TestPaperB:public TestPaper{
public:
    string answer1(){
        return  "3";
    }
    string answer2(){
        return  "4";
    }
};



int main(int argc, const char * argv[]) {
    
    cout<<"A test paper"<<endl;
    TestPaper *s1 = new TestPaperA();
    s1->question1();
    s1->question2();
    delete s1;
    
    cout<<endl;
    
    
    cout<<"B test paper"<<endl;
    TestPaper *s2 = new TestPaperB();
    s2->question1();
    s2->question2();
    delete s2;
    
    
    
    
    
    
    
    
    return 0;
}
