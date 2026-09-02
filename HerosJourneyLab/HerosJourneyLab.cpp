#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

class hero {
private:
    
    string name;
    int str;
    int crg;

public:

    hero(const string& name1) {
        name = name1;
        str = (rand() % 35) + 1;
        crg = (rand() % 30) + 1;
    }

    string getName() const {
        return name;
    }

    //str = (rand() % 35) + 1;
    //crg= (rand() % 30) + 1;

    int getStr() const {
        return str;
    }

    int getCrg() const {
        return crg;
    }

    void setCrg(int courage) {
        crg = courage;
    }

    void gym() {
        str += (rand() % 10) + 1;
    }

    void therapy() {
        crg += (rand() % 10) + 1;
    }

    
};

void quest(hero& h) {
    int win = 0;
    int chance = 0;

    if (h.getStr() <= 40) {
        chance = (rand() % 100) + 1;
        if (chance <= 10) {
            win = 1;
        }
        else if (chance > 15) {
            win = -1;
        }
    }

    if (h.getStr() > 40 && h.getStr() <= 70) {
        chance = (rand() % 100) + 1;
        if (chance <= 20) {
            win = 1;
        }
        else if (chance > 45) {
            win = -1;
        }
    }

    if (h.getStr() > 70) {
        chance = (rand() % 100) + 1;
        if (chance <= 70) {
            win = 1;
        }
        else if (chance > 90) {
            win = -1;
        }
    }

    if (win == -1) {
		h.setCrg(h.getCrg() - (rand() % 15) + 1);
        cout << "Hero lost.\n";
    }

    if (win == 1) {
        h.setCrg(h.getCrg() + (rand() % 10) + 1);
        cout << "Hero won!\n";
    }

    if (win == 0) {
        h.setCrg(h.getCrg() - (rand() % 8) + 1);
        cout << "Hero tied?\n";
    }

}



int main() {
    
    bool leave = false;
    char prep;

    hero knight("Knight");

    cout << "Hero's stats: \n";
	cout << "Strength: " << knight.getStr() << "\n";
    cout << "Courage: " << knight.getCrg() << "\n";

    while (leave == false) {
        cout << "Should hero hit the gym(g), go to therapy(t), or leave for the quest(q)? \n";
        cin >> prep;
        if (prep == 'g') {
            knight.gym();
			cout << "Hero's updated strength is now: " << knight.getStr() << "\n";
        }
        if (prep == 't') {
            knight.therapy();
            cout << "Hero's updated courage is now: " << knight.getCrg() << "\n";
        }
        if (prep == 'q') {
            cout << "Hero's final stats:\n";
            cout << "Strength: " << knight.getStr() << "\n";
            cout << "Courage: " << knight.getCrg() << "\n";
            leave = true;
        }
    }

    //cout << "Knight went to the gym. \n";
    //knight.gym();
    //cout << "Knight went to therapy. \n";
    //knight.therapy();
    //cout << knight.getStr() << "\n";
    //cout << knight.getCrg() << "\n";

    quest(knight);

    cout << "Hero's new strength: " << knight.getStr() << "\n";
    cout << "Hero's new courage: " << knight.getCrg() << "\n";

    return 0;
}

