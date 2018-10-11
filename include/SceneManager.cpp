#include "SceneManager.h"
#include <Cmagro.h>
#include <Magro.h>

namespace _mg
{
    void SceneManager::change_scene(Scene* &_scene, mg::transition _transition, vtime _time, mg::tweening _easing)
    {
        trans_mode = _transition;
        scene_easing = _easing;
        new_scene = _scene;
        new_scene->load();
        if(trans_mode == mg::none)
        {
            transition_on = false;
            if(current_scene != nullptr)
            {
                delete(current_scene);
            }
            current_scene = new_scene;
        }else
        {
            if(_transition >= mg::mix)
            {
                image_transition = al_create_bitmap(al_get_display_width(mg::get_display()), al_get_display_height(mg::get_display()) );
                al_set_target_bitmap(image_transition);
                new_scene->draw();
                al_set_target_backbuffer(mg::get_display());
            }
            duration_transition = _time;
            dtime_transition = 0.0;
            transition_on = true;
        }
    }

    void SceneManager::update_transition(vtime _dt)
    {
        double variable;
        if(trans_mode < mg::Tmove)
        {
            variable = easing_value(dtime_transition, 0.0, 255.0, duration_transition);
        }
        float screenW = mg::screen_width();
        float screenH = mg::screen_height();
        switch(trans_mode)
        {
            case mg::fadeOut :
                current_scene->draw();
                al_draw_filled_rectangle(0,0, screenW, screenH, al_map_rgba(0,0,0,variable));
                break;
            case mg::fadeOutIn :
                if(variable < 127.0)
                {
                    current_scene->draw();
                    al_draw_filled_rectangle(0,0,screenW, screenH, al_map_rgba(0,0,0,variable*2));
                }
                else{
                    new_scene->draw();
                    al_draw_filled_rectangle(0,0,screenW, screenH, al_map_rgba(0,0,0,(255.0 - variable)*2));
                }
                break;
            case mg::fadeIn :
                new_scene->draw();
                al_draw_filled_rectangle(0,0,screenW, screenH, al_map_rgba(0,0,0,255.0 - variable));
                break;
            case mg::mix :
                current_scene->draw();
                al_draw_tinted_bitmap(image_transition, al_map_rgba(variable, variable, variable, variable), 0, 0, 0);
                break;
            case mg::Tmove :
                current_scene->draw();
                al_draw_bitmap(image_transition, 0, easing_value(dtime_transition, 0, screenH, duration_transition) - screenH, 0);
                break;
            case mg::Rmove :
                current_scene->draw();
                al_draw_bitmap(image_transition, screenW - easing_value(dtime_transition, 0, screenW, duration_transition), 0, 0);
                break;
            case mg::Dmove :
                current_scene->draw();
                al_draw_bitmap(image_transition, 0, screenH - easing_value(dtime_transition, 0, screenH, duration_transition), 0);
                break;
            case mg::Lmove :
                current_scene->draw();
                al_draw_bitmap(image_transition, easing_value(dtime_transition, 0, screenW, duration_transition) - screenW, 0, 0);
            case mg::Tmove2 :
                current_scene->set_position(0, easing_value(dtime_transition, 0, screenH, duration_transition));
                current_scene->draw();
                al_draw_bitmap(image_transition, 0, easing_value(dtime_transition, 0, screenH, duration_transition) - screenH, 0);
                break;
            case mg::Rmove2 :
                current_scene->set_position(-easing_value(dtime_transition, 0, screenW, duration_transition), 0);
                current_scene->draw();
                al_draw_bitmap(image_transition, screenW - easing_value(dtime_transition, 0, screenW, duration_transition), 0, 0);
                break;
            case mg::Dmove2 :
                current_scene->set_position(0, -easing_value(dtime_transition, 0, screenH, duration_transition));
                current_scene->draw();
                al_draw_bitmap(image_transition, 0, screenH - easing_value(dtime_transition, 0, screenH, duration_transition), 0);
                break;
            case mg::Lmove2 :
                current_scene->set_position(easing_value(dtime_transition, 0, screenW, duration_transition), 0);
                current_scene->draw();
                al_draw_bitmap(image_transition, easing_value(dtime_transition, 0, screenW, duration_transition) - screenW, 0, 0);
            case mg::zoom :
                //float scale = easing_value(dtime_transition, 0, 1.0, duration_transition);
                //float x = (screenW/2) - (screenW/2) * scale;
                //float y = (screenH/2) - (screenH/2) * scale;
                current_scene->draw();
                al_draw_scaled_bitmap(image_transition, (screenW/2) - (screenW/2) * easing_value(dtime_transition, 0, 1.0, duration_transition),
                                       (screenH/2) - (screenH/2) * easing_value(dtime_transition, 0, 1.0, duration_transition),
                                        screenW * easing_value(dtime_transition, 0, 1.0, duration_transition),
                                       screenH * easing_value(dtime_transition, 0, 1.0, duration_transition), 0, 0, screenW, screenH, 0);
                break;
            case mg::zoom2 :
                float scale = easing_value(dtime_transition, 0, 1.0, duration_transition);
                float x = (screenW/2) - (screenW/2) / scale;
                float y = (screenH/2) - (screenH/2) / scale;
                current_scene->draw();
                al_draw_scaled_bitmap(image_transition, x, y, screenW / scale, screenH / scale, 0, 0, screenW, screenH, 0);
                break;
        }
        dtime_transition += _dt;
        if(dtime_transition >= duration_transition) /// end of transition
        {
            if(current_scene != nullptr){
                delete(current_scene);
            }
            if(image_transition != nullptr)
            {
                al_destroy_bitmap(image_transition);
                image_transition = nullptr;
            }
            current_scene = new_scene;
            transition_on = false;
        }
    }

    bool SceneManager::get_transition_on() const
    {
        return transition_on;
    }

    bool SceneManager::update_scene(vtime _dt)
    {
        return current_scene->update(_dt);
    }

    void SceneManager::draw_scene()
    {
        current_scene->draw();
    }

    void SceneManager::destroy()
    {
        if(current_scene != nullptr)
        {
            delete current_scene;
        }
        new_scene = nullptr;
        current_scene = nullptr;
    }

vtime SceneManager::easing_value(vtime _time, float _origin, float _end, vtime _duration)
    {
        switch(scene_easing)
        {
        case mg::backIn :
            return mg::Easing::backIn(_time, _origin, _end, _duration);
        case mg::backOut :
            return mg::Easing::backOut(_time, _origin, _end, _duration);
        case mg::backInOut :
            return mg::Easing::backInOut(_time, _origin, _end, _duration);
        case mg::bounceIn :
            return mg::Easing::bounceIn(_time, _origin, _end, _duration);
        case mg::bounceOut :
            return mg::Easing::bounceOut(_time, _origin, _end, _duration);
        case mg::bounceInOut :
            return mg::Easing::bounceInOut(_time, _origin, _end, _duration);
        case mg::circIn :
            return mg::Easing::circIn(_time, _origin, _end, _duration);
        case mg::circOut :
            return mg::Easing::circOut(_time, _origin, _end, _duration);
        case mg::circInOut :
            return mg::Easing::circInOut(_time, _origin, _end, _duration);
        case mg::cubicIn :
            return mg::Easing::cubicIn(_time, _origin, _end, _duration);
        case mg::cubicOut :
            return mg::Easing::cubicOut(_time, _origin, _end, _duration);
        case mg::cubicInOut :
            return mg::Easing::cubicInOut(_time, _origin, _end, _duration);
        case mg::elasticIn :
            return mg::Easing::elasticIn(_time, _origin, _end, _duration);
        case mg::elasticOut :
            return mg::Easing::elasticOut(_time, _origin, _end, _duration);
        case mg::elasticInOut :
            return mg::Easing::elasticInOut(_time, _origin, _end, _duration);
        case mg::expIn :
            return mg::Easing::expIn(_time, _origin, _end, _duration);
        case mg::expOut :
            return mg::Easing::expOut(_time, _origin, _end, _duration);
        case mg::expInOut :
            return mg::Easing::expInOut(_time,_origin, _end, _duration);
        case mg::quadIn :
            return mg::Easing::quadIn(_time,_origin, _end, _duration);
        case mg::quadOut :
            return mg::Easing::quadOut(_time, _origin, _end, _duration);
        case mg::quadInOut :
            return mg::Easing::quadInOut(_time, _origin, _end, _duration);
        case mg::quartIn :
            return mg::Easing::quartIn(_time, _origin, _end, _duration);
        case mg::quartOut :
            return mg::Easing::quartOut(_time, _origin, _end, _duration);
        case mg::quartInOut :
            return mg::Easing::quartInOut(_time, _origin, _end, _duration);
        case mg::quintIn :
            return mg::Easing::quintIn(_time,_origin, _end, _duration);
        case mg::quintOut :
            return mg::Easing::quintOut(_time,_origin, _end, _duration);
        case mg::quintInOut :
            return mg::Easing::quintInOut(_time, _origin, _end, _duration);
        case mg::sinIn :
            return mg::Easing::sinIn(_time, _origin, _end, _duration);
        case mg::sinOut :
            return mg::Easing::sinOut(_time, _origin, _end, _duration);
        case mg::sinInOut :
            return mg::Easing::sinInOut(_time, _origin, _end, _duration);
        case mg::linear :
        //[[fallthrough]];
        default :
            return mg::Easing::linear(_time, _origin, _end, _duration);
        }
    }
}
