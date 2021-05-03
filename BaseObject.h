#pragma once
//chua 1 lop co so dai dien cho doi tuong hinh anh hien thi len man hinh
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "CommonFunc.h"

class BaseObject
{
public :
	BaseObject();
	~BaseObject();
	void SetRect(const int& x, const int& y);
	SDL_Rect GetRect() const { return rect_; } //lay ra kich thuoc hinh anh
	SDL_Texture* GetObject(){ return p_object_; } //lay ra cac diem anh load duoc
	virtual bool loadImg(std::string path, SDL_Renderer* screen);          //ham load anh
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);     //hien thi anh
	void Free();

	
	void SetXPos(const int& x);
	int GetXPos() const { return this->rect_.x; }
	void DoRun(int x_val);
	bool GetStateBack() const { return is_back_; }
	void SetBack(bool b) { is_back_ = b; }

protected:
	bool is_back_;
	SDL_Texture* p_object_;    //bien luu tru cac hinh anh load duoc
	SDL_Rect rect_;            //bien luu kich thuoc hinh anh
};

#endif
