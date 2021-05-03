#include "CommonFunc.h"
void CommonFunction::LoadAudio(std::string path) //ham load am thanh
{
	Mix_Chunk* sound_ = Mix_LoadWAV(path.c_str());
	if (sound_ != NULL)
		Mix_PlayChannel(-1, sound_, 0);
	else
		cout << "load audio error!";
}


int CommonFunction::Random(int max, int min)
{
    return rand() % (max - min + 1) + min;
}

bool CommonFunction::CheckCollision(const SDL_Rect& obj1, const SDL_Rect& obj2)
{
    int left_a = obj1.x;
    int right_a = obj1.x + obj1.w;
    int top_a = obj1.y;
    int bottom_a = obj1.y + obj1.h;

    int left_b = obj2.x;
    int right_b = obj2.x + obj2.w;
    int top_b = obj2.y;
    int bottom_b = obj2.y + obj2.h;

    // Case 1: size object 1 < size object 2
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    // Case 2: size object 2 < size object 1
    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    // Case 3: size object 1 = size object 2
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return true;
    }

    return false;
}

bool CommonFunction::CheckFocusWithRect(const int& x, const int& y, SDL_Rect rect)
{
    if (x >= rect.x && x <= rect.x + rect.w &&
        y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
    return false;
}
