//
//  main.cpp
//  AbstractFactory
//
//  Created by Tang yuhua on 16/6/17.
//  Copyright © 2016年 Tang yuhua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class IUser{
public:
    virtual void getUser() = 0;
    virtual void setUser() = 0;
    
};

class SqlUser:public IUser{
public:
    void getUser(){
        cout<<"return data from sql to user"<<endl;
    }
    void setUser(){
        cout<<"set data to sql"<<endl;
    }
    
};

class AccessUser:public IUser {
public:
    void getUser(){
        cout<<"data from Access to user"<<endl;
    }
    void setUser(){
        cout<<"set data to Access"<<endl;
    }
};

class IDepartment{
public:
    virtual void getDepartment() = 0;
    virtual void setDepartment() = 0;
};

class SqlDepartment:public IDepartment {
public:
    void getDepartment(){
        cout<<"department from sql to user"<<endl;
    }
    void setDepartment(){
        cout<<"set department to sql"<<endl;
    }
};

class AccessDepartment:public IDepartment {
public:
    void getDepartment(){
        cout<<"department from Access to user"<<endl;
    }
    void setDepartment(){
        cout<<"set department to Access"<<endl;
    }
};

class IFactory{
public:
    virtual IUser * createUser() = 0;
    virtual IDepartment *createDepartment() = 0;
};

class SqlFactory: public IFactory{
public:
    IUser *createUser() {
        return new SqlUser();
    }
    IDepartment *createDepartment(){
        return new SqlDepartment();
    }
};

class AccessFactory: public IFactory{
public:
    IUser *createUser() {
        return new AccessUser();
    }
    IDepartment *createDepartment(){
        return new AccessDepartment();
    }
};

class DataAccess{
private:
    static string db;
public:
    static IUser *createUser(){
        if (db=="access") {
            return new AccessUser();
        }else if(db=="sql"){
            return new SqlUser();
        }else{
            return NULL;
        }
    }
    static IDepartment *createDepartment(){
        if (db=="access") {
            return new AccessDepartment();
        }else if(db=="sql"){
            return new SqlDepartment();
        }else{
            return NULL;
        }
    }
};

string DataAccess::db = "sql";



int main(int argc, const char * argv[]) {

    IFactory *factory;
    IUser *user;
    IDepartment *department;
    
    factory = new AccessFactory();
    user = factory->createUser();
    department = factory->createDepartment();
    
    user->getUser();
    user->setUser();
    department->getDepartment();
    department->setDepartment();
    
    user=DataAccess::createUser();
    department = DataAccess::createDepartment();
    
    user->getUser();
    user->setUser();
    department->getDepartment();
    department->setDepartment();
    
    
    return 0;
}
