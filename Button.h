#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class ButtonObject :public BaseObject
{
public:
	ButtonObject();
	~ButtonObject();
	bool loadImage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer*des);
	void MouseEvent();
	bool GetIsTouch()const { return is_touch_; }
	void SetIsTouch(bool b) { is_touch_ = b; }
	bool GetIsPress()const{ return is_press_; }
	void SetIsPress(bool b) { is_press_ = b; }
	bool GetIsUse()const { return is_use_; }
	
private:
	SDL_Event event_;
	bool is_press_;
	bool is_touch_;
	bool is_use_;




};

#endif


