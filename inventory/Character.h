//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

#include "Armor.h"
#include "Item.h"
#include "Weapon.h"

/**
 * @brief The Character class represents a player in the game
 */
class Character {
public:
  /**
   * @brief Character
   * @param nameVal value for Character's name
   */
  Character(const std::string& nameVal);

  /**
   * @brief print out all the information about the Character
   */
  void print() const;

  /**
   * @brief getHealthPoints
   * @return healthPoints
   */
  int getHealthPoints() const;

  /**
   * @brief takeDamage reduces healthPoints by given amount minus the protection
   *        value of the character's armor (min 0)
   * @param amount amount of damage to take
   */
  void takeDamage(int amount);

  /**
   * @brief Use this character's weapon to attack another character.
   * @param target Character being attacked
   * @param range distance to target
   */
  void attack(Character& target, int range);

  /**
   * @brief acquire adds an item to the inventory
   * @param item item to be added
   *
   */
  void acquire(Item* item);

  /**
   * @brief Attempt to use an item from the inventory. If it is a weapon,
   *        set it as the character's weapon. If it is armor, set it as
   *        the character's armor.
   * @param itemNumber index in the array to equip (0-based index)
   */
  void equip(int itemNumber);

  /**
   * @brief Get weapon.
   * @return currently equipped Weapon
   */
  Weapon* getWeapon();

  /**
   * @brief Get armor.
   * @return currently equipped Armor
   */
  Armor* getArmor();

private:
  std::string name;
  int healthPoints;

  // Pointers to the currently equipped weapon/armor
  Weapon* weapon;
  Armor* armor;

  // Inventory is a vector of pointers to items
  std::vector<Item*> inventory;

  // Default armor/weapon
  Armor skin = Armor("Skin", 0, 0);
  Weapon hands = Weapon("Bare Hands", 1, 0);
};

#endif
