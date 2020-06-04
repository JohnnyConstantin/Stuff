//
// Created by J.C on 04.06.2020.
//

#ifndef _BRANCH4_H
#define _BRANCH4_H

#include "Fond.h"

class Branch4 : public Fond
{
public:
    Branch4(Fond *parent, string name) : Fond(parent, name){}
};

#endif