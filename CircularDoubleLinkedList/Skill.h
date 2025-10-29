//
// Created by Dominik on 22.10.2025.
//

#ifndef SKILLS_H
#define SKILLS_H
#include <string>

class Skill {
    int id = 0;
    std::string name;
    int power_level;

public:
    Skill(int id, std::string name, int power_level);
    friend std::ostream& operator<<(std::ostream& os, const Skill& skill);
};

// overwrite "<<" operator
inline std::ostream & operator<<(std::ostream &os, const Skill &skill) {
    os << "Skill: ( id: " << skill.id << ", name: " << skill.name << ", power level: " << skill.power_level << " )";
    return os;
}

inline Skill::Skill(int id, std::string name, int power_level) : id(id), name(name), power_level(power_level) {

}


#endif //SKILLS_H
