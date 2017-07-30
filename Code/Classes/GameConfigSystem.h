//
//  GameConfigSystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/28.
//
//

#ifndef GameConfigSystem_h
#define GameConfigSystem_h


class GameConfigSystem
{
private:
    GameConfigSystem();
    ~GameConfigSystem();
public:
    static GameConfigSystem* getInstance();
    void SetGameSpeed(int _spped){GameSpeed = _spped;}
    int GetGameSpeed(){return GameSpeed;}
private:
    static GameConfigSystem* _instance;
private:
    int GameSpeed;
};

#endif /* GameConfigSystem_h */
