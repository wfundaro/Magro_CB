#include "SplashScreen.h"
#include <Magro.h>
#include <iostream>
#include "SceneMenu.h"

void SplashScreen::load()
{
    background.load("media/sokoban2.png");
    background.set_x(rand() % static_cast<int>(mg::screen_width()));
    background.set_y(300);
    background.set_center(background.width()/2 , background.height()/2);
    std::cout << "load splashscreen" << std::endl;
}

bool SplashScreen::update(double dt) /// dt is in second
{
    static float vx = 2.5;
    static float dscene = 0.0;
    static float ialpha = 255;
    ialpha-=5;
    if(ialpha <=1)
        ialpha = 255;
    background.set_alpha(ialpha);
    background.set_x(background.x() + vx);
    background.set_angle(background.get_angle() +3);
    if(background.x() < 0)
    {
        background.set_x(0);
        vx = -vx;
    }
    if(background.x() > mg::screen_width())
    {
        background.set_x(mg::screen_width());
        vx = -vx;
    }
    dscene += dt;
    if( dscene >= 3.0)
    {
        srand(time(NULL));
        dscene = 0.0;
        Scene* scene = new SceneMenu();
        mg::change_scene(scene, static_cast<mg::transition>(1+ rand() % mg::zoom2) , 2.0, static_cast<mg::tweening>(rand() % mg::sinInOut));
        //mg::change_scene(scene, mg::zoom2 , 2.0, static_cast<mg::tweening>(rand() % mg::sinInOut));
    }
	return false;
}

void SplashScreen::draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    background.draw();

}

void SplashScreen::unload()
{
    std::cout << "Unload splashscreen" << std::endl;
}
