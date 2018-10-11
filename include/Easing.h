#ifndef EASING_H_INCLUDED
#define EASING_H_INCLUDED
#include <math.h>
namespace mg
{
    enum tweening{linear,
     backIn, backOut, backInOut,
     bounceIn, bounceOut, bounceInOut,
     circIn, circOut, circInOut,
     cubicIn, cubicOut, cubicInOut,
     elasticIn, elasticOut, elasticInOut,
     expIn, expOut, expInOut,
     quadIn, quadOut, quadInOut,
     quartIn, quartOut, quartInOut,
     quintIn, quintOut, quintInOut,
     sinIn, sinOut, sinInOut
     };

  class Easing{
    public:
    /// t for time, b begin value, c end value, d duration
    static float linear(float t,float b , float c, float d);
    static float backIn(float t,float b , float c, float d);
	static float backOut(float t,float b , float c, float d);
	static float backInOut(float t,float b , float c, float d);

    static float bounceIn(float t,float b , float c, float d);
	static float bounceOut(float t,float b , float c, float d);
	static float bounceInOut(float t,float b , float c, float d);

    static float circIn(float t,float b , float c, float d);
	static float circOut(float t,float b , float c, float d);
	static float circInOut(float t,float b , float c, float d);

    static float cubicIn(float t,float b , float c, float d);
	static float cubicOut(float t,float b , float c, float d);
	static float cubicInOut(float t,float b , float c, float d);

    static float elasticIn(float t,float b , float c, float d);
	static float elasticOut(float t,float b , float c, float d);
	static float elasticInOut(float t,float b , float c, float d);

    static float expIn(float t,float b , float c, float d);
	static float expOut(float t,float b , float c, float d);
	static float expInOut(float t,float b , float c, float d);

    static float quadIn(float t,float b , float c, float d);
	static float quadOut(float t,float b , float c, float d);
	static float quadInOut(float t,float b , float c, float d);

    static float quartIn(float t,float b , float c, float d);
	static float quartOut(float t,float b , float c, float d);
	static float quartInOut(float t,float b , float c, float d);

    static float quintIn(float t,float b , float c, float d);
	static float quintOut(float t,float b , float c, float d);
	static float quintInOut(float t,float b , float c, float d);

    static float sinIn(float t,float b , float c, float d);
	static float sinOut(float t,float b , float c, float d);
	static float sinInOut(float t,float b , float c, float d);
};
}
#endif // EASING_H_INCLUDED
