// Devin Hill
// Open Lab 3: Textemon Battle
#include <iostream>
#include <iomanip>
using namespace std;


// variables 
string user_select;
string ai_select = "BattleMonX";
int ai_hp;
int user_hp;
int attack_choice;
int damage;
int hp = 0;


// function names
void outputHealth(string Textemon, int x);
int loudSoundPunch(string Textemon, int x);
int specialBeamAttack(string Textemon, int x);
int bandaids(string Textemon, int x);
void runAway();
int aiAttack(string ai_select);
int userAttack(string user_select);


int main() {

  // header / prompt
  cout << "BadguyAI has requested a battle!!!" << endl;
  cout << "..."<< endl;
  cout << "BadguyAI sent out BattlemonX" << endl;
  cout << "..."<< endl;
  cout << "Who do you send out? ";
  getline(cin, user_select);
  cout << "You sent out " << user_select << "!" << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  
  // creating user and ai hp
  int ai_healthhp = rand() % (151 - 100) +100;
  int user_healthhp = rand() % (151 - 100) +100;

  // loop continue game
 while (ai_healthhp > 0 || user_healthhp > 0) {
  outputHealth(ai_select, ai_healthhp);
  outputHealth(user_select, user_healthhp);
  cout << "Select Ability (1-4)" << endl;
  cout << "1. LOUDSOUNDPUNCH" << "    " << "3. BANDAIDS" << endl;
  cout << "2. SPECIALBEAMATTACK" << " " << "4. RUNAWAY" << endl;
  cout << "Choice: ";
  cin >> attack_choice;

   // attack decisions
   if (attack_choice > 0 && attack_choice < 5){
   // if (attack_choice > 0 && attack_choice < 3){
   damage = userAttack(user_select);
    ai_healthhp -= damage;
    user_healthhp -= damage;
   outputHealth(ai_select, ai_healthhp);
   outputHealth(user_select, user_healthhp);
   aiAttack(ai_select);
     // maybe fixes bandaids? ---------------------
   //   } else if (attack_choice == 3){
   //   damage = userAttack(user_select);
   //  ai_healthhp += damage;
   //  user_healthhp += damage;
   // outputHealth(ai_select, ai_healthhp);
   // outputHealth(user_select, user_healthhp);
   // aiAttack(ai_select);
     // --------------------------------------------
     } else {
     cout << "Please select a valid ability!" << endl;
     cout << endl;
     cout << endl;
     cout << endl;
     }
   } 
} 

// functions ----------------------------------------------

void outputHealth(string Textemon, int hp){
  cout << Textemon << ": " << hp << "hp" << endl;
}

int loudSoundPunch(string Textemon, int hp){
    int rand_hp = rand() % 11;
    cout << Textemon << " performed LOUDSOUNDPUNCH!" << endl; 
    cout << endl;
    cout << endl;
    cout << endl;
    hp = rand_hp;
    return hp;    
  }

int specialBeamAttack(string Textemon, int hp){
    int rand_hp = rand() % 8 * 2;
    cout << Textemon << " performed SPECIALBEAMATTACK!" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    hp = rand_hp;
    return hp; 
  }

int bandaids(string Textemon, int hp){
    int rand_hp = rand() % 10 - 4;
    cout << Textemon << " performed BANDAID!" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    hp = rand_hp;
    return hp;
  }

void runAway(string Textemon){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << Textemon << " tried to run away..." << endl;
    cout << "too bad you can't in our awesome game!" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
}

int aiAttack(string ai_select){
  int rand_attack = rand() % (4 - 1);
  if (rand_attack <= 0 || rand_attack >=5){
     cout << "Please select a valid ability!" << endl;
   } else if (rand_attack == 1){
      hp = loudSoundPunch(ai_select, hp);
    return hp;
    } else if (rand_attack == 2){
     hp = specialBeamAttack(ai_select, hp);
    return hp;
    } else if (rand_attack == 3){
     bandaids(ai_select, hp);
    } else if (rand_attack == 4){
     runAway(ai_select);
    } else {
     cout << "Please select a valid ability!" << endl;
     }
  }

int userAttack(string user_select){
  if (attack_choice <= 0 || attack_choice >=5){
     cout << "Please select a valid ability!" << endl;
   } else if (attack_choice == 1){
     hp = loudSoundPunch(user_select, hp);
    return hp;
    } else if (attack_choice == 2){
     hp = specialBeamAttack(user_select, hp);
    return hp;
    } else if (attack_choice == 3){
     bandaids(user_select, hp);
    } else if (attack_choice == 4){
     runAway(user_select);
    } else {
     cout << "Please select a valid ability!" << endl;
     }
}


