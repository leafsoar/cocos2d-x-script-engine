//
//  HelloLeafsoar.h
//  samples
//
//  Created by leafsoar on 04/11/2013.
//
//

#ifndef __samples__HelloLeafsoar__
#define __samples__HelloLeafsoar__

#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"

#include "ScriptingCore.h"
#include "generated/jsb_cocos2dx_auto.hpp"
#include "generated/jsb_cocos2dx_extension_auto.hpp"
#include "jsb_cocos2dx_extension_manual.h"
#include "cocos2d_specifics.hpp"
#include "js_bindings_ccbreader.h"
#include "js_bindings_system_registration.h"
#include "js_bindings_chipmunk_registration.h"
#include "jsb_opengl_registration.h"

#include "cocos2d.h"

USING_NS_CC;

class HelloLeafsoar: public Layer{
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(HelloLeafsoar);
    
    virtual void onEnter() override;
    virtual void onExit() override;
};

class GlobalSchedule: public Object{
public:
    static GlobalSchedule* getInstance();
    // 开始全局定时器 fInterval: 时间间隔 ; fDelay: 延迟运行
    static void start(float fInterval = 0.0f, float fDelay = 0.0f);
    // 停止全局定时器
    static void stop();
    // 全局定时器暂停
    static void pause();
    // 全局定时器暂停恢复
    static void resume();
    
    // 全局定时器主逻辑实现
    void globalUpdate(float dt);
    
    int count = 0;
    
    
    ScriptingCore* jsbEngine;
    LuaEngine* luaEngine;

    
private:
    // 构造函数私有化，只能通过 start 来启用全局定时器
    GlobalSchedule(float fInterval, float fDelay);
    ~GlobalSchedule();
    
    // 静态变量保持单例
    static GlobalSchedule* m_pSchedule;
};

#endif /* defined(__samples__HelloLeafsoar__) */
