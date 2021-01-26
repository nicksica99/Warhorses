/*****************************
 ** File: Heavy.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the Heavy horse class, it allows
 ** for the creation of Heavy horse objects and it is the child class of
 ** WarHorse
 ***************************/
#include "Warhorse.h"
#include "Heavy.h"
using namespace std;
//constants used
const int SIX = 6;
const int MAX = 3;

// Default Constructor
// Preconditions: None
// Postconditions: None
Heavy::Heavy():Warhorse() {
} //calls warhorse constructor 

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Heavy::Heavy(string name, Size size, int health, int speed):
  Warhorse(name, size, health, speed) {} //calls overloaded warhorse constructor 

// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + training level (0-5)
// Also, displays actual attack
// Finally, the heavy warhorse calls kick from attack (special attack for heavy)
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Heavy::attack(string name, int yourHealth) {
  int damage;
  //calculates damage to the horse
  damage = (yourHealth/MAX) + getTraining();
 
  cout << "The Heavy Warhorse " << getName() << " hits " << name << endl;
  //gets the kick damage 
  int kickDamage = kick();
  //sum of both damages 
  damage += kickDamage;
  
  return damage;
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Heavy")
string Heavy::toString() {
  //returns a string of the name of the subclass 
  return "Heavy";
}

// kick() - a special attack by heavy warhorses
// Preconditions: all variables are set valid
// Postconditions: returns an int between 1 and 3 of additional damage
int Heavy::kick() {
  int kickDamage;
  //seeds
  srand(time(NULL));
  //gets the amount of kickdamage done as a heavy warhorse 
  kickDamage = rand() % MAX + 1;
  //print statement 
  cout << "The Heavy Warhorse spins and kicks the enemy!" << endl;
  return kickDamage;

  
}




