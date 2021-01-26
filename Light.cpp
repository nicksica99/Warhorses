/*****************************
 ** File: Light.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Nick Sica
 ** Date: 4/8/19
 ** Section: 07
 ** E-mail: nsica1@umbc.edu
 **
 ** This file contains the main code for the Light horse class, it allows
 ** for the creation of light horse objects and it is the child class of
 ** WarHorse
 ***************************/
#include "Warhorse.h"
#include "Light.h"
using namespace std;
//used to get rid of magic number 
const int MAX = 6;
// Default Constructor
// Preconditions: None
// Postconditions: None
Light::Light():Warhorse() {
  //calls warhorse constructor 
}

// Overloaded Constructor
// Preconditions: Valid inputs (name, align, size, health, speed)
// Postconditions: None
Light::Light(string name, Size size, int health, int speed):
  Warhorse(name,size,health,speed) {}
//calls warhorse overloaded constructor 



// attack(string, int) - Returns amount of damage from attack
// Damage is calculated as health/6 + training level (0-5)
// Also, displays actual attack
// Preconditions: passed string name of target and attacker's health
// Postconditions: returns damage as integer
int Light::attack(string name, int yourHealth) {
  int damage;
  //calculates the damage to the horse object
  damage = (yourHealth/MAX) + getTraining();
  //print statement
  cout << "The light warhorse " << getName() << " hits " << name << endl;

  return damage;
}

// toString() - a string representation of the child class
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the subclass (return "Light")
string Light::toString() {
  //returns a string of the name of the subclass
  return "Light";
}






