/*****************************
 ** File: War.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the War.cpp file, it allows
 ** for the start of the program and the creation of the game and the user 
 ** input
 ***************************/
#include "War.h"
#include "Horse.h"
#include "Untrained.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
const int SMALLWIDTH = 10;
const int WIDTH = 20;
const char SEPARATE = ' ';

//ints for other random stuff such as QUIT 
const int LIGHT = 0;
const int MED = 1;
const int HEAVY = 2;
const int QUIT = 6;
// Default Constructor
// Preconditions: None
// Postconditions: Seeds srand only
War::War() {
  srand(time(NULL));
  //seeds 
}

// Destructor
// Preconditions: m_myStable and/or m_enemyStable is populated
// Postconditions: Deallocates horse objects in all vectors
War::~War() {
  //deletes the horses throughout both stables 
  for(int i = 0; i < (int) m_myStable.size(); i++) {
    delete m_myStable.at(i);
  }
  for(int j = 0; j < (int) m_enemyStable.size(); j++) {
    delete m_enemyStable.at(j);
  }
}

// Name: loadHorses
// Desc - Loads each horse into m_enemyStable from file
// Preconditions - Requires file with valid horse data
// Postconditions - m_enemyStable is populated with enemy horse pointers
void War::loadHorses(char* filename) {
  //variables to read in all of the variables 
  ifstream inputStream;
  string name;
  int size;
  Size horseSize;
  int health;
  int speed;
  int count = 0;
  //opens file 
  inputStream.open(filename);

  //while there is a name to read in 
  while(inputStream >> name) {
    //reads in size
    inputStream >> size;
    //sets the size to the correct enum type 
    if(size == LIGHT) {
      horseSize = SMALL;
    }
    else if(size == MED) {
      horseSize = MEDIUM;
    }
    else if(size == HEAVY) {
      horseSize = LARGE;
    }
    //reads in health and sped
    inputStream >> health;
    inputStream >> speed;
    //if the size is small then it creates a new light horse 
    if(horseSize == SMALL) {

      Horse* myLight = new Light(name,horseSize , health, speed);
      m_enemyStable.push_back(myLight);
    }
    //if the size is medium then it creates a new medium horse 
    else if(horseSize == MEDIUM) {
        
      Horse* myMedium = new Medium(name, horseSize, health, speed);
      m_enemyStable.push_back(myMedium);
    }
    //if the size is large then it creates a new heavy horse 
    else if(horseSize == LARGE) {
      
      Horse* myHeavy = new Heavy(name, horseSize, health, speed);
      m_enemyStable.push_back(myHeavy);
    }
    //count just for the horses 
    count += 1;
  }  
    
    
    
  //print statement to see if all of the horses loaded
  cout << count << " enemy horses loaded" << endl;
  
  //close file
  inputStream.close();
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - m_enemyStable has been populated from file
// Postconditions - exits if user entered 6
void War::mainMenu() {
  int choice;
  //menu prints
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Display Friendly Stable" << endl;
    cout << "2. Display Enemy Stable" << endl;
    cout << "3. Acquire Horse" << endl;
    cout << "4. Train Horse" << endl;
    cout << "5. Battle" << endl;
    cout << "6. Quit" << endl;
    //get input 
    cin >> choice;

    //input validation and menu choice again
    if(choice <= 0 || choice > QUIT) {
      cout << "That was an invalid selection, try again" << endl;
      cout << endl;
      //menu again
      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl;
      cout << "2. Display Enemy Stable" << endl;
      cout << "3. Acquire Horse" << endl;
      cout << "4. Train Horse" << endl;
      cout << "5. Battle" << endl;
      cout << "6. Quit" << endl;

      cin >> choice;
    }
    //switch statement for the choice 
    switch(choice) {
    case 1:
      //display your horses
      displayMyHorses();
      break;

    case 2:
      //display enemy horses
      displayEnemyHorses();
      break;

    case 3:
      //make a new horse
      acquireHorse();
      break;

    case 4:
      //train horse 
      trainHorse();
      break;

    case 5:
      //start battle 
      startBattle();
      break;

    case 6:
      //exit
      cout << "Thank you for playing Warhorse" << endl;

    }
    //while the choice does not equal quit
  } while(choice != QUIT);
  
}

// Name: acquireHorse()
// Desc - user randomly acquires a new untrained horse (random size)
// Preconditions - none
// Postconditions - new horse is added to m_myStable
void War::acquireHorse() {
  //horse attributes
  string nameHorse;
  int speed;
  int health;
  Size horseSize;
  //gets choice for the name of the horse 
  cout << "What would you like to name the horse?" << endl;
  cin.ignore();
  //allows for multiple name/spaces 
  getline(cin, nameHorse);

  srand(time(NULL));
  //randomizes if it is a heavy/medium/light horse 
  int random = rand() % (HEAVY + 1) + 1;
  random = random - 1;

  
  //if the horse is light randomize using the light constants 
  if(random == LIGHT) {
    //health is random using light health constants- range is max to min
    health = rand() % (LT_MAX_HEALTH - LT_MIN_HEALTH + 1) + LT_MIN_HEALTH;
    //speed is randomized using light speed constants
    speed = rand() % (LT_MAX_SPEED - LT_MIN_SPEED + 1) + LT_MIN_SPEED;
    horseSize = SMALL;
  }
  else if(random == MED) {
    //health is random using medium health constants- range is max to min
    health = rand() % (MD_MAX_HEALTH - MD_MIN_HEALTH + 1) + MD_MIN_HEALTH;
    //speed is randomized using light speed constants
    speed = rand() % (MD_MAX_SPEED - MD_MIN_SPEED + 1) + MD_MIN_SPEED;
    horseSize = MEDIUM;
  }
  else {
    //health is random using heavy health constants- range is max to min
    health = rand() % (HV_MAX_HEALTH - HV_MIN_HEALTH + 1) + HV_MIN_HEALTH;
    //speed is randomized using light speed constants
    speed = rand() % (HV_MAX_SPEED - HV_MIN_SPEED + 1) + HV_MIN_SPEED;
    horseSize = LARGE;
  }
  
  ///creates a new untrained horse object using the random attributes 
  Horse* myHorse = new Untrained(nameHorse, horseSize, health, speed);
  //pushes it back into the vector 
  m_myStable.push_back(myHorse);
  
  
}

// Name: trainHorse()
// Desc - user randomly acquires a horse
// Preconditions - none
// Postconditions - new horse is added to m_stable
void War::trainHorse() {
  //variables for the training
  Horse* newHorse;
  int trainChoice;
  bool trained;
  //gets users choice for which horse they want to train
  trainChoice = chooseHorse();
  //if the size is unknown then it specializes the horse into a
  //warhorse and adds it into the vector
  if(m_myStable.at(trainChoice)->toString() == "Unknown") {
    newHorse = m_myStable.at(trainChoice)->specialize();
    //deletes the old horse object 
    delete m_myStable.at(trainChoice);
    m_myStable.at(trainChoice) = newHorse;  
      
  }
  //if the size is not unknown 
  else {
    //random boolean checks to see if the horse was trained 
    bool random = m_myStable.at(trainChoice)->train();
    if(random == true) {
      //if the horse was trained then increase the training level 
      trained = m_myStable.at(trainChoice)->increaseTraining();
      if(trained == true) {
	//print staement 
	cout << "Your horse has been trained" << endl;
      }
      else {
	//max training statement 
	cout << "Your horse is at the max training" << endl;
      }
    }
    else{
      //didnt train
      cout << "Your horse failed to be trained" << endl;
    }
  }
}
// Name: startBattle()
// Desc - user selects a horse to battle with and fights first horse in enemy
// m_enemyStable. Horse that loses is removed from their respective stable forever
// User must have at least ONE specialized horse at least training level 2 or higher
// Preconditions - Use has at least one horse and horse is specialized trained
// Postconditions - m_myStable or m_enemyStable has loser removed
void War::startBattle() {
  //users choice 
  int battleChoice;
  //counter 
  int counter = 0;
  //bool if the user wins or loss
  bool winLoss;
  //user chooses horse for battle 
  battleChoice = chooseHorse();
  //gets the original healths of both horses for the regeneration effect 
  int firstEnemyHealth = m_enemyStable.at(counter)->getHealth();
  int firstUserHealth = m_myStable.at(battleChoice)->getHealth();
  //if the horse cant battle because it is not trained
  if(m_myStable.at(battleChoice)->getTraining() == (Training) 0) {
    cout << "Untrained horses can't battle, the horse must be at least Saddle trained" << endl;
    
  }
  else {
    //battles the horses -calls the warhorse.cpp function
    winLoss = m_myStable.at(battleChoice)->battle(m_enemyStable.at(counter));
    //if the users horse lost
    if(winLoss == false) {
      //print
      cout << m_myStable.at(battleChoice)->getName() << " lost the battle" << endl;
      //deletes the horse object 
      delete m_myStable.at(battleChoice);
      //removes horse from vector 
      m_myStable.erase(m_myStable.begin() + battleChoice);
      //resets enemy health 
      m_enemyStable.at(counter)->setHealth(firstEnemyHealth);
      
    }//if users horse wins
    else if(winLoss == true) {
      //print statement 
      cout << m_myStable.at(battleChoice)->getName() << " won the battle" << endl;
      //checks if the last horse was beaten 
      if(m_enemyStable.at(counter)->getName() == "Xanthos") {
	//congrats statement
	cout << "Congrats you have beaten all of the enemy Horses, go celebrate!!!" << endl;
      }
      //deletes enemy horse 
      delete m_enemyStable.at(counter);
      //removes the enemy horse from vector 
      m_enemyStable.erase(m_enemyStable.begin());
    
      //resets user horse health
      m_myStable.at(battleChoice)->setHealth(firstUserHealth);
    }

  }
}

// Name: displayMyHorses()
// Desc - Displays all horses in m_myStable or empty message if no horses
// Preconditions - m_myStable is populated
// Postconditions - None
void War::displayMyHorses(){
  //prints the users horse table stuff
  //also sets the format as seen in the sample code output 
  cout << "My Horses" << endl;
  cout << left << setw(SMALLWIDTH) << setfill(SEPARATE) << "Num"
       << setw(WIDTH) << setfill(SEPARATE) << "Horse"
       << setw(WIDTH) << setfill(SEPARATE) << "Size"
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Health"
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Speed"
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Training" << endl;
  //goes through the loop and prints the users horses info
  //sets format as seen in the sample code output
  for(int i = 0; i < (int) m_myStable.size(); i++) {
    cout << left << setw(SMALLWIDTH) << setfill(SEPARATE) << i + 1 //prints num;
	 << *m_myStable.at(i);
  }
}

  
// Name: displayEnemyHorses()
// Desc - Displays all horses in m_enemyStable or win message if empty
// Preconditions - m_enemyStable is populated
// Postconditions - None
void War::displayEnemyHorses() {
  //displays the top of the table stuff
  cout << "Enemy  Horses" << endl;
  cout << left << setw(SMALLWIDTH) << setfill(SEPARATE) << "Num" //num and sets the format 
       << setw(WIDTH) << setfill(SEPARATE) << "Horse" //horse name and sets format 
       << setw(WIDTH) << setfill(SEPARATE) << "Size" //size and sets format 
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Health" //health and sets format 
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Speed" //speed and sets format 
       << setw(SMALLWIDTH) << setfill(SEPARATE) << "Training" << endl; //training and sets format
  //goes through the stable and prints the horses data using the overloaded operator 
  for(int i = 0; i < (int) m_enemyStable.size(); i++) {
    cout << setw(SMALLWIDTH) << setfill(SEPARATE) << i + 1 //prints num;
	 << *m_enemyStable.at(i);
  }
}
// Name: chooseHorse
// Desc - Helper that either displays that m_myStable is empty or allows user to
//        choose a horse to use for training or battle. Returns index + 1
// Preconditions - None
// Postconditions - None
int War::chooseHorse() {
  int choice;
  //num horses equals the size of the vector 
  int numHorses = (int)m_myStable.size();
  //checks if the stable is empty 
  if(numHorses == 0) {
    cout << "Your stable is empty" << endl;
    return -1;
  }
  //if the vector is not empty then it displays the horses and gets the user choice for horse 
  else {
    cout << "Which horse would you like?" << endl;
    displayMyHorses();

    cin >> choice;
    //input validation
    if(choice <= 0 || choice > int(m_myStable.size())) {
      cout << "Invalid selection try again" << endl;
      cout << "Which horse would you like?" << endl;
      cin >> choice;
      }
    //gets the choice - 1 as the index would be incorrect 
    choice = choice - 1;
    
  }//returns the users choice 
  return choice;
}







