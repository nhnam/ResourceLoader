ResourceLoader
==============

Texture Resoure Loader multithread

using :
Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    std::vector<std::string> texture;
    texture.push_back("texture_01");
    texture.push_back("texture_02");
    texture.push_back("texture_03");
    texture.push_back("texture_04");
    texture.push_back("texture_05");
    texture.push_back("texture_06");
    texture.push_back("texture_08");
    texture.push_back("texture_09");
    texture.push_back("texture_10");
    texture.push_back("texture_11");
    ResourceLoader::getInstance()->loadTexture(texture, [this, visibleSize, origin](bool success)
    {
        auto spr = Sprite::createWithSpriteFrameName(“a_sprite_frame.png");
        this->addChild(spr);
        spr->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    });

