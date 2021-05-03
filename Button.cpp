#include "Button.h"

ButtonObject::ButtonObject()
{
	is_touch_ = false;
	is_press_ = false;
	is_use_ = false;
}
ButtonObject::~ButtonObject()
{

}

bool ButtonObject::loadImage(std::string path, SDL_Renderer* screen)
{
	return loadImg(path, screen);
}

void ButtonObject::Show(SDL_Renderer* des)
{
	Render(des);
}
void ButtonObject::MouseEvent()
{
	int xm = 0;
	int ym = 0;

	while (SDL_PollEvent(&event_))
	{
		switch(event_.type)
		{
			case SDL_QUIT:
			{
				is_use_= true;
			}
			case SDL_MOUSEMOTION:
			{
				xm = event_.motion.x;
				ym = event_.motion.y;
				if (CommonFunction::CheckFocusWithRect(xm, ym, this->GetRect()))
				{
					is_touch_ = true;
				}
				else
				{
					is_touch_ = false;
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = event_.motion.x;
				ym = event_.motion.y;
				if (CommonFunction::CheckFocusWithRect(xm, ym, this->GetRect()))
				{
					CommonFunction::LoadAudio("audio//button.wav");
					is_press_ = true;
				}
				else
				{
					is_press_ = false;
				}
				break;
			}
		}
	}
}

