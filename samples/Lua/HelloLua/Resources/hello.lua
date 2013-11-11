-- cclog
cclog = function(...)
    print(string.format(...))
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    ---------------

    local visibleSize = CCDirector:getInstance():getVisibleSize()
    local origin = CCDirector:getInstance():getVisibleOrigin()

    -- create farm
    local function createLayerFarm()
        local layerFarm = CCLayer:create()

        -- add in farm background
        local bg = CCSprite:create("images/HelloWorld.png")
        bg:setPosition(origin.x + visibleSize.width - 50, origin.y + visibleSize.height / 2)
        layerFarm:addChild(bg)

		local function onEnterOrExit(tag)
		   if tag == "enter" then
			  cclog("lua onEnter.");
		   -- elseif tag == "exit" then

		   end
		end

		layerFarm:registerScriptHandler(onEnterOrExit)

        return layerFarm
    end

    -- run scene 
    -- local sceneGame = CCScene:create()
    -- sceneGame:addChild(createLayerFarm())
    -- CCDirector:getInstance():runWithScene(sceneGame)

    cclog("leafsoar v5 ~ lua");
end

xpcall(main, __G__TRACKBACK__)
