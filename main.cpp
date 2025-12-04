#include <cmath>
#include <iostream>

#include "CircularDoubleLinkedList/CircularDoubleLinkedList.h"
#include "CircularDoubleLinkedList/Skill.h"
#include "DynamicArray/DynamicArray.h"

using namespace std;

void simple_test_CircularDoubleLinkedList() {
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

    skills_list->clear_list(false);

    cout << "List state: \n";
    skills_list->print_all_nodes_simple();
    cout << "find node by element Skill(3, 'axe', 3) when element doesn't exist: \n\tfound node body: ";
    if (skills_list->find_node_by_element(skill_4) != nullptr) {
        cout << *skills_list->find_node_by_element(skill_4)->body;
    } else {
        cout << "element doesn't exists\n";
    }

    skills_list->add_back(skill_1);
    skills_list->add_back(skill_2);
    skills_list->add_back(skill_4);

    cout << "List state: \n";
    skills_list->print_all_nodes_simple();
    cout << "find node by element Skill(3, 'axe', 3): \n\tfound node body: ";
    cout << *skills_list->find_node_by_element(skill_4)->body;

    cout << "\n\nList state: \n";
    skills_list->print_all_nodes_simple();
    cout << "add element Skill(2, 'sword', 2) in ascending order.\n";
    skills_list->add_in_order(skill_3, ASC);
    skills_list->print_all_nodes_simple();

    delete skills_list;
}
void test_circularity_of_list() {
    CircularDoubleLinkedList<Skill> *skills_list = new CircularDoubleLinkedList<Skill>;

    Skill* skill_1 = new Skill(0, "long sword", 0);
    Skill* skill_2 = new Skill(1, "long bow", 1);
    Skill* skill_3 = new Skill(2, "sword", 2);
    Skill* skill_4 = new Skill(3, "axe", 3);

    skills_list->add_back(skill_1);
    skills_list->add_back(skill_2);
    skills_list->add_back(skill_3);
    skills_list->add_back(skill_4);

    Node<Skill> *temp_node = skills_list->get_head();
    for (int i=0; i<24; i++) {
        cout << *temp_node->body << endl;
        temp_node = temp_node->next;
    }

    delete skills_list;
}
void main_test_CircularDoubleLinkedList() {
    const time_t SEED = time(NULL);
    const int MAX_ORDER = 4;

    CircularDoubleLinkedList<Skill> *skills_list = new CircularDoubleLinkedList<Skill>;

    for (int o=1; o<= MAX_ORDER; o++) {
        const int n = pow(10,o);
        const int m = n/4;

        cout << "Proba nr. " << o << endl;

        // add n objects
        srand(SEED);
        clock_t t1 = clock();
        for (int i=0; i<n; i++) {
            Skill* new_skill = Skill::return_rand_skill();
            skills_list->add_in_order(new_skill, ASC);
        }
        clock_t t2 = clock();
        double time = double(t2 - t1) / CLOCKS_PER_SEC * 1000;

        skills_list->print_list_very_simple();
        cout << "Pomiar czasu dla dodania " << n << " elementow: " << time << " ms (metoda add_in_order())" << endl;

        // return element from given random index
        t1 = clock();
        for (int i=0; i<n; i++) {
            int rand_index = rand() % n;
            *(*skills_list)[rand_index];
        }
        t2 = clock();
        time = double(t2 - t1) / CLOCKS_PER_SEC * 1000;
        cout << "\nPomiar czasu dla zwrocenia elementu z " << m << " losowych indeksow: " << time << " ms (lista[losowy_indeks])\n" << endl;

        // search and delete m objects
        t1 = clock();
        for (int i=0; i<m; i++) {
            Skill* skill_to_del = Skill::return_rand_skill();
            skills_list->del_node_by_element(skill_to_del);
        }
        t2 = clock();
        time = double(t2 - t1) / CLOCKS_PER_SEC * 1000;

        skills_list->print_list_very_simple();
        cout << "Pomiar czasu dla wyszukania i usuniecia " << m << " elementow: " << time << " ms (metoda del_node_by_element())" << endl;
    }
}

int main() {
    DynamicArray<Skill> dynamicArray;

    Skill* skill_1 = new Skill(0, "long sword", 0);
    Skill* skill_2 = new Skill(1, "long bow", 1);
    Skill* skill_3 = new Skill(2, "sword", 2);
    Skill* skill_4 = new Skill(3, "axe", 3);

    cout << "1. step\n";
    dynamicArray.print_list_simple();

    cout << "2. step\n";
    dynamicArray.push_back(*skill_1);
    dynamicArray.print_list_simple();

    cout << "3. step - extend capacity\n";
    dynamicArray.push_back(*skill_2);
    dynamicArray.print_list_simple();

    cout << "4. step - extend capacity v2\n";
    dynamicArray.push_back(*skill_3);
    dynamicArray.print_list_simple();

    cout << "5. step - add new element\n";
    dynamicArray.push_back(*skill_4);
    dynamicArray.print_list_simple();

    return 0;
}
