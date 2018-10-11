#include "Cmagro.h"
#include <memory>

void Magro::run()
{
    bool end_of_game = false;
    vtime T_refresh = Framerate;
    if(T_refresh > 0.0)
    {
        T_refresh = 1.0 / Framerate;
    }
    else{
        T_refresh = 0.001;
    }
    ALLEGRO_TIMER *Timer_refresh = al_create_timer(T_refresh);
    ALLEGRO_EVENT_QUEUE *mg_event_queue = al_create_event_queue();
    al_register_event_source(mg_event_queue, al_get_timer_event_source(Timer_refresh));
    al_register_event_source(mg_event_queue, al_get_display_event_source(display));
    al_start_timer(Timer_refresh);
    ALLEGRO_EVENT events;
    vtime start_frame;
    vtime dt = 0.0;
    do
    {
        start_frame = al_get_time();
        al_wait_for_event(mg_event_queue, &events);
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            //exit(0);
            end_of_game = true;
        }
        if(events.type == ALLEGRO_EVENT_TIMER)
        {
            if(scenemanager->get_transition_on())
            {
                scenemanager->update_transition(dt);
            }else
            {   ///update
                end_of_game = scenemanager->update_scene(dt);
                ///draw
                scenemanager->draw_scene();
            }
            al_flip_display();
        }
        dt = al_get_time() - start_frame;
        SetFps(dt);
    }while(!end_of_game);
    al_destroy_timer(Timer_refresh);
    al_destroy_event_queue(mg_event_queue);
}

float Magro::GetFps() const
{
    return Fps;
}

void Magro::SetFps(vtime _dt)
{
    Fps = 1/_dt;
}

void Magro::change_scene(Scene* &_scene, mg::transition _transition, vtime _time, mg::tweening _easing)
{
    scenemanager->change_scene(_scene, _transition, _time, _easing);
}

ALLEGRO_DISPLAY* Magro::get_display() const
{
    return display;
}

float Magro::get_screen_width() const
{
    return screen_width;
}

float Magro::get_screen_height() const
{
    return screen_height;
}

Scene& Magro::get_current_scene() const
{
    return *scenemanager->get_current_scene();
}

Magro::~Magro()
{
    scenemanager->destroy();
    scenemanager.reset();
}

int Magro::allegro_init()
{
    if (!al_init())
    {
        return mg::AL_INIT;
    }
    #ifdef INSTALL_KEYBOARD
        if (!al_install_keyboard())
        {
            return mg::AL_INSTALL_KEYBOARD;
        }
    #endif // INSTALL_KEYBOARD
    #ifdef INSTALL_MOUSE
        if (!al_install_mouse())
        {
            return mg::AL_INSTALL_MOUSE;
        }
    #endif // INSTALL_MOUSE
    #ifdef IMAGE_ADDON
        if(!al_init_image_addon())
        {
            return mg::AL_IMAGE_ADDON;
        }
    #endif // IMAGE_ADDON
    #ifdef FONT_ADDON
        if(!al_init_font_addon())
        {
            return mg::AL_FONT_ADDON;
        }
    #endif // FONT_ADDON
    #ifdef TTF_ADDON
        if(!al_init_ttf_addon())
        {
            return mg::AL_TTF_ADDON;
        }
    #endif // TTF_ADDON
    #ifdef INSTALL_AUDIO
        if(!al_install_audio())
        {
            return mg::AL_INSTALL_AUDIO;
        }
    #endif // INSTALL_AUDIO
    #ifdef ACODEC_ADDON
        if(!al_init_acodec_addon())
        {
            return mg::AL_ACODEC_ADDON;
        }
    #endif // ACODEC_ADDON
    #ifdef PRIMITIVES_ADDON
        if(!al_init_primitives_addon())
        {
            return mg::AL_PRIMITIVES_ADDON;
        }
    #endif // PRIMITIVES_ADDON
    #ifdef VIDEO_ADDON
        if(!al_init_video_addon())
        {
            return mg::AL_VIDEO_ADDON;
        }
    #endif // VIDEO_ADDON
    #ifdef NATIVE_DIALOG
        if(!al_init_native_dialog_addon())
        {
            return mg::AL_NATIVE_DIALOG;
        }
    #endif // NATIVE_DIALOG
    return 0;
}

int Magro::init(Scene* &_scene, int _sx, int _sy, vtime _framerate, int _flag)
{
    int error = allegro_init();
    if(error !=0)
    {
        return error;
    }

    screen_width = _sx;
    screen_height = _sy;
    Framerate = _framerate;
    display_flag = _flag;
    al_set_new_display_flags(display_flag);
    display = al_create_display(screen_width, screen_height);
    if (display)
    {
        scenemanager->change_scene(_scene);
        Magro::run();
    }
    else
    {
        return mg::AL_ERROR_CREATE_DISPLAY;
    }

    return 0;
}

