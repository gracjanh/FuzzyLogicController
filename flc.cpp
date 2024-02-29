
#include <iostream>
#include <random>

using namespace std;

// VARIABLES
int light,
    percentage;
float a = 20,
      b = 25,
      c = 30,
      d = 50,
      e = 500,
      f = 1000,
      current_temp,
      desired_temp,
      output,
      cold,
      warm,
      hot,
      dark,
      bright,
      very_bright,
      cold_and_dark,
      cold_and_bright,
      cold_and_very_bright,
      warm_and_dark,
      warm_and_bright,
      warm_and_very_bright,
      hot_and_dark,
      hot_and_bright,
      hot_and_very_bright,
      none,
      slow,
      fast;

// FUNCTIONS
void set_current_temp(float val)
{
    current_temp = val;
}

void set_desired_temp(float val)
{
    desired_temp = val;
}

void set_light_intensity(int val)
{
    light = val;
}

void classify_temp()
{
    if (current_temp <= a)
        cold = 1;
    else if ((a < current_temp) && (current_temp <= b))
        cold = (b - current_temp) / (b - a);
    else if (current_temp > b)
        cold = 0;

    if (current_temp <= a)
        warm = 0;
    else if ((a < current_temp) && (current_temp <= b))
        warm = (current_temp - a) / (b - a);
    else if ((b < current_temp) && (current_temp <= c))
        warm = (c - current_temp) / (c - b);
    else if (current_temp > c)
        warm = 0;

    if (current_temp <= b)
        hot = 0;
    else if ((b < current_temp) && (current_temp <= c))
        hot = (current_temp - b) / (c - b);
    else if (current_temp > c)
        hot = 1;
}

void classify_light_intensity()
{

    if (light <= d)
        dark = 1;
    else if ((d < light) && (light <= e))
        dark = (e - light) / (e - d);
    else if (light > e)
        dark = 0;

    if (light <= d)
        bright = 0;
    else if ((d < light) && (light <= e))
        bright = (light - d) / (e - d);
    else if ((e < light) && (light <= f))
        bright = (f - light) / (f - e);
    else if (light > f)
        bright = 0;

    if (light <= e)
        very_bright = 0;
    else if ((e < light) && (light <= f))
        very_bright = (light - e) / (f - e);
    else if (light > f)
        very_bright = 1;
}

void find_intersection()
{
    cold_and_dark = min(cold, dark);
    cold_and_bright = min(cold, bright);
    cold_and_very_bright = min(cold, very_bright);

    warm_and_dark = min(warm, dark);
    warm_and_bright = min(warm, bright);
    warm_and_very_bright = min(warm, very_bright);

    hot_and_dark = min(hot, dark);
    hot_and_bright = min(hot, bright);
    hot_and_very_bright = min(hot, very_bright);
}

void fan_speed()
{
    none = max(max(cold_and_dark, cold_and_bright), cold_and_very_bright);
    slow = max(max(warm_and_dark, warm_and_bright), hot_and_dark);
    fast = max(max(hot_and_bright, hot_and_very_bright), warm_and_very_bright);
}

void calculate_fan_speed()
{
    output = ((0 * none + 6 * slow + 12 * fast) / (none + slow + fast));
    percentage = (output / 12 * 100);
}

// MAIN
int main()
{
    set_current_temp(25.8);
    set_light_intensity(600);
    set_desired_temp(19);

    classify_temp();
    classify_light_intensity();

    find_intersection();
    fan_speed();
    calculate_fan_speed();

    cout << percentage << "%";

    return 0;
}
