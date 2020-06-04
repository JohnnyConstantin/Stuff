//
// Created by J.C on 04.06.2020.
//

#ifndef _ROOT_H
#define _ROOT_H

#include "Fond.h"
#include <vector>
#include <string>

using namespace std;

class Root:public Fond
{
protected:
    struct sh
    {
        string obj1;
        string obj2;
        int num;
    };
    vector<sh*> setCons;

public:
    Root(Fond* parent) : Fond(parent){};
    void OutAdress();
    int exe_cute();
    void start();
    void setConnections();
    void getConnections();
    void emit();
    void sign(string& text);
    void hand(string text);
    static TYPE_SIGNAL getSignal(int cl);
    static TYPE_HANDLER getHandler(int cl);
    ~Root();
};

#endif
