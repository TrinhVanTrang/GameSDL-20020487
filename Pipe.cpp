#include "Pipe.h"

PipeObject::PipeObject()
{
	is_back_ = false;
}
PipeObject::~PipeObject()
{

}

bool PipeObject::LoadImg(std ::string path, SDL_Renderer* screen)
{
	bool ret = loadImg(path, screen);
	return ret;
}

void PipeObject::SetPos(const int &x,const int &y)
{
	this->SetRect(x, y);
}

void PipeObject::SetXPos(const int& x)
{
	SDL_Rect rect = this->GetRect();
	this->SetRect(x, rect.y);
}

void PipeObject::ShowImg(SDL_Renderer* screen)
{
	this->Render(screen);
}

void PipeObject::DoRun(int x_val)
{
	this->rect_.x += x_val;
	if (rect_.x + rect_.w < 0)
	{
		is_back_ = true;
	}
}

DoublePipe::DoublePipe()
{
	is_back_ = false;
	is_pass_ = false;
	is_pause_ = false;
	x_val_ = -5;
	//y_val_ = 0;
	d_height_ = 150;
}

DoublePipe::~DoublePipe()
{

}

void DoublePipe::Init(SDL_Renderer* screen, const int& xpos)
{
	up_pipe_.LoadImg("image//up_pipe.png", screen);
	down_pipe_.LoadImg("image//down_pipe.png", screen);
	down_pipe_.SetPos(xpos, CommonFunction::Random(150, -150) + 550 - d_height_);
	up_pipe_.SetPos(xpos, down_pipe_.GetRect().y - d_height_ - 520);

	/*up_tree_.loadimage("image//frametree_up.png", screen);
	down_tree_.loadimage("image//frametree_down.png", screen);
	up_tree_.SetPos(xpos, up_pipe_.GetRect().y + up_pipe_.GetRect().h - up_tree_.GetRect().w);
	down_tree_.SetPos(xpos, down_pipe_.GetRect().y );*/
	
}

void DoublePipe::ShowImage(SDL_Renderer* screen)
{
	//down_tree_.Show(screen);
	down_pipe_.ShowImg(screen);

	//up_tree_.Show(screen);
	up_pipe_.ShowImg(screen);

}

void DoublePipe::Move()
{
	down_pipe_.DoRun(x_val_);
	up_pipe_.DoRun(x_val_);
	/*down_tree_.DoRun(x_val_);
	up_tree_.DoRun(x_val_);*/
	if(down_pipe_.GetStateBack() || up_pipe_.GetStateBack())
	{
		is_back_ = true;
	}
}



void DoublePipe::SetIsBack(bool b)
{
	is_back_ = b;
	down_pipe_.SetBack(b);
	//down_tree_.SetBack(b);
	up_pipe_.SetBack(b);
	//up_tree_.SetBack(b);

}
void DoublePipe::SetXRect(const int& xp)
{
	down_pipe_.SetXPos(xp);
	//down_tree_.SetXPos(xp);
	up_pipe_.SetXPos(xp);
	//up_tree_.SetXPos(xp);
	

}
int DoublePipe::GetXpos()
{
	return down_pipe_.GetXPos();
}
void DoublePipe::CheckPass(SDL_Rect obj)
{
	int del = down_pipe_.GetRect().x + down_pipe_.GetRect().w - obj.x;

	if (del >= 0 && del <= 5)
	{
		is_pass_ = true;
	}
}
void DoublePipe::SetVal(int v)
{
	x_val_ = v;
}
bool DoublePipe::CheckCol(SDL_Rect obj)
{
	if (CommonFunction::CheckCollision(obj, down_pipe_.GetRect()) ||
		CommonFunction::CheckCollision(obj, up_pipe_.GetRect()) /*||
		CommonFunction::CheckCollision(obj, up_tree_.GetRect()) ||
		CommonFunction::CheckCollision(obj, down_tree_.GetRect())*/)
	{
		return true;
	}
	return false;
}

//void DoublePipe::Appear()
//{
//	int rand = CommonFunction::Random(3, 1);
//	if (rand == 1)
//	{
//		up_tree_.DoAppear(y_val_);
//		if (up_tree_.GetRect().y + up_tree_.GetRect().h - up_pipe_.GetRect().y - up_pipe_.GetRect().h == 100)
//		{
//			y_val_ = 0;
//		}
//	}
//	if (rand == 2)
//	{
//		down_tree_.DoAppear(-y_val_);
//		if (down_tree_.GetRect().y  - down_pipe_.GetRect().y  == -100)
//		{
//			y_val_ = 0;
//		}
//	}
//	if (rand == 3)
//	{
//		up_tree_.DoAppear(y_val_/2);
//		down_tree_.DoAppear(-y_val_/2);
//		if (up_tree_.GetRect().y + up_tree_.GetRect().h - up_pipe_.GetRect().y - up_pipe_.GetRect().h == 50||
//			down_tree_.GetRect().y - down_pipe_.GetRect().y == -50)
//		{
//			y_val_ = 0;
//		}
//		
//	}
//}

//=========================

PipeList::PipeList()
{
	is_col_ = false;
	stop_move_ = false;
	d_width_ = 200;
	
}

PipeList::~PipeList()
{
	DeleteList();
}

void PipeList::DeleteList()
{
	for (int i = 0; i < list_.size(); i++)
	{
		DoublePipe* p_pipe = list_.at(i);
		delete p_pipe;
		p_pipe = NULL;
	}
	list_.clear();
}

void PipeList::SetVal(int x)
{
	for (int i = 0; i < list_.size(); i++)
	{
		DoublePipe* p_pipe = list_.at(i);
		p_pipe->SetVal(x);
	}
	
}

void PipeList::InitList(SDL_Renderer* screen)
{
	DoublePipe* pipe1 = new DoublePipe;
	DoublePipe* pipe2 = new DoublePipe;
	DoublePipe* pipe3 = new DoublePipe;
	DoublePipe* pipe4 = new DoublePipe;

	DoublePipe* pipe5 = new DoublePipe;
	DoublePipe* pipe6 = new DoublePipe;
	DoublePipe* pipe7 = new DoublePipe;

	pipe1->Init(screen, SCREEN_WIDTH + d_width_ * 1);
	pipe2->Init(screen, SCREEN_WIDTH + d_width_ * 2);
	pipe3->Init(screen, SCREEN_WIDTH + d_width_ * 3);
	pipe4->Init(screen, SCREEN_WIDTH + d_width_ * 4);
	pipe5->Init(screen, SCREEN_WIDTH + d_width_ * 5);
	pipe6->Init(screen, SCREEN_WIDTH + d_width_ * 6);
	pipe7->Init(screen, SCREEN_WIDTH + d_width_ * 7);

	list_.push_back(pipe1);
	list_.push_back(pipe2);
	list_.push_back(pipe3);
	list_.push_back(pipe4);
	list_.push_back(pipe5);
	list_.push_back(pipe6);
	list_.push_back(pipe7);

}

void PipeList::ShowList(SDL_Renderer* screen, PlayerObject &obj,ScoreObject &scr)
{
	 
		for (int i = 0; i < list_.size(); i++)
		{
			DoublePipe* p_pipe = list_.at(i);
			p_pipe->Move();
			if (!stop_move_)
			{

				if (p_pipe->GetBack())
				{
					DoublePipe* temp_pipe = list_.at((i + 6) % 7);
					p_pipe->SetXRect(temp_pipe->GetXpos() + 200);
					p_pipe->SetIsBack(false);
				}
				//p_pipe->Appear();
				p_pipe->CheckPass(obj.GetRect());
				if (p_pipe->GetIsPass())
				{
					scr.SetAddScore(true);
					p_pipe->SetIsPass(false);
				}

				if (p_pipe->CheckCol(obj.GetRect()))
				{
					obj.SetCol(true);
				}
			}
		
		p_pipe->ShowImage(screen);
	}
}

//==========================================

TreeObject::TreeObject()
{
	is_back_ = false;;
	is_appear_ = false;
	x_pos_ = 0;
	y_pos_ = 0;
	frame_ = 0;
	width_frame_ = 0;
	height_frame_ = 0;
}

TreeObject::~TreeObject()
{

}

bool TreeObject::loadimage(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::loadImg(path, screen);
	if (ret == true)
	{
		width_frame_ = rect_.w / 4;
		height_frame_ = rect_.h;
	}
	return ret;
}

void TreeObject::Show(SDL_Renderer* des)
{
	if (frame_ > 11)
	{
		frame_ = 0;
	}
	rect_.x = x_pos_;
	rect_.y = y_pos_;

	SDL_Rect* current_clip = &frame_clip_[frame_ / 4];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };
	SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);
	frame_++;
}

void TreeObject::set_clips()
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

void TreeObject::DoRun(int x_val)
{
	this->rect_.x += x_val;
	if (rect_.x + rect_.w < 0)
	{
		is_back_ = true;
	}
}

void TreeObject::SetPos(const int& x, const int& y)
{
	rect_.x = x;
	rect_.y = y;
}

void TreeObject::DoAppear(int y_val)
{
	if (this->GetAppear())
	{
		this->rect_.y += y_val;
	}

}