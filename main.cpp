#include <iostream>

#include "DoubleLinkedList/DoubleLinkedList.h"
#include "DoubleLinkedList/Skill.h"

using namespace std;

int main() {

    Skill *sword_skill = new Skill(1, "sword skill", 0);
    Skill *bow_skill = new Skill(2, "bow skill", 0);

    DoubleLinkedList<Skill>* list = new DoubleLinkedList<Skill>;

    list->addFront(sword_skill);
    list->addFront(bow_skill);

    list->rmvBack();
    list->rmvBack();

    if (list->getHead()) cout << *list->getHead()->value << endl; else cout<<"NULL"<<endl;

    delete sword_skill;
    delete bow_skill;

    return 0;
}