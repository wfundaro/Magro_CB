#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <Scene.h>
#include <Easing.h>
#include <iostream>

class Magro;

namespace _mg
{
    class SceneManager
    {
        public:
            SceneManager(){};
            void change_scene(Scene* &_scene, mg::transition _transition = mg::none, vtime _time = 1.0, mg::tweening _easing = mg::linear);
            void draw_scene();
            bool update_scene(vtime _dt);
            bool get_transition_on() const;
            void update_transition(vtime _dt);
            void destroy();
            Scene* get_current_scene() const { return current_scene;}
        private:
            Scene* new_scene = nullptr;
            Scene* current_scene = nullptr;
            mg::transition trans_mode;
            mg::tweening scene_easing;
            vtime duration_transition;
            vtime dtime_transition;
            bool transition_on = false;
            ALLEGRO_BITMAP* image_transition = nullptr;
            vtime easing_value(vtime _time, float _origin, float _end, vtime _duration);
    };
}


#endif // SCENEMANAGER_H
