// main.js

require('jsb.js')

var MyLayer = cc.Layer.extend({
	init: function(){
		this._super();
		var background = cc.Sprite.create("images/HelloWorld.png");
		var size = background.getTexture().getContentSize();
		background.setPosition(cc.p(50, size.height / 2));
		this.addChild(background);
	},
	onEnter: function(){
		this._super();
		cc.log("jsb onEnter.");
	}
});

MyLayer.scene = function(){
	var scene = new cc.Scene();	
	var layer = new MyLayer();
	layer.init();
	scene.addChild(layer);

	// var sprite = cc.Sprite.create("images/CloseNormal.png");
	// sprite.setPosition(cc.p(20, 20));
	// scene.addChild(sprite, 1, 100);
	return scene;
};

//cc.Director.getInstance().runWithScene(MyLayer.scene());

cc.log("leafsoar v5 ~ jsb");

