#include <Magro.h>
#include <Cmagro.h>
#include <memory>
#include <iostream>

namespace mg
{
    namespace
    {
        std::unique_ptr<Magro> magro(new Magro()); /// magro object
        //std::unique_ptr<Magro> magro = std::make_unique<Magro>();
    }

    int start(Scene* &_scene, int _sx, int _sy, vtime _framerate, int _flag)
    {
        int status = magro->init(_scene, _sx, _sy, _framerate, _flag);  /// enter loop Magro
        magro.reset(); /// Exit loop reset magro
        return status; /// return to main with status
    }

    void change_scene(Scene* &_scene, mg::transition _transition, vtime _time, mg::tweening _easing)
    {
        magro->change_scene(_scene, _transition, _time, _easing);
    }

    Scene& _get_current_scene()
    {
        return magro->get_current_scene();
    }

    float getFps()
    {
        return magro->GetFps();
    }
    ALLEGRO_DISPLAY* get_display()
    {
        return magro->get_display();
    }

    float screen_width()
    {
        return al_get_display_width(magro->get_display());
    }

    float screen_height()
    {
        return al_get_display_height(magro->get_display());
    }
}
