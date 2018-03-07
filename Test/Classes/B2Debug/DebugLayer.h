#ifndef __DebugLayer_H_
#define __DebugLayer_H_

#include "GLES-Render.h"

class DebugLayer : public cocos2d::Layer
{
private:
    GLESDebugDraw* _debugDraw;
    b2World *w;
    
public:

    virtual bool init();
    DebugLayer(b2World*);
    ~DebugLayer();
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
};


#endif //__DebugLayer_H_
