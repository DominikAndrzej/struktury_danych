#include <iostream>

#include "CircularDoubleLinkedList/CircularDoubleLinkedList.h"
#include "CircularDoubleLinkedList/Skill.h"

using namespace std;

int main() {
    CircularDoubleLinkedList<Skill>* skills_list = new CircularDoubleLinkedList<Skill>;

    Skill* long_sword_fighting_skill = new Skill(0, "long sword", 2);
    Skill* long_bow_fighting_skill = new Skill(1, "long bow", 2);
    Skill* sword_fighting_skill = new Skill(2, "sword", 1);
    Skill* axe_fighting_skill = new Skill(3, "axe", 2);

    skills_list->add_back(long_sword_fighting_skill);
    skills_list->add_back(long_bow_fighting_skill);
    skills_list->add_back(sword_fighting_skill);

    skills_list->setValue(1, axe_fighting_skill);

    std::cout << *(*skills_list)[0] << endl;
    std::cout << *(*skills_list)[1] << endl;
    std::cout << *(*skills_list)[2] << endl;

    std::cout << *(skills_list->find_node_with_element(sword_fighting_skill)->body);

    skills_list->del_node_with_element(sword_fighting_skill);

    delete skills_list;
    // delete long_sword_fighting_skill;
    // delete long_bow_fighting_skill;
    delete sword_fighting_skill;

    return 0;
}