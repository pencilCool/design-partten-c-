//
//  main.cpp
//  Bridge
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class HandsetSoft{
public:
    virtual void run() = 0;
};

class HandsetGame: public HandsetSoft{
public:
    void run(){
        cout<<"run the phone game"<<endl;
    }
};

class HandsetAddressList: public HandsetSoft{
public:
    void run(){
        cout<<"run the phone address List"<<endl;
    }
};

class HandsetBrand{
protected:
    HandsetSoft *soft;
public:
    void setHandsetSoft(HandsetSoft *soft){
        this->soft = soft;
    }
    virtual void run()=0;
};

class HandsetBrandN :public HandsetBrand{
public:
    void run(){
        soft->run();
    }
};

class HandsetBrandM :public HandsetBrand {
public:
    void run(){
        soft->run();
    }
};


int main(int argc, const char * argv[]) {
    HandsetBrand *hb;
    hb = new HandsetBrandM();
    
    hb->setHandsetSoft(new HandsetGame());
    hb->run();
    
    hb->setHandsetSoft(new HandsetAddressList());
    hb->run();
    
    
    
    return 0;
}
