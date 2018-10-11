#ifndef SPRITESHEET_H
#define SPRITESHEET_H
#include <Scene.h>
#include <vector>
#include "SpriteAnimation.h"

class SpriteSheet
{
    public:
        SpriteSheet(Scene& _scene)
        : scene(_scene), posx(0), posy(0), alpha(255.0), scale_x(1.0), scale_y(1.0), angle(0.0), cx(0.0), cy(0.0), flag(0)
        {};
        void load(const char *filename);
        void draw() const ;
        void set_x(float _x);
        void set_y(float _y);
        float x() const;
        float y() const;
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
        virtual ~SpriteSheet();

        void add_animation();
    protected:
        ALLEGRO_BITMAP* ptr = nullptr;
        Scene& scene;
        float posx;
        float posy;
        float scale_x;
        float scale_y;
        float alpha;
        float angle;
        float cx;
        float cy;
        int flag;
        struct _color
        {
            float r;
            float g;
            float b;
        };
        _color color;
    private:
        std::vector<SpriteAnimation> animation;
};
#endif // SPRITESHEET_H
