#include <iostream>

#include "CircularDoubleLinkedList/CircularDoubleLinkedList.h"
#include "CircularDoubleLinkedList/Skill.h"

using namespace std;

int main() {
    CircularDoubleLinkedList<Skill>* skills_list = new CircularDoubleLinkedList<Skill>;

    Skill* long_sword_fighting_skill = new Skill(0, "long sword", 0);
    Skill* long_bow_fighting_skill = new Skill(1, "long bow", 1);
    Skill* sword_fighting_skill = new Skill(2, "sword", 2);
    Skill* axe_fighting_skill = new Skill(3, "axe", 3);

    skills_list->add_back(long_sword_fighting_skill);
    skills_list->add_back(long_bow_fighting_skill);
    // skills_list->add_back(axe_fighting_skill);

    // cout << *(*skills_list).get_head();

    skills_list->print_all_nodes();

    // skills_list->setValue(1, axe_fighting_skill);

    // skills_list->print_all_nodes();

    // cout << "find sword skill: " << endl;
    // std::cout << *(skills_list->find_node_with_element(sword_fighting_skill)) << endl;

    // skills_list->del_node_with_element(sword_fighting_skill);
    // cout << "after deleting sword skill:" << endl;

    // for (int i = 0; i < skills_list->get_size(); i++) {
    //     std::cout << *(*skills_list)[i] << endl;
    // }

    cout << "\nafter adding in ASC order sword skill:" << endl;
    skills_list->add_in_order(sword_fighting_skill, ASC);

   skills_list->print_all_nodes();

    delete skills_list;
    // delete long_sword_fighting_skill;
    // delete long_bow_fighting_skill;
    delete sword_fighting_skill;

    return 0;
}