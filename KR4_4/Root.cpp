//
// Created by J.C on 04.06.2020.
//

#include <string>
#include <iostream>

#include "Fond.h"
#include "Branch4.h"
#include "Branch2.h"
#include "Branch3.h"
#include "Branch5.h"
#include "Branch6.h"
#include "Root.h"

using namespace std;

Root::~Root()
{
    for(int i=0; i < setCons.size(); i++)
        delete setCons[i];
}

void Root::start()
{
    this->setState(1);

    string rootName, parentName, childName;
    Fond *obj = nullptr;
    cin >> rootName;
    this->setName(rootName);
    int classNum, state;
    while(true)
    {
        cin >> parentName;
        if(parentName=="endtree")
            break;
        cin >> childName >> classNum >> state;
        switch(classNum)
        {
            case 2:
            {
                obj = new Branch2(fParent(parentName), childName);
                obj->setState(state);
                break;
            }
            case 3:
            {
                obj = new Branch3(fParent(parentName), childName);
                obj->setState(state);
                break;
            }
            case 4:
            {
                obj = new Branch4(fParent(parentName), childName);
                obj->setState(state);
                break;
            }
            case 5:
            {
                obj = new Branch5(fParent(parentName), childName);
                obj->setState(state);
                break;
            }
            case 6:
            {
                obj = new Branch6(fParent(parentName), childName);
                obj->setState(state);
                break;
            }
            default:
                obj = nullptr;
                break;
        }
    }
}

int Root::exe_cute()
{
    this->getConnections();
    cout << "Object tree\n";
    this->OutTree(this,0);
    this->setConnections();
    this->emit();
    return 0;
}

void Root::OutAdress()
{
    string adress, unique;
    Fond* obj;
    while(true)
    {
        cin >> adress;
        unique = adress;
        if(adress=="//")
            break;
        if((unique[0] == '/') && (unique[1] == '/'))
        {
            unique.erase(unique.begin(), unique.begin()+2);
            obj = this->fParent(unique);
        } else
            obj = adress_search(adress);
        cout << '\n';
        cout << adress << " Object ";
        if(obj == nullptr)
            cout << "not found";
        else
        cout << "name: " << obj->getName();
    }
}

void Root::getConnections()
{
    int conNum;
    string obj1, obj2;
    Fond *obj;
    cin >> conNum;
    while(conNum != 0)
    {
        cin >> obj1 >> obj2;
        obj = fParent(obj1);
        obj->setConnection(Root::getSignal(obj->getClassNum()),
                           fParent(obj2), Root::getHandler(fParent(obj2)->getClassNum()));
        sh* os = new sh;
        os->obj1 = obj1;
        os->num = conNum;
        os->obj2 = obj2;

        setCons.push_back(os);
        cin >> conNum;
    }
}

void Root::emit()
{
    Fond* obj;
    string name, text;
    cout << "\nEmit signals";
    cin >> name;
    while(name != "endsignals")
    {
        cin >> text;
        obj = fParent(name);
        obj->emitSignal(Root::getSignal(obj->getClassNum()), text);
        cin >> name;
    }
}

void Root::setConnections()
{
    cout << "\nSet connects";
    for(int i=0; i < setCons.size(); i++)
    {
        cout << endl << setCons[i]->num << " " << setCons[i]->obj1 << " " <<
        setCons[i]->obj2;
    }
}

void Root::sign(string& text)
{
    text = " Text: " + this->getName() + " -> " + text;
}

void Root::hand(string text)
{
    cout << "\nSignal to " << this->getName().c_str() << text;
}

TYPE_SIGNAL Root::getSignal(int classNum)
{
    switch(classNum)
    {
        case 1:
            return SIGNAL_D(Root, sign);
        case 2:
            return SIGNAL_D(Branch2, sign);
        case 3:
            return SIGNAL_D(Branch3, sign);
    }
}

TYPE_HANDLER Root::getHandler(int classNum)
{
    switch(classNum)
    {
        case 1:
            return HANDLER_D(Root, hand);
        case 2:
            return HANDLER_D(Branch2, hand);
        case 3:
            return HANDLER_D(Branch3, hand);
    }
}