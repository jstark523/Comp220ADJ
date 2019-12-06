//
// Created by Jrsta on 12/5/2019.
//

#include <iostream>
#include "LinkedNode.h"
#include "Song.h"

void nodeTest(){
    std::cout<<"Testing LinkedNode"<<std::endl;
    std::cout<<""<<std::endl;
    Song song1 = Song("Muse", "Showbiz",60);
    LinkedNode* test1 = new LinkedNode(song1);
    std::cout<<""<<std::endl;

    //Testing Getters/Node holding Songs/Song initialized with parameter heavy constructor
    std::cout<<""<<std::endl;
    std::cout<<"Should print Muse, Showbiz, 60, 0 "<<std::endl;
    std::cout<< test1->getItem().getArtist() + ", " + test1->getItem().getTitle() + ", " + std::to_string(test1->getItem().getDuration()) + ", "  + std::to_string(test1->getItem().getPlayCount()) <<std::endl;

    Song song2 = Song("RexOrangeCounty*10/10*30");
    LinkedNode* test2 = new LinkedNode(song2);

    std::cout<<""<<std::endl;
    //Testing Getters/Node holding Songs/Song initialized with Single String parameter Constructor
    std::cout<<"Should print RexOrangeCounty, 10/10, 30, 0 "<<std::endl;
    std::cout<< test2->getItem().getArtist() + ", " + test2->getItem().getTitle() + ", " + std::to_string(test2->getItem().getDuration()) + ", "  + std::to_string(test2->getItem().getPlayCount()) <<std::endl;

    test2->setItem(song1);

    std::cout<<""<<std::endl;
    //Testing setItem

    std::cout<<"Should print Muse, Showbiz, 60, 0"<<std::endl;
    std::cout<< test2->getItem().getArtist() + ", " + test2->getItem().getTitle() + ", " + std::to_string(test2->getItem().getDuration()) + ", "  + std::to_string(test2->getItem().getPlayCount()) <<std::endl;

    test2->setItem(song2);
    test1->setNext(test2);

    //Testing setNext and getNext
    std::cout<<""<<std::endl;
    std::cout<<"Should print RexOrangeCounty"<<std::endl;
    std::cout<< test1->getNext()->getItem().getArtist() << std::endl;
    std::cout<<""<<std::endl;

    //Testing Copy Constructor
    std::cout<<"Should print Muse"<<std::endl;
    LinkedNode* copyNode = new LinkedNode(song1);
    LinkedNode copiedNode = LinkedNode(*copyNode);
    std::cout<<copiedNode.getItem().getArtist()<<std::endl;

    std::cout<<""<<std::endl;
    std::cout<<"Linked Node Tests Complete"<<std::endl;
}

int main(){
    nodeTest();


    return 0;
}

