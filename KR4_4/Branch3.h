//
// Created by J.C on 04.06.2020.
//
#ifndef _BRANCH3_H
#define _BRANCH3_H

#include "Fond.h"

class Branch3 : public Fond
{
public:
    Branch3(Fond *parent, string name) : Fond(parent, name){}

    void sign(string& text);
    void hand(string text);
};

#endif