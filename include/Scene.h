#ifndef SCENE_H
#define SCENE_H
#include "init.h"
#include <mg_init.h>

class Scene
{
	public:
        Scene() : posx(0), posy(0), sx(1.0), sy(1.0) {};
		virtual void load() = 0;
		virtual void unload() = 0;
		virtual bool update(double dt) = 0;  ///return end game with true
		virtual void draw() = 0;
		virtual ~Scene(){};
		virtual float x() const final;
		virtual float y() const final;
        virtual void set_x(float _x) final;
		virtual void set_y(float _y) final;
		virtual void set_position(float _x, float _y) final;
		virtual float scale_x() const final;
		virtual float scale_y() const final;
		virtual void set_scale(float _sx, float _sy) final;
		virtual void set_scale_x(float _sx) final;
		virtual void set_scale_y(float _sy) final;
    protected:
        float posx;
        float posy;
        float sx;
        float sy;
};

#endif // SCENE_H
