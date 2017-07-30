//
//  UISystem.h
//  NewGame
//
//  Created by 胡可 on 15/10/14.
//
//

#ifndef UISystem_h
#define UISystem_h



class UISystem
{
private:
    UISystem();
    ~UISystem();
public:
    static UISystem* getInstance();
    void OpenTopStateBar();
    void OpenBottomStateBar();
    void CloseTopStateBar();
    void CloseBottomStateBar();
    void OpenPlayerConfig();
    void ClosePlayerConfig();
    inline bool getTopStateBarControl(){return _TopStateBarControl;}
    inline bool getBottomStateBarControl(){return _BottomStateBarControl;}
    inline void setBottomStateBarControl(bool _bool){_BottomStateBarControl = _bool;}
    inline void setTopStateBarControl(bool _bool){_TopStateBarControl = _bool;}
    inline void setBottomStateCanMove(bool _bool){_BottomStateCanMove = _bool;}
    inline bool getBottomStateCanMove(){return _BottomStateCanMove;}
    inline void setMapCanControl(bool _bool){_MapCanControl = _bool;}
    inline bool getMapCanControl(){return _MapCanControl;}
    inline void SetItemLayerOpen(bool _bool){_ItemLayerOpen = _bool;}
    inline bool getItemLayerOpen(){return _ItemLayerOpen;}
private:
    static UISystem* _instance;
    bool _TopStateBarControl;
    bool _BottomStateBarControl;
    bool _BottomStateCanMove;
    bool _MapCanControl;
    bool _ItemLayerOpen;
};

#endif /* UISystem_h */
