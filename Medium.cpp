/*****************************
 ** File: Medium.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the Medium horse class, it allows
 ** for the creation of Medium horse objects and it is the child class of
 ** WarHorse
 ***************************/
#include "Warhorse.h"
#include "Medium.h"
using namespace std;

const int MAX = 6;
// Default Constructor
// Preconditions: None
// Postconditions: None
Medium::Medium():Warhorse() {
  //calls warhorse constructor    
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Medium::Medium(string name, Size size, int health, int speed):
  Warhorse(name,size,health,speed) {} //calls warhorse overloaded constructor 

// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + training level (0-5)
// Also, displays actual attack
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Medium::attack(string name, int yourHealth) {
  int damage;
  //calculates the damage 
  damage = (yourHealth/MAX) + getTraining();
  //print statement
  cout << "The Medium Warhorse " << getName() << " hits " << name << endl;

  return damage;
  
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Medium")
string Medium::toString() {
  //returns a string of the name of the subclass
  return "Medium";
}

