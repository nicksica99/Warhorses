/*****************************
 ** File: Warhorse.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the Warhorse class, it allows
 ** for the creation of Warhorse objects and it is the child class of 
 ** Horse
 ***************************/
#include "Warhorse.h"
#include "Horse.h"
#include <string>
#include <ctime>
#include <iostream>
#include <vector> 
using namespace std;
//gets rid of magic number
const int FIFTY = 50;
// Default Constructor
// Preconditions: None
// Postconditions: None
Warhorse::Warhorse():Horse() {
  //calls horse constructor 
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Warhorse::Warhorse(string name, Size size, int health, int speed):
  Horse(name,size,health,speed) {} //calls overloaded horse constructor 

// train() - Tests if animal successfully ate.
// - if the hunt was a success or they are age 1 then true
// otherwise they have a 50% chance
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal ate or did not
//                 in the course of the year
bool Warhorse::train() {
  srand(time(NULL));
  //calls random percent based function from horse.cpp to check if the horse gets
  //trained or not 
  bool random = randomPercentBased(FIFTY);
  
  return random;
  
}


// toString() - purely virtual
// Preconditions: all variables are set valid
// Postconditions: used for subclasses to return string of their type
//virtual string toString() = 0;

// battle(Horse*) - passed enemy horse
// turns are based on speed - counter starts at 0 and if counter % speed == 0 then
// that horse attacks counter%getSpeed()==0, attacks. If attack leaves at or below 0
// then that horse loses battle.
// Preconditions: enemy horse has been defined
// Postconditions: returns a bool of who won battle between two horses
bool Warhorse::battle(Horse* enemy) {
  int counter = 0;
  bool winLoss;
  int damage = 0;
  int userDamage = 0;
  //while loop that keeps the battle going until one horse hits 0 health  
  while((getHealth() > 0) && (enemy->getHealth() > 0)) {
    //resets the damage variables
    damage = 0;
    userDamage = 0;
    //if the users horse and the enemy horse have the same then both attack, but user
    //horse is first 
    if((counter % getSpeed() == 0) && (counter % enemy->getSpeed() == 0)) {
      //gets the damage to the enemy horse 
      userDamage = attack(enemy->getName(), enemy->getHealth());
      //sets the enemy's health to the new health 
      enemy->setHealth(enemy->getHealth() - userDamage);
			 
      //enemy's attack to user horse 
      damage = enemy->attack(getName(), getHealth());
      //sets the user's horse new health
      setHealth(getHealth() - damage);
      
    }//if only the users horse can attack 
    else if(counter % getSpeed() == 0) {
      //attacks the enemy horse and sets the new health
      damage = attack(enemy->getName(), enemy->getHealth());
      enemy->setHealth(enemy->getHealth() - damage);
      
    }//if only the enemy horse can attack 
    else if(counter % enemy->getSpeed() == 0) {
      //attacks the user horse and sets the new health 
      damage = enemy->attack(getName(), getHealth());
      setHealth(getHealth() - damage);
      
    }
    //counter increases every 'round'
    counter++;
    
    
  }//if the user wins then winLoss returns true
  if(enemy->getHealth() <= 0) {
    winLoss = true;
  }
  else {
    //if user loses then winLoss returns false 
    winLoss = false;
  }
  return winLoss;
}

// attack(string, int) - purely virtual (implemented in all child classes)
// Preconditions: passed string name of target and health of attacker
// Postconditions: returns damage as an integer
//virtual int attack(string, int) = 0;







  








