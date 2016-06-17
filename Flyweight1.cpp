//
//  main.cpp
//  Flyweight1
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Flyweight{
public:
    virtual void operation(int) = 0;
};

class ConcreteFlyweight: public Flyweight {
    void operation(int extrinsicState){
        cout<<"flyweight instance"<<extrinsicState<<endl;
    }
};

class UnsharedConcreteFlyweigth: public Flyweight {
    void operation(int extrinsicState){
        cout<<"unshared flyweight instance"<<extrinsicState<<endl;
    }
};

class FlyweightFactory{
private:
    map<string,Flyweight*> flyweights;
public:
    FlyweightFactory()
    {
        flyweights["x"] = new ConcreteFlyweight();
        flyweights["y"] = new ConcreteFlyweight();
        flyweights["z"] = new ConcreteFlyweight();
    }
    Flyweight *getFlyweight(string key){
        return (Flyweight *)flyweights[key];
    }
};

int main(int argc, const char * argv[]) {
    int state = 22;
    FlyweightFactory *f = new FlyweightFactory();
    Flyweight *fx = f->getFlyweight("x");
    fx->operation(--state);
    
    Flyweight *fy = f->getFlyweight("y");
    fy->operation(--state);
    
    Flyweight *fz = f->getFlyweight("z");
    fz->operation(--state);

    return 0;
}
