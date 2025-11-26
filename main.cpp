#include <iostream>

#include "CircularDoubleLinkedList/CircularDoubleLinkedList.h"
#include "CircularDoubleLinkedList/Skill.h"

using namespace std;

int main() {
    CircularDoubleLinkedList<Skill>* skills_list = new CircularDoubleLinkedList<Skill>;

    Skill* skill_1 = new Skill(0, "long sword", 0);
    Skill* skill_2 = new Skill(1, "long bow", 1);
    Skill* skill_3 = new Skill(2, "sword", 2);
    Skill* skill_4 = new Skill(3, "axe", 3);

    // Simple tests for all methods

    // print list without any nodes
    skills_list->print_all_nodes_simple();

    cout << "\nadd two el at front: " << endl;
    skills_list->add_front(skill_1);
    skills_list->add_front(skill_2);
    skills_list->print_all_nodes_simple();

    cout << "\nadd one el at back: " << endl;
    skills_list->add_back(skill_3);
    skills_list->print_all_nodes_simple();

    cout << "\ndelete at front: " << endl;
    skills_list->del_front(false);
    skills_list->print_all_nodes_simple();

    cout << "\ndelete at back: " << endl;
    skills_list->del_back(false);
    skills_list->print_all_nodes_simple();

    cout << "\ndelete at back when head == tail: " << endl;
    skills_list->del_back(false);
    skills_list->print_all_nodes_simple();

    cout << "\ndelete at front when empty: " << endl;
    skills_list->del_front(false);
    skills_list->print_all_nodes_simple();

    cout << "\ndelete at back when empty: " << endl;
    skills_list->del_back(false);
    skills_list->print_all_nodes_simple();

    try {
        cout << "\nprint what's at index 0 when empty: " << endl;
        cout << *(*skills_list)[0];
    } catch (std::out_of_range &e) {
        cout << "Caught exception: " << e.what() << "\n";
    }

    skills_list->add_front(skill_1);
    skills_list->add_front(skill_2);
    try {
        cout << "\nprint what's at index 0 when not empty: " << endl;
        cout << *(*skills_list)[0];
    } catch (std::out_of_range &e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "\nList state: \n";
    skills_list->print_all_nodes_simple();

    skills_list->del_back(false);
    skills_list->del_back(false);
    try {
        cout << "\tChange what's at index 0 when empty: " << endl;
        (*skills_list)[0] = skill_3;
    } catch (std::out_of_range &e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "List state: ";
    skills_list->print_all_nodes_simple();

    skills_list->add_front(skill_1);
    cout << "\n\nList state before changing index 0: ";
    skills_list->print_all_nodes_simple();
    try {
        cout << "\nChange what's at index 0 when not empty " << endl;
        (*skills_list)[0] = skill_3;
    } catch (std::out_of_range &e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "List state after: \n";
    skills_list->print_all_nodes_simple();

    skills_list->clear_list();

    delete skills_list;

    return 0;
}