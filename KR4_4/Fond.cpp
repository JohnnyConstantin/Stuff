//
// Created by J.C on 04.06.2020.
//

#include <iostream>
#include <stdlib.h>
#include "Fond.h"

using namespace std;

Fond::Fond(Fond *parent)
{
    setParent(parent);
}

Fond::Fond(Fond *parent, string name)
{
    setParent(parent);
    setName(name);
}

Fond::~Fond()
{
    for(int i =0; i < child.size(); i++)
        delete child[i];
    for(int i =0; i < connections.size(); i++)
        delete connections[i];
}

int Fond::Out(bool flag)
{
    if(flag)
        cout << "Test result\nThe object " << this->getName() << " is " << (this->getState() > 0 ? "ready" : "not ready");
    if(countChildren())
    {
        for(int i =0; i < child.size(); i++)
        {
            cout << "\nThe object " << child[i]->getName() << " is " << (child[i]->getState() > 0 ? "ready" : "not ready");
            child[i]->Out(false);
        }
    }
    return 0;
}

void Fond::OutTree(Fond *parent, int space)
{
    for(int i = 0; i < space; i++)
    {
        cout << " ";
    }
    cout << this->getName();
    for(int i=0; i < child.size(); i++)
    {
        cout << endl;
        child[i]->OutTree(this->child[i], space +1);
    }
}

Fond* Fond::fParent(string found)
{
    Fond* searchelement = NULL;

    if(found == this -> getName().c_str())
    {
        searchelement = this;
    }
    else if(countChildren())
    {
        for(int i =0; i < child.size(); i++)
        {
            searchelement = child[i] -> fParent(found);
            if(searchelement != NULL)
                break;
        }
    }
    return searchelement;
}

void Fond::setName(string name)
{
    this -> name = name;
}

void Fond::setParent(Fond *parent)
{
    this->parent = parent;
    if(parent!=nullptr)
        parent->child.push_back(this);
}

void Fond::setState(int state)
{
    this->state = state;
}

int Fond::getState()
{
    return state;
}

bool Fond::countChildren()
{
    return child.size() > 0;
}

string Fond::getName()
{
    return name;
}

Fond* Fond::child_search(string found)
{
    for(int i = 0; i < child.size(); i++)
        if(child[i]->name == found)
            return child[i];
    return nullptr;
}

Fond* Fond::adress_search(string adress)
{
    adress += '/';
    string objname = "";
    Fond* obj = this;
    for(int i = 1; i < adress.size(); i++)
    {
        if(adress[i] == '/')
        {
            if(objname != this -> getName())
            {
                obj = obj->child_search(objname);
                if(obj==nullptr)
                    break;
            }
            objname = "";
        }
        else objname += adress[i];
    }
    return obj;
}

int Fond::getClassNum()
{
    return classNum;
}

void Fond::setConnection(TYPE_SIGNAL signal, Fond *obj, TYPE_HANDLER handler)
{
    sh* value;
    for(int i=0; i < connections.size(); i++)
    {
        if((connections[i]->signal== signal) && (connections[i]->obj == obj) && (connections[i]->handler == handler))
            return;
    }

    value = new sh();
    value->signal = signal;
    value->obj = obj;
    value->handler = handler;

    connections.push_back(value);
}

void Fond::delConnection(TYPE_SIGNAL signal, Fond *obj, TYPE_HANDLER handler)
{
    sh* value;
    for(int i = 0; i < connections.size(); i++)
    {
        value = connections[i];
        if((connections[i]->signal == signal) && (connections[i]->obj == obj) && (connections[i]->handler == handler))
        {
            delete connections[i];
            connections.erase(connections.begin() + 1);
            return;
        }
    }
}

void Fond::emitSignal(TYPE_SIGNAL signal, string& command)
{
    TYPE_HANDLER handler;
    (this->*signal)(command);
    for(int i=0; i < connections.size(); i++)
    {
        if(connections[i]->signal == signal)
        {
            handler = connections[i]->handler;
            (connections[i]->obj->*handler)(command);
        }
    }
}