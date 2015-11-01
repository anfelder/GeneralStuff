#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


class Character
{
public:
    Character();

    //set methods
    void Set_Name(string n);
    void Set_Race(string r);
    void Set_Background(string b);
    void Set_Alignment(string a);
    void Set_EXP(int e);
    //Saving Throws
    void Set_Strength(int s);
    void Set_Strength_Passive(int s_p);
    void Set_Dexterity(int d);
    void Set_Dexterity_Passive(int d);
    void Set_Constitution(int c);
    void Set_Const_Passive(int c);
    void Set_Intelligence(int i);
    void Set_Intell_Passive(int i);
    void Set_Wisdom(int w);
    void Set_Wisdom_Passive(int w);
    void Set_Charisma(int c);
    void Set_Charisma_Passive(int c);
    //Skills
    void Set_Acrobatics(int a);
    void Set_Animal_Handling(int a);
    void Set_Arcana(int a);
    void Set_Athletics(int a);
    void Set_Deception(int d);
    void Set_History(int h);
    void Set_Insight(int i);
    void Set_Intimidation(int i);
    void Set_Investigation(int i);
    void Set_Medicine(int m);
    void Set_Nature(int n);
    void Set_Perception(int p);
    void Set_Performance(int p);
    void Set_Persuasion(int p);
    void Set_Religion(int r);
    void Set_Sleight_of_hand(int s);
    void Set_Stealth(int s);
    void Set_Survival(int s);
    //Other Info
    void Set_Proficiency_Bonus(int p);
    void Set_Armor_Class(int a);
    void Set_Initiative(int i);
    void Set_Speed(int s);
    void Set_Max_Hp(int m);
    void Set_Current_Hp(int c);
    void Set_Death_Save_S(int d);
    void Set_Death_Save_F(int d);
    void Set_Passive_Wisdom(int p);

    //Passives
    void Set_Personality_Traits(string p);
    void Set_Ideals(string i);
    void Set_Bonds(string b);
    void Set_Flaws(string f);
    void Set_Feats_Traits(string f);
    void Set_Proficiencies(string p);
    void Set_Languages(string l);

    //Equipment/Attacks
    void Set_Weapon_Name(string w[3]);
    void Set_Weapon_Atk_Bonus(int w[3]);
    void Set_Weapon_Damage_Type(string w[3]);
    void Set_CP(int c);
    void Set_SP(int s);
    void Set_EP(int e);
    void Set_GP(int g);
    void Set_PP(int p);
    void Set_Equipment(string e);
    void Set_Attack_Effects(string a);




private:
    //character info
    string name;
    string race;
    string background;
    string alignment;
    int exp;
    //Saving Throws
    int strength;
    int strength_passive;
    int dexterity;
    int dexterity_passive;
    int constitution;
    int const_passive;
    int intelligence;
    int intell_passive;
    int wisdom;
    int wisdom_passive;
    int charisma;
    int charisma_passive;
    //Skills
    int acrobatics;
    int animal_handling;
    int arcana;
    int athletics;
    int deception;
    int history;
    int insight;
    int intimidation;
    int investigation;
    int medicine;
    int nature;
    int perception;
    int performance;
    int persuasion;
    int religion;
    int sleight_of_hand;
    int stealth;
    int survival;
    //Other Info
    int proficiency_bonus;
    int armor_class;
    int initiative;
    int speed;
    int max_hp;
    int current_hp;
    int death_save_s;
    int death_save_f;
    int passive_wisdom;

    //Passives
    string personality_traits;
    string ideals;
    string bonds;
    string flaws;
    string feats_traits;
    string proficiencies;
    string languages;

    //Equipment/Attacks
    string weapon_name[3];
    int weapon_atk_bonus[3];
    string weapon_damage_type[3];
    int cp;
    int sp;
    int ep;
    int gp;
    int pp;
    string equipment;
    string attack_effects;
};

#endif // CHARACTER_H
