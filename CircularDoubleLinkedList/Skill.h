//
// Created by Dominik on 22.10.2025.
//

#ifndef SKILLS_H
#define SKILLS_H
#include <string.h>
#include <string>
#include <time.h>

class Skill {
    int id = 0;
    std::string name;
    int power_level;

public:
    Skill(int id, std::string name, int power_level);

    static Skill* return_rand_skill();

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

inline Skill * Skill::return_rand_skill() {
    int new_id = rand() % 100;
    int new_power_level = rand() % 10;

    const char *possible_characters = "abcd";
    int length = strlen(possible_characters);
    int random_index = rand() % length;
    std::string new_name(1, possible_characters[random_index]);

    return new Skill(new_id, new_name, new_power_level);
}


#endif //SKILLS_H
