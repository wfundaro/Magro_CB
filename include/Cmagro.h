#ifndef ENGINE_H
#define ENGINE_H
#include <Scene.h>
#include <SceneManager.h>
#include <memory>
#include <iostream>

class Magro
{
public :
    Magro(){}
    Magro(int _sx, int _sy, vtime _framerate, int _flag)
    : screen_width(_sx), screen_height(_sy), Framerate(_framerate), display_flag(_flag)
    {}
    ~Magro();
    void change_scene(Scene* &_scene, mg::transition _transition = mg::none, vtime _time = 1.0, mg::tweening _easing = mg::linear);
    int init(Scene* &_scene, int _sx, int _sy, vtime _framerate, int _flag);
    ALLEGRO_DISPLAY* get_display() const;
    float GetFps() const;
    float get_screen_width() const;
    float get_screen_height() const;
    Scene& get_current_scene() const;
private:
    float screen_width;
    float screen_height;
    float Framerate;
    int display_flag;
    ALLEGRO_DISPLAY* display = nullptr;
    std::unique_ptr<_mg::SceneManager> scenemanager = std::make_unique<_mg::SceneManager>(_mg::SceneManager());
    float Fps;
    void SetFps(float dt);
    int allegro_init();
    void run();
};
#endif // ENGINE_H
