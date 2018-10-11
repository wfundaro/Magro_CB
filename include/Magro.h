#ifndef MG_H
#define MG_H
#include <Scene.h>
#include <Easing.h>
#include <Sprite.h>
#include <SpriteSheet.h>
#include <iostream>

namespace mg
{
    int start(Scene* &_scene, int _sx, int _sy, vtime _framerate = 60.0, int _flag = ALLEGRO_WINDOWED);
    float getFps();
    void change_scene(Scene* &_scene, mg::transition _transition = mg::none, vtime _time = 1.0, mg::tweening _easing = mg::linear);
    ALLEGRO_DISPLAY* get_display();
    float screen_width();
    float screen_height();
    void close();
    Scene& _get_current_scene();
}

#endif // MG_H
