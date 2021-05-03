#pragma once
#ifndef PIPE_OBJECT_H_
#define PIPE_OBJECT_H_
#include "BaseObject.h"
#include "CommonFunc.h"
#include "ScoreObject.h"
#include "PlayerObject.h"
class PipeObject : public BaseObject
{
public:
	PipeObject();
	~PipeObject();
	bool LoadImg(std::string path,SDL_Renderer* screen);
	void ShowImg(SDL_Renderer* screen);

	void SetPos(const int& x, const int& y);
	void SetXPos(const int& x);
	int GetXPos() const { return this->rect_.x;}
	SDL_Rect GetRectPos() const { return this->GetRect();}
	void DoRun(int x_val);
	bool GetStateBack() const { return is_back_; }
	
	void SetBack(bool b) { is_back_ = b; }
	
private:
	bool is_back_;
	int x_pos_;
	int y_pos_;
	
};

class TreeObject :public BaseObject
{
public:
	TreeObject();
	~TreeObject();
	bool loadimage(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void set_clips();

	void DoRun(int x_val);
	void SetPos(const int& x, const int& y);
	bool GetStateBack() const { return is_back_; }
	void SetBack(bool b) { is_back_ = b; }
	bool GetAppear() const { return is_appear_; }
	void SetAppear(bool b) { is_appear_ = b; }
	void DoAppear(int y_val);
	void SetValAppear(int v) { val_appear_ = v; }

private:
	bool is_back_;
	bool is_appear_;
	int val_appear_;
	float x_pos_;
	float y_pos_;
	int width_frame_;
	int height_frame_;
	SDL_Rect frame_clip_[4];
	int frame_;

};

class DoublePipe
{
public:
	DoublePipe();
	~DoublePipe();
	void Init(SDL_Renderer*screen,const int& xpos);
	void Move();
	bool GetIsPass()const { return is_pass_; }
	void SetIsPass(bool b) { is_pass_ = b; }
	void CheckPass(SDL_Rect obj);
	bool CheckCol(SDL_Rect obj);
	bool GetBack()const { return is_back_; }
	void SetIsBack(bool b);
	void ShowImage(SDL_Renderer* screen);
	int GetXpos();
	void SetXRect(const int& xp);
	void SetVal(int v);
	void SetDistanse_H(int s) { d_height_ = s; }
	void SetIsAppear(bool b) { is_appear_ = b; }
	bool GetIsAppear()const { return is_appear_; }
	void Appear();

private:
	PipeObject up_pipe_;
	PipeObject down_pipe_;
	TreeObject up_tree_;
	TreeObject down_tree_;
	bool is_pass_;
	bool is_back_;
	bool is_appear_;
	int x_val_;
	float y_val_;
	int d_height_;
	bool is_pause_;

};

class PipeList
{
public:
	PipeList();
	~PipeList();
	void InitList(SDL_Renderer* screen);
	void ShowList(SDL_Renderer* screen, PlayerObject &obj,ScoreObject &scr);
	void DeleteList();
	void SetStopMove(bool b) { stop_move_ = b; }
	bool GetCol()const { return is_col_; }
	bool GetPass()const { return is_pass_; }
	void SetPass(bool b) { is_pass_ = b; }
	void SetVal(int v);
	void SetDistanseW(int s) { d_width_ = s; }

private:
	std::vector < DoublePipe*> list_;
	bool is_col_;
	bool is_pass_;
	bool stop_move_;
	int d_width_;
};




#endif 

