#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <vector>

class SpriteAnimation
{
    public:
        SpriteAnimation();
        ~SpriteAnimation();
        void add_frame(float _x, float _y, float _sw, float _sh, float _delay = 0.0);
        void play();
        void stop();
        void set_direction(bool _direction);
        void set_loop(bool _loop);
        void set_duration(float _duration);
        void change_frame(int _frame);
        void reset();
        void set_frame_delay(int _frame, float _delay);
        void set_region(float _x, float _y, float _sw, float _sh);
        int get_current_frame() const;
        float get_frame_delay() const;
        bool get_direction() const;
        bool is_play() const;
        bool is_loop() const;

    private:
        struct _frame
        {
            float x;
            float y;
            float sw;
            float sh;
            float delay;
        };
        bool status;  /// play true else false
        bool loop;  /// true else false
        bool direction; /// 0 normal, 1 reverse
        float duration;
        float dt;
        int current_frame;
        std::vector<_frame> frame;
};

#endif // SPRITEANIMATION_H
