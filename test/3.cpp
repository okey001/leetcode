/*
    IInteract               virtual func: "onAction", "onTalk"
      / | \
     /  |  \Inherit
    /   |   \
   /    |    \
Door   NPC  Monster         implement "onAction" or "onTalk" or both

    IMoveable               virtual func: "onMoveToNorth", "onMoveToSouth", "onMoveToEast", "onMoveToWest"
        |
        |Inherit
        |   
        |    
      Player                implement "onAction" or "onTalk" or both
*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;

class IMoveable{
public:
    virtual bool onMoveToNorth(){return false;}
    virtual bool onMoveToSouth(){return false;}
    virtual bool onMoveToEast(){return false;}
    virtual bool onMoveToWest(){return false;}
};

class IInteract{
public:
    virtual bool onAction(){return false;}
    virtual bool onTalk(){return false;}
};

class Player : public IMoveable, public IInteract{
    //implement move interface
};

class Door: public IInteract{
public:
    bool onAction() override{
        cout << "Door Open!" << endl;
        return true;
    }
};

class NPC: public IInteract{
public:
    bool onTalk() override{
        cout << "NPC Say Something!" << endl;
        return true;
    }
};

class Monster: public IInteract{
public:
    bool onAction() override{
        cout << "Monster Hurt!" << endl;
        return true;
    }
};

IInteract* getTarget(){
    return new NPC();  // debug
}

Player* getPlayer(){
    static Player player;
    return &player;  // debug
}

void HandleCmd(string cmd){
    IInteract *target = getTarget();
    Player *player = getPlayer();
    if (cmd == "N") {
        player->onMoveToNorth();
    }
    //... other cmd
    else if (cmd == "talk") {
        bool result = target->onTalk();
        if (result) player->onTalk();
    }
    else if (cmd == "action"){
        bool result = target->onAction();
        if (result) player->onAction();
    }
    
}

int main(){
    string cmd;
    while(true){
        cin >> cmd;
        HandleCmd(cmd);
    }
    return 0;
}