#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Monstres.cpp"

using namespace std;

// Method to make monsters fight
int fight(Monstres mstr1, Monstres mstr2) {

    int initialHPmstr1 = mstr1.getHp();
    int initialHPmstr2 = mstr2.getHp();

    while(mstr1.getHp() > 0 && mstr2.getHp() > 0) {

        cout << "\n\n" << endl;

        int damage = static_cast<int>(mstr1.getAtk()*0.3) + mstr1.getAtk();
        mstr2.setHp(mstr2.getHp() - rand() % damage);

        cout << mstr1.getName() << " attaque " << mstr2.getName() << " avec " << damage << " points de degats ! " << mstr2.getName() << " n'a plus que " << mstr2.getHp() << "/" << initialHPmstr2 << "HP." << endl;

        int damage2 = static_cast<int>(mstr2.getAtk()*0.3) + mstr2.getAtk();
        mstr1.setHp(mstr1.getHp() - rand() % damage2);

        cout << mstr2.getName() << " attaque " << mstr1.getName() << " avec " << damage2 << " points de degats ! " << mstr1.getName() << " n'a plus que " << mstr1.getHp() << "/" << initialHPmstr1 << "HP." << endl;
    }

    if (mstr1.getHp() <= 0) {
        cout << mstr1.getName() << " a perdu !" << endl;
    }
    else if(mstr2.getHp() <= 0) {
        cout << mstr2.getName() << " a perdu !" << endl;
    }
}



// Main program
int main() {
    string monstre1;
    string monstre2;

    Monstres demogorgon("Demogorgon",50000,12038);
    Monstres cthulu("Cthulu",579301,14000);
    Monstres kraken("Kraken",44891,9485);

    cout << "Choisissez des combattants" << endl;
    cin >> monstre1 >> monstre2;

    fight(demogorgon,cthulu);


    return 0;
}

