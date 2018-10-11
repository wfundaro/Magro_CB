#include "Sprite.h"
#include <magro.h>

void Sprite::load(const char *filename, float _rx, float _ry, float _sw, float _sh)
{
    ptr = al_load_bitmap(filename);
    region.x = _rx;
    region.y = _ry;
    if(_sw < 0)
    {
        region.sw = al_get_bitmap_width(ptr);
    }else
    {
        region.sw = _sw;
    }
    if(_sh < 0)
    {
       region.sh = al_get_bitmap_height(ptr);
    }else
    {
        region.sh = _sh;
    }
    color.r = 255.0;
    color.g = 255.0;
    color.b = 255.0;
    color.ar = 255.0;
    color.ag = 255.0;
    color.ab = 255.0;
}

void Sprite::load(const char *filename)
{
    load(filename, 0.0, 0.0, -1, -1);
}

void Sprite::draw() const
{
    if(ptr != NULL)
    {
        al_draw_tinted_scaled_rotated_bitmap_region(ptr, region.x, region.y, region.sw, region.sh,
                                                al_map_rgba(color.ar, color.ag, color.ab, alpha), cx, cy,
                                                posx + mg::_get_current_scene().x(), posy + mg::_get_current_scene().y(),
                                                scale_x * mg::_get_current_scene().scale_x(), scale_y * mg::_get_current_scene().scale_y(),
                                                angle, flag );
    }
}

void Sprite::set_scale_to_screen()
{
    scale_x = mg::screen_width() / width();
    scale_y = mg::screen_height() / height();
}

void Sprite::set_position(float _x, float _y)
{
    posx = _x;
    posy = _y;
}

void Sprite::set_x(float _x)
{
    posx = _x;
}

void Sprite::set_y(float _y)
{
    posy = _y;
}

float Sprite::x() const
{
    return posx;
}

float Sprite::y() const
{
    return posy;
}

void Sprite::set_center(float _cx, float _cy)
{
    cx = _cx;
    cy = _cy;
}

void Sprite::set_center_x(float _cx)
{
    cx = _cx;
}

void Sprite::set_center_y(float _cy)
{
    cy = _cy;
}

float Sprite::get_center_x() const
{
    return cx;
}

float Sprite::get_center_y() const
{
    return cy;
}

void Sprite::set_alpha(float _alpha)
{
    float coeff = _alpha / 255.0;
    color.ar = color.r * coeff;
    color.ag = color.g * coeff;
    color.ab = color.b * coeff;
    alpha = _alpha;
}

float Sprite::get_alpha() const
{
    return alpha;
}

void Sprite::set_angle(float _angle)
{
    angle = (ALLEGRO_PI / 180.0) * _angle;

}

float Sprite::get_angle() const
{
    return angle *(180.0 / ALLEGRO_PI);
}

void Sprite::set_color(float _r, float _g, float _b)
{
    color.r = _r;
    color.g = _g;
    color.b = _b;
    set_alpha(alpha);
}

ALLEGRO_COLOR Sprite::get_color() const
{
    return al_map_rgba(color.r, color.g, color.b, alpha);
}

float Sprite::get_r_color() const
{
    return color.r;
}

float Sprite::get_g_color() const
{
    return color.g;
}

float Sprite::get_b_color() const
{
    return color.b;
}

float Sprite::width() const
{
    return region.sw;
}

float Sprite::height() const
{
    return region.sh;
}

Sprite::~Sprite()
{
    al_destroy_bitmap(ptr);
}
