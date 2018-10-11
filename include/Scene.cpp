#include "Scene.h"

float Scene::x() const
{
    return posx;
}

float Scene::y() const
{
    return posy;
}

void Scene::set_x(float _x)
{
    posx = _x;
}

void Scene::set_y(float _y)
{
    posy = _y;
}

void Scene::set_position(float _x, float _y)
{
    posx = _x;
    posy = _y;
}

float Scene::scale_x() const
{
    return sx;
}

float Scene::scale_y() const
{
    return sy;
}

void Scene::set_scale(float _sx, float _sy)
{
    sx = _sx;
    sy = _sy;
}

void Scene::set_scale_x(float _sx)
{
    sx = _sx;
}

void Scene::set_scale_y(float _sy)
{
    sy = _sy;
}
