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

    bool operator<(const Skill& right_skill) const {
        return power_level < right_skill.power_level;
    }

    bool operator>(const Skill& right_skill) const {
        return power_level > right_skill.power_level;
    }

    bool operator<=(const Skill& right_skill) const {
        return power_level <= right_skill.power_level;
    }

    bool operator>=(const Skill& right_skill) const {
        return power_level >= right_skill.power_level;
    }

    bool operator==(const Skill& right_skill) {
        return std::tie(id, name, power_level)
             == std::tie(right_skill.id, right_skill.name, right_skill.power_level);
    }


};

// overwrite "<<" operator
inline std::ostream & operator<<(std::ostream &os, const Skill &skill) {
    os << "Skill: ( id: " << skill.id << ", name: " << skill.name << ", power level: " << skill.power_level << " )";
    return os;
}

inline Skill::Skill(int id, std::string name, int power_level) : id(id), name(name), power_level(power_level) {}



#endif //SKILLS_H
