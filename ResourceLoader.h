//
//  ResourceLoader.h
//  FeebleEscape
//
//  Created by namnguyen on 11/29/14.
//
//

#ifndef __FeebleEscape__ResourceLoader__
#define __FeebleEscape__ResourceLoader__

#include <stdio.h>
#include "cocos2d.h"
#include <iostream>
#include <functional>
#include <vector>
class ResourceLoader
{
public:
    ResourceLoader();
    ~ResourceLoader();
    static ResourceLoader* getInstance();
    CC_SYNTHESIZE_READONLY(int, m_total, Total);
    CC_SYNTHESIZE_READONLY(int, m_current, Current);
    CC_SYNTHESIZE_READONLY(bool, m_isBusy, IsBusy);
    void loadTexture(std::vector<std::string>_texture, std::function<void(bool success)>onFinish);
    
    void increase();
    void done();
private:
    std::vector<std::string> m_textures;
    std::function<void(bool success)> m_onFinish;
};

#endif /* defined(__FeebleEscape__ResourceLoader__) */
