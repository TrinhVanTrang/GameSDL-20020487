#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_


#include "CommonFunc.h"
#include "BaseObject.h"

class PlayerObject: public BaseObject
{
public:
	PlayerObject();
	~PlayerObject();

	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen);   //ham lay su kien tu ban phim
	bool GetIsDie() const { return is_die_; }
	bool GetFalling() const { return is_falling_; }
	void SetFalling(bool falling) { is_falling_ = falling; }
	void SetCol(bool b) { check_col_ = b; }
	bool GetCol()const { return check_col_; }
	void DoFalling(SDL_Renderer* des);
	void DoGround(SDL_Renderer* screen);
	void SetVal(int v);
private:
	bool check_col_;
	bool is_die_;
	bool is_falling_;
	float y_val_;

};

#endif 