#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <Scene.h>
#include <Magro.h>
#include <iostream>
//class MyScene : public Scene
//{
//    public:
//        MyScene(){};
//        virtual void load() override;
//        virtual void unload() override;
//        virtual bool update(double dt) override;
//        virtual void draw() override;
//        virtual ~MyScene() { unload(); };
//    private:
//};

class SplashScreen : public Scene
{
    public:
        SplashScreen(){};
        virtual void load() override;
        virtual void unload() override;
        virtual bool update(double dt) override;
        virtual void draw() override;
        virtual ~SplashScreen() { unload(); };
    private:
    Sprite background = Sprite();
    ALLEGRO_BITMAP* bg;
};

#endif // SPLASHSCREEN_H
