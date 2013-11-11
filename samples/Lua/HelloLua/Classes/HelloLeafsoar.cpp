//
//  HelloLeafsoar.cpp
//  samples
//
//  Created by leafsoar on 04/11/2013.
//
//

#include "HelloLeafsoar.h"
#include "SimpleAudioEngine.h"
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


Scene* HelloLeafsoar::scene(){
    auto scene = Scene::create();
    auto layer = HelloLeafsoar::create();
    scene->addChild(layer);
    return scene;
}

bool HelloLeafsoar::init(){
    auto bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        CCLOG("leafsoar v5 ~ cpp");
        
        auto winSize = Director::getInstance()->getWinSize();
        
        auto background = Sprite::create("images/HelloWorld.png");
        background->setPosition(Point(winSize.width / 2, winSize.height / 2));
        addChild(background);
        

        bRet = true;
    } while (0);
    
    return bRet;
}

void HelloLeafsoar::onEnter(){
    Layer::onEnter();
    CCLOG("cpp onEnter .");
}

void HelloLeafsoar::onExit(){
    Layer::onExit();
}


#define SCHEDULE Director::getInstance()->getScheduler()

GlobalSchedule* GlobalSchedule::m_pSchedule = NULL;

GlobalSchedule::GlobalSchedule(float fInterval, float fDelay) {
    CCLOG("GlobalSchedule()");


    SCHEDULE->scheduleSelector(schedule_selector(GlobalSchedule::globalUpdate), this, fInterval, false);
    m_pSchedule = this;
}

GlobalSchedule::~GlobalSchedule() {
    CCLOG("GlobalSchedule().~()");
    
    SCHEDULE->unscheduleSelector(schedule_selector(GlobalSchedule::globalUpdate), this);
}

GlobalSchedule* GlobalSchedule::getInstance(){
    return m_pSchedule;
}

void GlobalSchedule::globalUpdate(float dt) {
    // 这里写全局定时器的逻辑处理代码
    CCLOG("global update");
//    Director::getInstance()->popScene();
    count ++;

    auto scene = Director::getInstance()->getRunningScene();
    LabelTTF* label = (LabelTTF*)scene->getChildByTag(100);
    if (!label){
        label = LabelTTF::create("一叶 v 5~", "", 24);
        label->setPosition(Point(250, 300));
        label->setColor(Color3B::BLACK);
        scene->addChild(label, 1, 100);
    } else {
        if (count % 3 == 0)
            label->setScale(1);
        else if (count % 3 == 1)
            ScriptingCore::getInstance()->runScript("jsbMethod.js");
        else if (count %3 == 2)
            LuaEngine::getInstance()->executeScriptFile("luaMethod.lua");
    }
}

void GlobalSchedule::start(float fInterval, float fDelay) {
    CCLOG("GlobalSchedule().start()");
    new GlobalSchedule(fInterval, fDelay);
}

void GlobalSchedule::stop() {
    CCLOG("GlobalSchedule().stop()");
    
    CC_SAFE_DELETE(m_pSchedule);
}

void GlobalSchedule::pause() {
    CCLOG("GlobalSchedule().pause()");
    
    SCHEDULE->pauseTarget(m_pSchedule);
}

void GlobalSchedule::resume() {
    CCLOG("GlobalSchedule().resume()");
    
    SCHEDULE->resumeTarget(m_pSchedule);
}