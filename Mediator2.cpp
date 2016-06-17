//
//  main.cpp
//  Mediator2
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Country;

class UniteNations{
public:
    virtual void declare(string message,Country *colleague) = 0;
};

class Country{
protected:
    UniteNations *mediator;
public:
    Country(UniteNations *mediator){
        this->mediator = mediator;
    }
};

class USA:public Country {
public:
    USA(UniteNations *mediator):Country(mediator){};
    void declare(string message){
        mediator->declare(message, this);
    }
    
    void getMessage(string message){
        cout<<"USA get the message!"<<message<<endl;
    }
};

class Iraq:public Country{
public:
    Iraq(UniteNations *mediator):Country(mediator){}
    void declare(string message){
        mediator->declare(message, this);
    }
    void getMessage(string message){
        cout<<"Iraq get the message"<<message<<endl;
    }
};

class UnitedNationsSecurityCouncil:public UniteNations{
public:
    USA *usa;
    Iraq *iraq;
    void declare(string message, Country *colleague){
        if (colleague ==usa) {
            iraq->getMessage(message);
        }else{
            usa->getMessage(message);
        }
        
    }
};

int main(int argc, const char * argv[]) {
    UnitedNationsSecurityCouncil *unsc =new UnitedNationsSecurityCouncil();
    USA *c1 =new USA(unsc);
    Iraq *c2 =new Iraq(unsc);
    
    unsc->usa   = c1;
    unsc->iraq = c2;
    c1->getMessage("do not allowed research the nuclear weapon,or you will be attacked");
    c2->declare("go to hell USA");
    return 0;
}
