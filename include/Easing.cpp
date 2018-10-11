#include <Easing.h>
#ifndef PI
#define PI  3.14159265
#endif
namespace mg
{
    float Easing::linear(float t,float b , float c, float d)
    {
        return c*t/d + b;
    }

    float Easing::backIn(float t,float b , float c, float d)
    {
        float s = 1.70158f;
        float postFix = t/=d;
        return c*(postFix)*t*((s+1)*t - s) + b;
    }

    float Easing::backOut(float t,float b , float c, float d)
    {
        float s = 1.70158f;
        return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
    }

    float Easing::backInOut(float t,float b , float c, float d)
    {
        float s = 1.70158f;
        if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
        float postFix = t-=2;
        return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
    }

    float Easing::bounceIn(float t,float b , float c, float d)
    {
        return c - bounceOut (d-t, 0, c, d) + b;
    }

    float Easing::bounceOut(float t,float b , float c, float d)
    {
        if ((t/=d) < (1/2.75f)) {
            return c*(7.5625f*t*t) + b;
        } else if (t < (2/2.75f)) {
            float postFix = t-=(1.5f/2.75f);
            return c*(7.5625f*(postFix)*t + .75f) + b;
        } else if (t < (2.5/2.75)) {
                float postFix = t-=(2.25f/2.75f);
            return c*(7.5625f*(postFix)*t + .9375f) + b;
        } else {
            float postFix = t-=(2.625f/2.75f);
            return c*(7.5625f*(postFix)*t + .984375f) + b;
        }
    }

    float Easing::bounceInOut(float t,float b , float c, float d)
    {
        if (t < d/2) return bounceIn (t*2, 0, c, d) * .5f + b;
        else return bounceOut (t*2-d, 0, c, d) * .5f + c*.5f + b;
    }

    float Easing::circIn(float t,float b , float c, float d)
    {
       return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
    }

    float Easing::circOut(float t,float b , float c, float d)
    {
        return c * sqrt(1 - (t=t/d-1)*t) + b;
    }

    float Easing::circInOut(float t,float b , float c, float d)
    {
        if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
        return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
    }

    float Easing::cubicIn(float t,float b , float c, float d)
    {
        return c*(t/=d)*t*t + b;
    }

    float Easing::cubicOut(float t,float b , float c, float d)
    {
        return c*((t=t/d-1)*t*t + 1) + b;
    }

    float Easing::cubicInOut(float t,float b , float c, float d)
    {
        if ((t/=d/2) < 1) return c/2*t*t*t + b;
        return c/2*((t-=2)*t*t + 2) + b;
    }

    float Easing::elasticIn(float t,float b , float c, float d)
    {
        if (t==0) return b;  if ((t/=d)==1) return b+c;
        float p=d*.3f;
        float a=c;
        float s=p/4;
        float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
        return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
    }

    float Easing::elasticOut(float t,float b , float c, float d)
    {
        if (t==0) return b;  if ((t/=d)==1) return b+c;
        float p=d*.3f;
        float a=c;
        float s=p/4;
        return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
    }

    float Easing::elasticInOut(float t,float b , float c, float d)
    {
        if (t==0) return b;  if ((t/=d/2)==2) return b+c;
        float p=d*(.3f*1.5f);
        float a=c;
        float s=p/4;

        if (t < 1) {
            float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
            return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
        }
        float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
        return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
    }

    float Easing::expIn(float t,float b , float c, float d)
    {
        return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
    }

    float Easing::expOut(float t,float b , float c, float d)
    {
        return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
    }

    float Easing::expInOut(float t,float b , float c, float d)
    {
        if (t==0) return b;
        if (t==d) return b+c;
        if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
        return c/2 * (-pow(2, -10 * --t) + 2) + b;
    }

    float Easing::quadIn(float t,float b , float c, float d)
    {
        return c*(t/=d)*t + b;
    }

    float Easing::quadOut(float t,float b , float c, float d)
    {
        return -c *(t/=d)*(t-2) + b;
    }

    float Easing::quadInOut(float t,float b , float c, float d)
    {
        if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
        return -c/2 * (((t-2)*(--t)) - 1) + b;
    }

    float Easing::quartIn(float t,float b , float c, float d)
    {
        return c*(t/=d)*t*t*t + b;
    }

    float Easing::quartOut(float t,float b , float c, float d)
    {
        return -c * ((t=t/d-1)*t*t*t - 1) + b;
    }

    float Easing::quartInOut(float t,float b , float c, float d)
    {
        if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
        return -c/2 * ((t-=2)*t*t*t - 2) + b;
    }

    float Easing::quintIn(float t,float b , float c, float d)
    {
        return c*(t/=d)*t*t*t*t + b;
    }

    float Easing::quintOut(float t,float b , float c, float d)
    {
        return c*((t=t/d-1)*t*t*t*t + 1) + b;
    }

    float Easing::quintInOut(float t,float b , float c, float d)
    {
        if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
        return c/2*((t-=2)*t*t*t*t + 2) + b;
    }

    float Easing::sinIn(float t,float b , float c, float d)
    {
        return -c * cos(t/d * (PI/2)) + c + b;
    }

    float Easing::sinOut(float t,float b , float c, float d)
    {
        return c * sin(t/d * (PI/2)) + b;
    }

    float Easing::sinInOut(float t,float b , float c, float d)
    {
        return -c/2 * (cos(PI*t/d) - 1) + b;
    }
}

