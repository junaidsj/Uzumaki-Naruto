#include <iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class NarutoCharacter {
private:
    string name;
    string clan;
    string jutsu;
    int powerLevel; // Randomly generated when adding

public:
    NarutoCharacter(string n, string c, string j) : name(n), clan(c), jutsu(j) {
        powerLevel = rand() % 100 + 1; // Random power level (1-100)
    }

    string getName() const { return name; }
    string getClan() const { return clan; }
    string getJutsu() const { return jutsu; }
    int getPowerLevel() const { return powerLevel; }

    void display() const {
        cout << "Name: " << name << " | Clan: " << clan << " | Jutsu: " << jutsu
            << " | Power Level: " << powerLevel << endl;
    }
};

class NarutoWorld {
private:
    vector<NarutoCharacter> characters;

public:
    void addCharacter(string name, string clan, string jutsu) {
        NarutoCharacter newChar(name, clan, jutsu);
        characters.push_back(newChar);
        cout << name << " added to the Naruto world!\n";
    }

    void viewCharacters() const {
        if (characters.empty()) {
            cout << "No characters added yet!\n";
            return;
        }

        cout << "\n--- Naruto Characters ---\n";
        for (size_t i = 0; i < characters.size(); ++i) {
            cout << i + 1 << ". ";
            characters[i].display();
        }
    }

    void battleCharacters(int index1, int index2) {
        if (index1 < 1 || index1 > characters.size() || index2 < 1 || index2 > characters.size()) {
            cout << "Invalid selection! Choose correct indexes.\n";
            return;
        }

        NarutoCharacter& char1 = characters[index1 - 1];
        NarutoCharacter& char2 = characters[index2 - 1];

        cout << "\n🔥 Battle: " << char1.getName() << " vs " << char2.getName() << " 🔥\n";
        cout << char1.getName() << " uses " << char1.getJutsu() << "!\n";
        cout << char2.getName() << " uses " << char2.getJutsu() << "!\n";

        if (char1.getPowerLevel() > char2.getPowerLevel()) {
            cout << char1.getName() << " wins! 🏆\n";
        }
        else if (char2.getPowerLevel() > char1.getPowerLevel()) {
            cout << char2.getName() << " wins! 🏆\n";
        }
        else {
            cout << "It's a tie! 💥\n";
        }
    }
};

int main() {
    srand(time(0)); // Seed for random numbers
    NarutoWorld world;
    int choice;

    while (true) {
        cout << "\n--- Naruto World ---\n";
        cout << "1. Add Character\n";
        cout << "2. View Characters\n";
        cout << "3. Battle Between Characters\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, clan, jutsu;
            cin.ignore();
            cout << "Enter Character Name: ";
            getline(cin, name);
            cout << "Enter Clan: ";
            getline(cin, clan);
            cout << "Enter Jutsu: ";
            getline(cin, jutsu);
            world.addCharacter(name, clan, jutsu);
        }
        else if (choice == 2) {
            world.viewCharacters();
        }
        else if (choice == 3) {
            int index1, index2;
            world.viewCharacters();
            cout << "Choose two characters to battle (Enter their numbers): ";
            cin >> index1 >> index2;
            world.battleCharacters(index1, index2);
        }
        else if (choice == 4) {
            cout << "Exiting... Believe it! 🍜\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
