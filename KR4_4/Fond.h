//
// Created by J.C on 04.06.2020.
//
#ifndef _FOND_H
#define _FOND_H

#include <vector>
#include <string>

using namespace std;

class Fond;
typedef void (Fond::* TYPE_SIGNAL) (string &);
typedef void (Fond::* TYPE_HANDLER) (string);

class Fond
{
private:
    int state, space;
    vector<Fond*> child = {};
    Fond *parent;
    string name;
    struct sh
    {
        TYPE_SIGNAL signal;
        TYPE_HANDLER handler;
        Fond* obj;
    };
    vector<sh*> connections;

public:
    int classNum = 1;
    Fond(Fond *parent);
    Fond(Fond *parent, string name);

    int Out(bool flag);
    void setName(string name);

    string getName();
    void setState(int state);
    void setParent(Fond *parent);
    int getState();
    Fond* fParent(string found);
    bool countChildren();
    void OutTree(Fond *parent, int space);
    Fond* child_search(string found);
    Fond* adress_search(string adress);
    ~Fond();
    int getClassNum();

    void setConnection(TYPE_SIGNAL signal, Fond *obj, TYPE_HANDLER handler);
    void delConnection(TYPE_SIGNAL signal, Fond *obj, TYPE_HANDLER handler);
    void emitSignal(TYPE_SIGNAL signal, string& command);
};

#define SIGNAL_D(T, signal_f) ((TYPE_SIGNAL) (&T::signal_f))
#define HANDLER_D(G, handler_f) ((TYPE_HANDLER) (&G::handler_f))
#endif
