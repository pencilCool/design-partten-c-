//
//  main.cpp
//  Composite
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Component{
public:
    string name;
    Component(string name){
        this->name = name;
    }
    virtual void add(Component *) = 0;
    virtual void remove(Component *) = 0;
    virtual void display(int ) = 0;
};

class Leaf:public Component{
public:
    Leaf(string name):Component(name){}
    void add(Component *c){
        cout<<"leaf cannot add"<<endl;
    }
    
    void remove(Component *c) {
        cout<<"leaf cannot remove"<<endl;
    }
    void display(int depth){
        string str(depth,'-');
        str += name;
        cout<<str<<endl;
    }
};

class Composite:public Component{
private:
    vector<Component*> component;
public:
    Composite(string name):Component(name){}
    void add(Component *c){
        component.push_back(c);
    }
    void remove(Component *c){
        vector<Component *>::iterator iter = component.begin();
        while (iter!= component.end()){
            if (*iter ==c) {
                component.erase(iter);
            }
            iter++;
        }
    }
    void display(int depth){
        string str(depth,'-');
        str += name;
        cout<<str<<endl;
        vector<Component *>::iterator iter = component.begin();
        while (iter != component.end()){
            (*iter)->display(depth+2);
            iter++;
        }
    
    }
};


int main(int argc, const char * argv[]) {
   // Composite *p = //
   Component *p = new Composite("xiaoli");
    p->add(new Leaf("xiao wang"));
    p->add(new Leaf("xiao qing"));
    
    Component *sub = new Composite("xiao hu");
    
    sub->add(new Leaf("xiao wang"));
    sub->add(new Leaf("xiao ming"));
    sub->add(new Leaf("xiao liu"));
    
    p->add(sub);
    p->display(0);
    cout<<"-------------"<<endl;
    sub->display(2);
    
    
    
    return 0;
}
