//
//  main.cpp
//  Prototype3
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Resume{
private:
    string name,sex,age,timeArea,company;
public:
    Resume(string s){
        name = s;
    }
    void setPersonalInfo(string s, string a){
        sex = s;
        age = a;
    }
    void setWorkExperience(string t,string c){
        timeArea = t;
        company = c;
    }
    void display(){
        cout<<name<<" "<<sex<<" "<<age<<endl;
        cout<<"work experience :"<<timeArea<<" "<<company<<endl;
    }
    
    Resume *clone(){
        Resume *b;
        b = new Resume(name);
        b->setPersonalInfo(sex, age);
        b->setWorkExperience(timeArea, company);
        return  b;
    }
};


int main(int argc, const char * argv[]) {
    
    Resume *r = new Resume("li jun hong");
    r->setPersonalInfo("man", "26");
    r->setWorkExperience("2007-2010", "master");
    r->display();
    
    Resume *r2 = r->clone();
    r2->setWorkExperience("2003", "colleage");
    r->display();
    r2->display();
    
    return 0;
}
