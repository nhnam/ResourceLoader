//
//  ResourceLoader.cpp
//  FeebleEscape
//
//  Created by namnguyen on 11/29/14.
//
//

#include "ResourceLoader.h"
#include <thread>
#include <mutex>

using namespace cocos2d;

static ResourceLoader* ins_resLoader = nullptr;
static std::mutex ins_mutex;

ResourceLoader::ResourceLoader():m_total(0), m_current(0),m_isBusy(false){
    
}

ResourceLoader::~ResourceLoader()
{
    
}

ResourceLoader* ResourceLoader::getInstance()
{
    if(ins_resLoader==nullptr){
        ins_resLoader = new ResourceLoader();
    }
    return ins_resLoader;
}

void ResourceLoader::loadTexture(std::vector<std::string>_texture, std::function<void(bool success)>onFinish)
{
    if(m_isBusy)
    {
        cocos2d::log("Loader is busy");
    }else
    {
        for(const auto &obj : _texture){
            m_textures.push_back(obj);
        }
        m_total = m_textures.size();
        m_current = 0;
        m_isBusy = true;
        m_onFinish = onFinish;
        
        int i = 0;
        int max = 3;
        int total = 0;
        
        while(total < m_total)
        {
            std::thread t = std::thread([&i, max, total, this]()
            {
                while ((i<max) && (total+i<m_total))
                {
                    std::string png = StringUtils::format("%s.png",m_textures.at(total+i).c_str());
                    std::string plist = StringUtils::format("%s.plist",m_textures.at(total+i).c_str());
                    cocos2d::log("//== Load: %s, %s", png.c_str(), plist.c_str());
                    Director::getInstance()->getTextureCache()->addImageAsync(png, [this,plist](Texture2D* text){
                        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
                        this->increase();
                    });
                    i++;
                }
            });
            t.join();
            total += i;
            i = 0;
        }
    }
}

void ResourceLoader::increase()
{
    ins_mutex.lock();
    m_current ++;
    if(m_current == m_total){
        this->done();
    }
    ins_mutex.unlock();
}

void ResourceLoader::done()
{
    m_isBusy = false;
    m_onFinish(true);
}