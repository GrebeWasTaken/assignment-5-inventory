//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <cassert>
#include <iostream>

#include "Character.h"

using namespace std;

Character::Character(const string& nameVal)
{
  name = nameVal;
  healthPoints = 100;

  // point to our built in armor/weapon
  weapon = &hands;
  armor = &skin;
}

void Character::print() const
{
  cout << name << endl;
  cout << "Health: " << healthPoints << endl;
  cout << "Armor: " << armor->toString() << endl;
  cout << "Weapon: " << weapon->toString() << endl;
  cout << "Inventory: " << endl;
  cout << "-----------------------------------" << endl;
  for (size_t i = 0; i < inventory.size(); i++) {
    if (inventory.at(i) != nullptr) {
      cout << "[" << i << "] " << inventory.at(i)->toString() << endl;
    }
  }
  cout << "-----------------------------------" << endl;
}

int Character::getHealthPoints() const
{
  return healthPoints;
}

void Character::takeDamage(int amount)
{
  int damageAmount = amount - armor->getProtection();

  if (damageAmount < 0)
    damageAmount = 0;

  healthPoints -= damageAmount;
  if (healthPoints < 0)
    healthPoints = 0;
}

void Character::attack(Character& target, int range)
{
  target.takeDamage(weapon->use(range));
}

void Character::acquire(Item* item)
{
  inventory.push_back(item);
}

void Character::equip(int itemNumber)
{
  // TODO - Implement
}

Weapon* Character::getWeapon()
{
  return weapon;
}

Armor* Character::getArmor()
{
  return armor;
}
