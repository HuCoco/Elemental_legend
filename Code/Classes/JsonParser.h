//
//  JsonParser.h
//  NewGame
//
//  Created by 胡可 on 15/11/10.
//
//

#ifndef JsonParser_h
#define JsonParser_h
#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/filestream.h"
#include "json/prettywriter.h"

using namespace rapidjson;

//
//  章节数据
//
#define CHAPTER_JSON "json/chapter.json"
#define CHAPTER_1 "CHAPTER_1"
#define CHAPTER_2 "CHAPTER_2"
#define CHAPTER_3 "CHAPTER_3"
#define CHAPTER_4 "CHAPTER_4"
#define CHAPTER_5 "CHAPTER_5"
#define CHAPTER_TITLE "CHAPTER_TITLE"
#define CHAPTER_INFO "CHAPTER_INFO"
struct CHAPTER_INFO_DATA
{
    std::string ChapterTitle;
    std::string ChapterInfo;
};
//
//

//
//  关卡位置数据
//
#define MAP_1_GATE_POS_JSON "json/map1_gate_pos.json"
#define MAP_2_GATE_POS_JSON "json/map2_gate_pos.json"
#define GATE__NUM "gate%d"
#define WHICH_MAP "map"
#define POS_X "x"
#define POX_Y "y"
struct GATE_POS_DATA
{
    int InWhichMap;
    int WidthOdd;
    int HeightOdd;
};
//
//
//

//
//  任务数据
//
#define MISSION_JSON "json/mission.json"
#define MISSION__NUM "mission%d"
#define MISSION_CUR "Cur"
#define MISSION_INFO "Info"
#define MISSION_VALUE "Value"
#define MISSSION_TAG "Tag"
struct MISSION_DATA
{
    std::string Cur;
    int Value;
    std::string Info;
    int Tag;
};
//
//  技能数据
//
#define FIRE_JSON "json/fire.json"
#define WATER_JSON "json/water.json"
#define THUNDER_JSON "json/thunder.json"
#define WIND_JSON "json/wind.json"
#define SELECT_FIRE 1
#define SELECT_WATER 2
#define SELECT_THUNDER 3
#define SELECT_WIND 4
#define SKILL__NUM "Skill%d"
#define PALYER_SKILL_NAME "Name"
#define PALYER_SKILL_COST "Cost"
#define PALYER_SKILL_INFO "Info"

struct PLAYER_SKILL_DATA
{
    std::string Name;
    std::string Cost;
    std::string Info;
};



//
//  关卡数据
//
#define TRAIL_JONS "json/trail.json"
#define CHAPTER_1_GATE_JSON "json/chapter1_gates.json"
#define CHAPTER_2_GATE_JSON "json/chapter2_gates.json"
#define CHAPTER_3_GATE_JSON "json/chapter3_gates.json"
#define CHAPTER_4_GATE_JSON "json/chapter4_gates.json"
#define CHAPTER_5_GATE_JSON "json/chapter5_gates.json"
#define MONSTER__NUM "monster%d"
#define MONSTER_LEVEL "level"
#define MONSTER_HP "hp"
#define MONSTER_ATK "atk"
#define MONSTER_DEF "def"
#define MONSTER_SPEED "speed"
#define MONSTER_ATKNUM "atknum"
#define MONSTER_DEFNUM "defnum"
#define MONSTER_SPENUM1 "spenum1"
#define MONSTER_SPENUM2 "spenum2"
#define MONSTER_SPENUM3 "spenum3"
#define MONSTER_NAME "Name"
#define MONSTER_INFO "Info"
#define MONSTER_TYPE "Type"
struct GATE_MONSTER_DATA
{
    int Level;
    int Hp;
    int ATK;
    int DEF;
    int SPEED;
    int ATKNUM;
    int DEFNUM;
    int SPENUM1;
    int SPENUM2;
    int SPENUM3;
    std::string Name;
    std::string Info;
    int Type;
};
//
//
//

//
//  属性数据
//
#define ATTR_JSON "json/attr.json"
#define ATTR__NUM "Attr%d"
struct ATTR_DATA
{
    std::string attr;
    
};
//
//


//
// 装备属性
//
#define ITEM_JSON "json/item.json"
#define ITEM_NAME "name"
#define ITEM_INFO "info"
#define ITEM_SUIT "suit"
#define ITEM_MIN "minvalue"
#define ITEM_MAX "maxvalue"
struct ITEM_BASE_DATA
{
    std::string name;
    std::string info;
    int suit;
    int min;
    int max;
};

//
//
//


class JsonParser
{
private:
    JsonParser();
    ~JsonParser();
public:
    static JsonParser* getInstance();
    std::vector<CHAPTER_INFO_DATA>* GetChapterData();
    std::vector<GATE_POS_DATA>* GetGatePosData(int _gate);
    std::vector<MISSION_DATA>* GetMissionData();
    GATE_MONSTER_DATA* GetMonsterData(int _gate,int _num);
    std::vector<PLAYER_SKILL_DATA>* GetPlayerSkillData(int _type);
    std::vector<ATTR_DATA>* GetAttrData();
    ITEM_BASE_DATA* GetItenBaseData(const std::string& _key);
    GATE_MONSTER_DATA* GetTrailData(int num);
public:
    
private:
    static JsonParser* _instance;
    
};




#endif /* JsonParser_h */
