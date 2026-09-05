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
    //"increases strength in proportion to time is accomplised by the number of times you choose to go to the gym

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
        cout << h.getName() << " failed on their quest.\n";
    }

    if (win == 1) {
        h.setCrg(h.getCrg() + (rand() % 10) + 1);
        cout << h.getName() << " won!\n";
    }

    if (win == 0) {
        h.setCrg(h.getCrg() - (rand() % 8) + 1);
        cout << h.getName() << " tied? \n";
    }

}



int main() {
    
    bool leave = false;
    bool quit = false;
    char ans;
    char prep;
    string nam;

    cout << "What is your hero's name? \n";
    cin >> nam;

    hero knight(nam);

    cout << knight.getName() << " stats: \n";
	cout << "Strength: " << knight.getStr() << "\n";
    cout << "Courage: " << knight.getCrg() << "\n";

    while (quit == false) {
        while (leave == false) {
            cout << "Should " << knight.getName() << " hit the gym(g), go to therapy(t), or leave for the quest(q)? \n";
            cin >> prep;
            if (prep == 'g') {
                knight.gym();
                cout << knight.getName() << "'s updated strength is now : " << knight.getStr() << "\n";
            }
            if (prep == 't') {
                knight.therapy();
                cout << knight.getName() << "'s updated courage is now: " << knight.getCrg() << "\n";
            }
            if (prep == 'q') {
                cout << knight.getName() << "'s final stats:\n";
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

        cout << knight.getName() << "'s new strength: " << knight.getStr() << "\n";
        cout << knight.getName() << "'s new courage: " << knight.getCrg() << "\n";
        cout << "Quit? (y/n): ";
        cin >> ans;
        if (ans == 'y') {
            break;
        }
		leave = false;
    }

    return 0;
}

