#include "BaseObject.h"

BaseObject::BaseObject()
{
	is_back_ = false;
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}
BaseObject::~BaseObject()
{
	Free();
}

bool BaseObject::loadImg(std::string path, SDL_Renderer* screen)
{
	Free();
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL)
	{
		//color key image (loai bo background anh)
		Uint32 key = SDL_MapRGB(load_surface->format,
			COLOR_KEY_R,
			COLOR_KEY_G,
			COLOR_KEY_B);

		SDL_SetColorKey(load_surface, SDL_TRUE, key);
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL)
		{
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);
	}
	p_object_ = new_texture;
	return p_object_ != NULL;
}
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip /*=NULL*/)
{
	SDL_Rect renderQuad= { rect_.x, rect_.y, rect_.w, rect_.h };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}

void BaseObject::Free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}
void BaseObject::DoRun(int x_val)
{
	this->rect_.x += x_val;
	if (rect_.x + rect_.w < 0)
	{
		is_back_ = true;
	}
}
void BaseObject::SetXPos(const int& xp)
{
	SDL_Rect rect = this->GetRect();
	this->SetRect(xp, rect.y);
}

void BaseObject::SetRect(const int& x, const int& y)
{
	rect_.x = x;
	rect_.y = y;

}