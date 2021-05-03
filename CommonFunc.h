#pragma once
//Chua cac thong so chung cua chuong trinh
//Noi goi cac file header cua thu vien SDL2
#ifndef COMMONFUNC_H
#define COMMONFUNC_H
//Cac thu vien thuong su dung 
//#include <window.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
static SDL_Window* g_window = NULL;      //bien xay dung len man hinh WINDOW 
static SDL_Renderer* g_screen = NULL;      //bien load anh len man hinh
static SDL_Event g_event;        //bien nhan cac du kien tu ban phim chuot

//Cac thong so co ban cho moi truong game
const int SCREEN_WIDTH = 1000;           //chieu rong man hinh
const int SCREEN_HEIGHT = 720;           //chieu cao man hinh
const int SCREEN_BPP = 32;	//chi so load pixel
const int FRAMES_PER_SECOND = 55; //fps: so frame tren 1s

#define GROUND_MAP 640  //vi tri cua nen dat
#define GROUND_STRET 950          //khoang cach di chuyen giua cac nen dat

const int SPEED_GROUND = -5;//toc do di chuyen cua nen dat

#define BACKGROUND_STRET 1000
//mau sac transference
const int COLOR_KEY_R = 180;             
const int COLOR_KEY_G = 180;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0XFF;



namespace CommonFunction
{
	void LoadAudio(std::string path);
	bool CheckCollision(const SDL_Rect& obj1, const SDL_Rect& obj2);
	int Random(int max, int min);
	bool CheckFocusWithRect(const int& x, const int& y, SDL_Rect rect);
}

#endif