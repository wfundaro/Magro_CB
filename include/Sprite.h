#ifndef SPRITE_H
#define SPRITE_H
#include <Scene.h>

class Sprite
{
    public:
        Sprite()
        : posx(0), posy(0), alpha(255.0), scale_x(1.0), scale_y(1.0), angle(0.0), cx(0.0), cy(0.0), flag(0)
        {};
        void load(const char *filename);
        void load(const char *filename, float _rx, float _ry, float _sw, float _sh);
        void draw() const ;
        void set_scale_to_screen();
        void set_position(float _x, float _y);
        void set_x(float _x);
        void set_y(float _y);
        float x() const;
        float y() const;
        void set_center(float _cx, float _cy);
        void set_center_x(float _cx);
        void set_center_y(float _cy);
        float get_center_x() const;
        float get_center_y() const;
        void set_alpha(float _alpha);
        float get_alpha() const;
        void set_angle(float _angle);
        float get_angle() const;
        void set_color(float _r, float _g, float _b);
        ALLEGRO_COLOR get_color() const;
        float get_r_color() const;
        float get_g_color() const;
        float get_b_color() const;
        float width() const;
        float height() const;
        virtual ~Sprite();

    protected:
        ALLEGRO_BITMAP* ptr = nullptr;
        float posx;
        float posy;
        float scale_x;
        float scale_y;
        float alpha;
        float angle;
        float cx;
        float cy;
        int flag;
        struct
        {
            float r;
            float g;
            float b;
            float ar;
            float ag;
            float ab;
        }color;

    private:
        struct
        {
            float x;
            float y;
            float sw;
            float sh;
        } region;
};

#endif // SPRITE_H
