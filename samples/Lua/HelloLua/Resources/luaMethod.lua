-- cclog
cclog = function(...)
    print(string.format(...))
end

cclog("lua method .");

local scene = CCDirector:getInstance():getRunningScene()
local label = scene:getChildByTag(100)
label:setScale(0.8)


