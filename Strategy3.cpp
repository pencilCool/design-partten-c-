//
//  main.cpp
//  Strategy3
//
//  Created by Tang yuhua on 16/6/16.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CashSuper{
public:
    virtual double acceptMoney(double money) = 0;
};

class CashNormal:public CashSuper{
public:
    double acceptMoney(double money){
        return money;
    }
};

class CashRebate: public CashSuper{
private:
    double discount;
public:
    CashRebate(double dis){
        discount = dis;
    }
    double acceptMoney(double money){
        return money * discount;
    }
};

class CashReturn: public CashSuper{
private:
    double moneyCondition;
    double moneyReturn;
public:
    CashReturn(double mc, double mr){
        moneyCondition = mc;
        moneyReturn = mr;
    }
    double acceptMoney(double money){
        double result = money;
        if (money>=moneyCondition) {
            return  money - floor(money/moneyCondition)*moneyReturn;
        }
        return result;
    }
};

class CashContext{
private:
    CashSuper *cs;
public:
    CashContext(string str){
        if (str == "Normal") {
            cs = new CashNormal();
        }else if(str == "discount"){
            cs = new CashRebate(0.9);
        }else if(str == "return 200 while over 300"){
            cs = new CashReturn(300,200);
        }
    
    }
    double getResult(double money){
        return cs->acceptMoney(money);
    }
    
};

int main(int argc, const char * argv[]) {
    double money = 1000;
    CashContext *cc = new CashContext("discount");
    cout<<cc->getResult(money)<<endl;
    return 0;
}
