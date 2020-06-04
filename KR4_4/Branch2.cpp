//
// Created by J.C on 04.06.2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Branch2.h"

using namespace std;

void Branch2::sign(string& text)
{
    text = " Text: " + this->getName() + " -> " + text;
}

void Branch2::hand(string text)
{
    cout << "\nSignal to " << this->getName().c_str() << text;
}