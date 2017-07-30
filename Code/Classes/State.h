//
//  State.h
//  NewGame
//
//  Created by 胡可 on 15/9/25.
//
//

#ifndef State_h
#define State_h

#include <stdio.h>

struct ROLE_STATE
{
    int Level;
    int HealthPoint_Max;                      //最大生命值
    int MagicPoint_Max;                       //最大魔法值
    int BuffTime_Max;                         //BUFF持续最大时间
    int ShieldValue_Max;                      //最大护盾值
    int AttackValue;                            //攻击值
    int DefenceValue;                           //防御值
    int RecoverHealthPointPerSecond;            //每秒恢复生命值
    int RecoverMagicPointPerSecond;             //每秒恢复魔法值
};



class State
{
public:
    static State* create(ROLE_STATE);
    State();
    ~State();
    virtual bool init(ROLE_STATE);
public:
    void UpdateLevel(int);
    void UpdateHP(int);                         //设置生命值
    void UpdateMP(int);                         //设置魔法值
    void UpdateBT(int);                         //设置Buff持续时间
    void UpdateSV(int);                         //设置护盾值
    void UpdateAttack(int);                     //设置攻击力
    void UpdateDefence(int);                    //设置防御值
    void UpdateReHp(int);                       //设置秒回生命值
    void UpdateReMp(int);                       //设置秒回魔法值
    void SetAttack(int);
public:
    inline int GetLevel(){return Level;}
    inline int GetHP(){return HealthPoint_Current;}                              //获取生命值
    inline int GetMP(){return MagicPoint_Current;}                              //获取魔法值
    inline int GetBT(){return BuffTime_Current;}                              //获取Buff持续时间
    inline int GetSV(){return ShieldValue_Current;}                              //获取护盾值
    inline int GetAttack(){return AttackValue;}                          //获取攻击力
    inline int GetDefence(){return DefenceValue;}                         //获取防御值
    inline int GetReHp(){return RecoverHealthPointPerSecond;}                            //获取秒回生命值
    inline int GetReMp(){return RecoverMagicPointPerSecond;}           //获取秒回魔法值
    inline int GetHpMax(){return HealthPoint_Max;}
    inline int GetMpMax(){return MagicPoint_Max;}
    inline int GetSvMax(){return ShieldValue_Max;}
    inline int GetBtMax(){return BuffTime_Max;}
private:
    /**固定属性**/
    int Level;                                  //等级
    int HealthPoint_Max;                      //最大生命值
    int MagicPoint_Max;                       //最大魔法值
    int BuffTime_Max;                         //BUFF持续最大时间
    int ShieldValue_Max;                      //最大护盾值
    /**变动属性**/
    int HealthPoint_Current;                  //当前生命值
    int MagicPoint_Current;                   //当前魔法值
    int BuffTime_Current;                     //当前BUFF时间
    int ShieldValue_Current;                  //当前护盾值
    int AttackValue;                            //攻击值
    int DefenceValue;                           //防御值
    int RecoverHealthPointPerSecond;            //每秒恢复生命值
    int RecoverMagicPointPerSecond;             //每秒恢复魔法值
};


#endif /* State_h */
