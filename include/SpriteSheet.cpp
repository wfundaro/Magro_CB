#include "SpriteSheet.h"
#include <vector>

void SpriteSheet::add_animation()
{

}

void SpriteSheet::load(const char *filename)
{
    ptr = al_load_bitmap(filename);
//    region.x = 0.0;
//    region.y = 0.0;
//    region.sw = al_get_bitmap_width(ptr);
//    region.sh = al_get_bitmap_height(ptr);
    color.r = 255.0;
    color.g = 255.0;
    color.b = 255.0;
}

void SpriteSheet::draw() const
{
    if(ptr != NULL)
    {
//        al_draw_tinted_scaled_rotated_bitmap_region(ptr, region.x, region.y, region.sw, region.sh,
//                                                al_map_rgba(color.r, color.g, color.b, alpha), cx, cy, posx + scene.x(), posy + scene.y(),
//                                                scale_x * scene.scale_x(), scale_y * scene.scale_y(), angle, flag );

        al_draw_tinted_scaled_rotated_bitmap_region(ptr, 0, 0, 128, 128,
                                                al_map_rgba(color.r, color.g, color.b, alpha), cx, cy, posx + scene.x(), posy + scene.y(),
                                                scale_x * scene.scale_x(), scale_y * scene.scale_y(), angle, flag );

    }
}

void SpriteSheet::set_x(float _x)
{
    posx = _x;
}

void SpriteSheet::set_y(float _y)
{
    posy = _y;
}

float SpriteSheet::x() const
{
    return posx;
}

float SpriteSheet::y() const
{
    return posy;
}

void SpriteSheet::set_alpha(float _alpha)
{
    float coeff = 255.0 / _alpha;
    color.r *= coeff;
    color.g *= coeff;
    color.b *= coeff;
    alpha = _alpha;
}

float SpriteSheet::get_alpha() const
{
    return alpha;
}

void SpriteSheet::set_angle(float _angle)
{
    angle = (ALLEGRO_PI / 180.0) * _angle;
}

float SpriteSheet::get_angle() const
{
    return angle;
}

void SpriteSheet::set_color(float _r, float _g, float _b)
{
    color.r = _r;
    color.g = _g;
    color.b = _b;
}

ALLEGRO_COLOR SpriteSheet::get_color() const
{
    return al_map_rgba(color.r, color.g, color.b, alpha);
}

float SpriteSheet::get_r_color() const
{
    return color.r;
}

float SpriteSheet::get_g_color() const
{
    return color.g;
}

float SpriteSheet::get_b_color() const
{
    return color.b;
}

float SpriteSheet::width() const
{
    return 0;
}

float SpriteSheet::height() const
{
    return 0;
}

SpriteSheet::~SpriteSheet()
{
    al_destroy_bitmap(ptr);
}
