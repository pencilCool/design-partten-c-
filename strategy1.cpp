//
//  main.cpp
//  Strategy1
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CashSupper{
public:
    virtual double acceptMoney(double money) = 0;
};

class CashNormal: public CashSupper{
public:
    double acceptMoney(double money){
        return money;
    }
};

class CashRebat: public CashSupper{
private:
    double discount;
public:
    CashRebat(double dis){
        discount = dis;
    }
    double acceptMoney(double money){
        return money * discount;
    }
};

class CashReturn:public CashSupper{
private:
    double moneyCondition;
    double moneyReturn;
public:
    CashReturn(double mc ,double mr){
        moneyCondition = mc;
        moneyReturn = mr;
    }
    double acceptMoney(double money){
        double result = money;
        if (money>=moneyCondition) {
            result = money - floor(money/moneyCondition)*moneyReturn;
        }
        return result;
    }
};

class CashFactory{
public:
    static CashSupper * createCashAccept(string str){
        CashSupper *cs = NULL;
        if (str == "Normal") {
            return new CashNormal();
        }else if(str == "discount 90%"){
            return new CashRebat(0.9);
        }else if(str == "return 200 while over 300"){
            return new CashReturn(300,200);
        }
        return  cs;
    }
};


int main(int argc, const char * argv[]) {
    
    CashSupper *cs;
    cs = CashFactory::createCashAccept("discount 90%");
    cout<<cs->acceptMoney(1000)<<endl;
    
    cs = CashFactory::createCashAccept("Normal");
    cout<<cs->acceptMoney(1000)<<endl;
    
    return 0;
}
