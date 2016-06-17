//
//  main.cpp
//  Flyweight2
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;


class WebSite{
public:
    virtual void use() = 0;
};

class ConcreteWebSite: public WebSite{
private:
    string name;
public:
    ConcreteWebSite(string name){
        this->name = name;
    }
    void use(){
        cout<<"Web site classification "<<name<<endl;
    }
};

class WebSiteFactory{
private:
    map<string,WebSite *> wf;
public:
    WebSite *getWebSiteCategory(string key){
        if(wf.find(key) == wf.end()){
            wf[key] = new ConcreteWebSite(key);
        }
        return wf[key];
    }
    
    int getWebSiteCount(){
        return wf.size();
    }
};



int main(int argc, const char * argv[]) {
    WebSiteFactory *wf = new WebSiteFactory();
    WebSite *fx = wf->getWebSiteCategory("good");
    fx->use();
    
    WebSite *fy = wf->getWebSiteCategory("product display");
    fy->use();
    
    WebSite *fz = wf->getWebSiteCategory("product display");
    fz->use();
    
    WebSite *f1 = wf->getWebSiteCategory("blog");
    f1->use();
    
    
    WebSite *f2 = wf->getWebSiteCategory("blog");
    fz->use();
    
    cout<<wf->getWebSiteCount()<<endl;
    
    return 0;
}
