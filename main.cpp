#include <iostream>

#include "CircularDoubleLinkedList/CircularDoubleLinkedList.h"
#include "CircularDoubleLinkedList/Skill.h"

using namespace std;

int main() {

    CircularDoubleLinkedList<Skill>* skills_list = new CircularDoubleLinkedList<Skill>();

    Skill* long_sword_fighting_skill = new Skill(0, "long sword", 1);
    Skill* long_bow_fighting_skill = new Skill(1, "long bow", 1);
    Skill* sword_fighting_skill = new Skill(1, "sword", 1);

    skills_list->add_back(long_bow_fighting_skill);
    skills_list->add_back(sword_fighting_skill);
    skills_list->add_back(long_sword_fighting_skill);
    skills_list->del_back(false);

    std::cout << *skills_list->get_head() << std::endl;
    // std::cout << *skills_list->get_tail()->body << std::endl;
    //
    // std::cout << skills_list->get_size() << std::endl;

    delete skills_list;
    delete long_sword_fighting_skill;
    delete long_bow_fighting_skill;
    delete sword_fighting_skill;

    return 0;
}