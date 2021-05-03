#pragma once
#ifndef SCORE_OBJECT_H_
#define SCORE_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
const string numb[10] = { "image//0.png", "image//1.png" ,"image//2.png" ,"image//3.png" ,"image//4.png" ,"image//5.png" ,"image//6.png" ,"image//7.png" ,"image//8.png" ,"image//9.png" };
const string numb_50x70[10] = { "image//0_50x70.png", "image//1_50x70.png" ,"image//2_50x70.png" ,"image//3_50x70.png" ,"image//4_50x70.png" ,"image//5_50x70.png" ,"image//6_50x70.png" ,"image//7_50x70.png" ,"image//8_50x70.png" ,"image//9_50x70.png" };



class ScoreObject //: public BaseObject
{
public:
	ScoreObject();
	~ScoreObject();
	void SetAddScore(bool b) { add_score_ = b; }
	bool GetAddScore()const { return add_score_; }
	int GetScoreVal()const { return score_val_; }
	//void CheckAddScore(const SDL_Rect& obj1, const SDL_Rect& obj2);
	void Add() ;
	/*void RenderScore();
	void Show(SDL_Renderer*des);*/
	void InitScore(SDL_Renderer* screen, int x_tram, int x_chuc, int x_dv,int y);
	void ShowImg(SDL_Renderer* screen);
private:
	/*LoadScore img_tram_;
	LoadScore img_chuc_;
	LoadScore img_dv_;*/
	BaseObject img_tram_;
	BaseObject img_chuc_;
	BaseObject img_dv_;
	int score_val_;
	bool add_score_;
};

//class phu trach animation coin
class EffectCoin :public BaseObject
{
public:
	EffectCoin();
	~EffectCoin();
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void set_clips();
	void SetEffect(bool b) { check_effect_ = b; }
	bool GetEffect()const { return check_effect_; }
	void SetRect(const int& x, const int& y);
private:
	bool check_effect_;
	float x_pos_;
	float y_pos_;
	int width_frame_;
	int height_frame_;
	SDL_Rect frame_clip_[4];
	int frame_;
};

struct number_img
{
	BaseObject tram_;
	BaseObject chuc_;
	BaseObject dv_;
	BaseObject medal_;
	int val_;
};
class HightScore :public BaseObject
{
public:
	HightScore();
	~HightScore();
	bool loadImg(SDL_Renderer* screen);
	void Show(SDL_Renderer* screen);
	void UpdateHightScore(int score);
	int CheckScore(int score);
	void SetRect();
	void GetScore();
private:	
	number_img hight_score[3];
	BaseObject transcript_;
};
#endif