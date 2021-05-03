#include "ScoreObject.h"

ScoreObject::ScoreObject()
{
	//add_score_ = false;
	score_val_ = 0;
	
}

ScoreObject::~ScoreObject()
{

}

//void ScoreObject::CheckAddScore(const SDL_Rect& obj1, const SDL_Rect& obj2)
//{
//	int del_size_ = obj2.x + obj2.w - obj1.x;
//	if ( del_size_ >= 0 && del_size_ <= 5)
//	{
//		this->SetAddScore(true);
//	}
//}

void ScoreObject::Add()
{
		CommonFunction::LoadAudio("audio//point.wav");
		this->score_val_+=1;
		//this->SetAddScore(false);
}

void ScoreObject::InitScore(SDL_Renderer* screen,int x_tram,int x_chuc,int x_dv,int y )
{
	int score_ = score_val_, tram_, chuc_, dv_;
	dv_ = score_ % 10;
	score_ /= 10;
	chuc_ = score_ % 10;
	tram_ = score_ / 10;

	img_tram_.SetRect(x_tram, y);
	img_chuc_.SetRect(x_chuc, y);
	img_dv_.SetRect(x_dv, y);

	bool ret=img_tram_.loadImg(numb[tram_], screen);
	ret=img_chuc_.loadImg(numb[chuc_], screen);
	ret=img_dv_.loadImg(numb[dv_], screen);
	
}

void ScoreObject::ShowImg(SDL_Renderer* screen)
{
	img_tram_.Render(screen);
	img_chuc_.Render(screen);
	img_dv_.Render(screen);
}



//=========================================================================
EffectCoin::EffectCoin()
{
	x_pos_ = 0;
	y_pos_ = 0;
	frame_ = 0;
	width_frame_ = 0;
	height_frame_ = 0;
	check_effect_ = false;
}

EffectCoin::~EffectCoin()
{

}

bool EffectCoin::LoadImg(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::loadImg(path, screen);
	if (ret == true)
	{
		width_frame_ = rect_.w / 4;
		height_frame_ = rect_.h;
	}
	return ret;
}

void EffectCoin::SetRect(const int& x, const int& y)
{
	this->x_pos_ = x;
	this->y_pos_ = y;
}
void EffectCoin::set_clips()
{
	if (width_frame_ > 0 && height_frame_ > 0)
	{
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = width_frame_;
		frame_clip_[0].h = height_frame_;

		frame_clip_[1].x = width_frame_;
		frame_clip_[1].y = 0;
		frame_clip_[1].w = width_frame_;
		frame_clip_[1].h = height_frame_;

		frame_clip_[2].x = width_frame_ * 2;
		frame_clip_[2].y = 0;
		frame_clip_[2].w = width_frame_;
		frame_clip_[2].h = height_frame_;

		frame_clip_[3].x = width_frame_ * 3;
		frame_clip_[3].y = 0;
		frame_clip_[3].w = width_frame_;
		frame_clip_[3].h = height_frame_;

	}
}

void EffectCoin::Show(SDL_Renderer *des)
{
	//LoadImg("image//frameCoin2.png", des);
	
	if (this->GetEffect())
	{
		if (frame_ > 11)
			{
				this->SetEffect(false);
				frame_ = 0;
			}
		rect_.x = x_pos_;
		rect_.y = y_pos_;

		SDL_Rect* current_clip = &frame_clip_[frame_ / 4];
		SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };
		SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
		frame_++;
	}
}
 
//===========================
HightScore::HightScore()
{
	for (int i = 0; i < 3; i++)
	{
		hight_score[i].val_ = 0;;
	}
}
HightScore::~HightScore()
{


}

void HightScore::UpdateHightScore(int score)
{
	vector<int>h_score;
	h_score.push_back(score);
	fstream file;
	//lay diem trong file
	file.open("hight_score.txt",ios::in);
	if(file.fail())
	{
		cout << "Fail open file!" << endl;
	}
	int n;
	while (file >> n)
	{
		h_score.push_back(n);
	}
	file.close();

	//sap xep lai diem va ghi vao file
    file.open("hight_score.txt", ios::out);
	sort(h_score.begin(), h_score.end(),std:: greater<int>());
	
	for (int i = 0; i < 3; i++)
	{
		hight_score[i].val_ = h_score[i];
		file << h_score[i] << " ";
	}
	file.close();
	

}


void HightScore::GetScore()
{
	fstream file;
	vector<int>h_score;
	file.open("hight_score.txt", ios::in);
	
	while (file.fail())
	{
		cout << "Fail open file!" << endl;
	}
	int n;
	while (file >> n)
	{
		h_score.push_back(n);
	}
	file.close();
	for (int i = 0; i < 3; i++) 
	{
		hight_score[i].val_ = h_score[i];
		//cout << hight_score[i].val_ << " ";
		
	}
	cout << endl;
}
int HightScore::CheckScore(int score)
{
	int result = -1;
	if (score == hight_score[0].val_)
	{
		result = 0;
	}
	if (score == hight_score[1].val_ || score == hight_score[2].val_)
	{
		result = 1;
	}
	return result;
}
bool HightScore::loadImg(SDL_Renderer* screen)
{
	bool ret;
	ret = transcript_.loadImg("image//hight_score (1).png", screen);
	//load anh medal
	for (int i = 0; i < 3; i++)
	{
		if (hight_score[i].val_ <= 20)
		{
			ret = hight_score[i].medal_.loadImg("image//bronze_medal.png", screen);

		}
		if (hight_score[i].val_ > 20 && hight_score[i].val_ <= 50)
		{
			ret = hight_score[i].medal_.loadImg("image//iron_medal.png", screen);
		}
		if (hight_score[i].val_ > 50 && hight_score[i].val_ <= 100)
		{
			ret = hight_score[i].medal_.loadImg("image//silver_medal.png", screen);
		}
		if (hight_score[i].val_ > 100)
		{
			ret = hight_score[i].medal_.loadImg("image//gold_medal.png", screen);
		}
	}
	//load anh score

	for (int i = 0; i < 3; i++)
	{
		int score_ = hight_score[i].val_, tram_, chuc_, dv_;
		dv_ = score_ % 10;
		score_ /= 10;
		chuc_ = score_ % 10;
		tram_ = score_ / 10;

		ret = hight_score[i].tram_.loadImg(numb_50x70[tram_], screen);
		ret = hight_score[i].chuc_.loadImg(numb_50x70[chuc_], screen);
		ret = hight_score[i].dv_.loadImg(numb_50x70[dv_], screen);
		
	}
	return ret;

}
void HightScore::SetRect()
{
	transcript_.SetRect(100, 0);

	hight_score[0].medal_.SetRect(340, 160);
	hight_score[1].medal_.SetRect(340, 260);
	hight_score[2].medal_.SetRect(340, 360);

	hight_score[0].tram_.SetRect(460, 160);
	hight_score[0].chuc_.SetRect(520, 160);
	hight_score[0].dv_.SetRect(580, 160);

	hight_score[1].tram_.SetRect(460, 260);
	hight_score[1].chuc_.SetRect(520, 260);
	hight_score[1].dv_.SetRect(580, 260);

	hight_score[2].tram_.SetRect(460, 360);
	hight_score[2].chuc_.SetRect(520, 360);
	hight_score[2].dv_.SetRect(580, 360);

}

void HightScore::Show(SDL_Renderer* screen)
{
	transcript_.Render(screen);

	for (int i = 0; i < 3; i++)
	{
		hight_score[i].medal_.Render(screen);
		hight_score[i].tram_.Render(screen);
		hight_score[i].chuc_.Render(screen);
		hight_score[i].dv_.Render(screen);

	}



}
