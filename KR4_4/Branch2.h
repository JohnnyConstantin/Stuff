//
// Created by J.C on 04.06.2020.
//
#ifndef _BRANCH2_H
#define _BRANCH2_H

#include "Fond.h"

class Branch2 : public Fond
{
public:
    Branch2(Fond *parent, string name) : Fond(parent, name){}

    void sign(string& text);
    void hand(string text);
};

#endif