//
// Created by Malo on 13/02/2018.
//

#include "Monstres.h"
#include <string>;
using namespace std;


class Monstres {
    string name;
    int hp;
    int atk;
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Monstres::name = name;
    }

    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        Monstres::hp = hp;
    }

    int getAtk() const {
        return atk;
    }

    void setAtk(int atk) {
        Monstres::atk = atk;
    }

public:
        Monstres(string name,int hp, int atk)
                : name(name), hp(hp), atk(atk) {}


};

