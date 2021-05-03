// Game_SDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CommonFunc.h"
#include "BaseObject.h"
#include "PlayerObject.h"
#include "TimeFps.h"
#include "Pipe.h"
#include "ScoreObject.h"
#include "Button.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 720

BaseObject g_background;

BaseObject g_ground;

BaseObject coin;

HightScore rate_;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
    {
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    g_window = SDL_CreateWindow("            FLAPPY BIRD          ",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    
    if (g_window == NULL)
        success = false;
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
        if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        {
            success = false;
        }
    }
    return success;
}


void close()
{
    g_background.Free();
    
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (InitData() == false)
    {
        return -1;
    }

    bool quite = false;
    TimeFps fps;
    HightScore H_S;
    

    Menu:
    BaseObject g_background2;
    BaseObject menu;
    BaseObject bird_img_;
    ButtonObject start;
    ButtonObject exit;
    ButtonObject rate;
    H_S.GetScore();
    H_S.loadImg(g_screen);
    H_S.SetRect();
    Mix_Music* music_menu;
    music_menu =  Mix_LoadMUS("audio//musicmenu.mp3");
    if (music_menu != NULL)
    {
        Mix_PlayMusic(music_menu, -1);
    }
    else
    {
        return -1;
    }

    bool ret_ = start.loadImage("image//play.png", g_screen);
    if (ret_ == false)
      {
          return -1;
      }
     ret_ = exit.loadImage("image//exit.png", g_screen);
    if (ret_ == false)
    {
        return -1;
    }
    ret_ = rate.loadImage("image//rateButton.png", g_screen);
    if (ret_ == false)
    {
        return -1;
    }
    ret_ = menu.loadImg("image//flappybird_img.png", g_screen);
    if (ret_ == false)
      {
          return -1;
      }
    ret_ = g_background2.loadImg("image//menuBG2.png", g_screen);
    if (ret_ == false)
    {
        return -1;
    }
    ret_ = bird_img_.loadImg("image//mid_bird2.png", g_screen);
    bool menu_check = true;
    int frame_ = 0;

    int  bgmenu_x_ = 0;
    int bg_val = 5;
    while (menu_check)
    {
        fps.start();
        SDL_RenderClear(g_screen);
        menu.SetRect((SCREEN_WIDTH - menu.GetRect().w) / 2, 10);
        start.SetRect(200, 200);
        exit.SetRect(600, 200);
        rate.SetRect(450, 500);
        
        if (frame_ > 12)
        {
            frame_ = 0;
        }
        switch (frame_)
        {
        case 0:
            bird_img_.loadImg("image//up_bird2.png", g_screen);
            break;
        case 4:
            bird_img_.loadImg("image//mid_bird2.png", g_screen);

            break;
        case 8:
            bird_img_.loadImg("image//down_bird2.png", g_screen);
            break;
        case 12:
            bird_img_.loadImg("image//mid_bird2.png", g_screen);
            break;
        }
        frame_++;
        bird_img_.SetRect(700, 50);
       
       g_background2.SetRect(bgmenu_x_, 0);
       bgmenu_x_-=bg_val;
       if (bgmenu_x_ <= -SCREEN_WIDTH)
       {
           bgmenu_x_ = 0;
       }
       g_background2.SetRect(bgmenu_x_, g_background2.GetRect().y);
       g_background2.Render(g_screen); 
        start.MouseEvent();
        if (start.GetIsTouch())
        {
            start.loadImage("image//play2.png", g_screen);
        }
        else
        {
            start.loadImage("image//play.png", g_screen);
        }
        if (start.GetIsPress())
        {
            start.SetIsPress(false);
            Mix_PauseMusic();
            goto start_game;
            menu_check = false;
        }
        exit.MouseEvent();
        if (exit.GetIsTouch())
        {
            exit.loadImage("image//exit2.png", g_screen);
        }
        else
        {
            exit.loadImage("image//exit.png", g_screen);
        }
       
        if (start.GetIsUse() || exit.GetIsPress() || exit.GetIsUse()||rate.GetIsUse())
        {
            quite = true;
            return 1;
        }
        rate.MouseEvent();
        
        menu.Render(g_screen);
        bird_img_.Render(g_screen);
        start.Show(g_screen);
        exit.Show(g_screen);
       
        if (rate.GetIsTouch())
        {
            H_S.Show(g_screen);

        }

        rate.Show(g_screen);



        int real_time_ = fps.get_ticks();
        int time_one_frame = 1000 / FRAMES_PER_SECOND;   // ms
        if (real_time_ < time_one_frame)
        {
            int delay_time = time_one_frame - real_time_;
            if (delay_time >= 0)
                SDL_Delay(delay_time);
        }

        SDL_RenderPresent(g_screen);
    }
    
    start_game:
    
    bool ret = g_ground.loadImg("image//ground3.png", g_screen);
    if (ret == false)
    {
        return -1;
    }

    
    ret = g_background.loadImg("image//bg.png", g_screen);
    if (ret == false)
    {
        return -1;
    }

   
    ret = coin.loadImg("image//coinDl.png", g_screen);
    if (ret == false)
    {
        return -1;
    }
    coin.SetRect(850, 10);

    int ground_x_ = 0;
    g_ground.SetRect(ground_x_, GROUND_MAP);

    int bg_x_ = 0;
    bg_val = 2;
    int ground_val = 5;
    g_background.SetRect(bg_x_, 0);
  
    BaseObject ready_go;
    ready_go.SetRect(450, 300);
    bool is_ready = true;
    int index_=0;

    //Khoi tao nhan vat
    PlayerObject Player;
    ret = Player.loadImg("image//mid_bird.png",g_screen);
    if (ret == false)
    {
        
        return - 1;
    }
    Player.SetRect(150, 200);

    PipeList listpipe;
    listpipe.InitList(g_screen);

    Mix_Music* music_play;
    music_play = Mix_LoadMUS("audio//musicplay.mp3");
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
    if (music_play != NULL)
    {
       
        Mix_PlayMusic(music_play, -1);
    }
    else
    {
        return -1;
    }
    
    //khoi tao score
    ScoreObject score;
    EffectCoin effect;
    effect.LoadImg("image//frameCoin2.png", g_screen);
    effect.set_clips();
    
    
    //Vong lap Game
    bool is_pause = false;
    while (!quite)
    {
        if (is_ready)
        {
           
            Player.SetVal(0);
            ground_val = 0;
            bg_val = 0;
            listpipe.SetVal(0);
           
            if (index_ > 2)
            {
                is_ready = false;
                index_ = 0;
                Player.SetVal(1);
                ground_val = 5;
                bg_val = 2;
                listpipe.SetVal(-5);   
            }
            if (index_ == 0)
            {
                ready_go.loadImg("image//3_img.png", g_screen);
            }
            if (index_ == 1)
            {
                ready_go.loadImg("image//2_img.png", g_screen);
            }
            if (index_ == 2)
            {
                ready_go.loadImg("image//1_img.png", g_screen);
            }
            SDL_Delay(1000);
            index_++;
        }
        fps.start();
        while (SDL_PollEvent(&g_event) != 0 && is_pause != true && is_ready == false)
        {
            if (g_event.type == SDL_QUIT)
            {
                quite = true;
            }
            Player.HandleInputAction(g_event, g_screen);
            if (g_event.type == SDL_KEYDOWN)
            {
                switch (g_event.key.keysym.sym)
                {
                case SDLK_x:
                    is_pause = true;
                   
                    Player.SetVal(0);
                    ground_val = 0;
                    bg_val = 0;
                    listpipe.SetVal(0);
                    
                    break;
                }
            }
        }
  
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR,
            RENDER_DRAW_COLOR,
            RENDER_DRAW_COLOR,
            RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        bg_x_ -= bg_val;
        if (bg_x_ < -SCREEN_WIDTH)
        {
            bg_x_ = 0;
        }
        g_background.SetRect(bg_x_, g_background.GetRect().y);
        g_background.Render(g_screen);
       
      
        listpipe.ShowList(g_screen,Player,score);
        effect.SetRect(Player.GetRect().x - 35, Player.GetRect().y - 12 - 35);
       //check pass, add diem
        if (score.GetAddScore() && is_pause == false)
        {
            score.Add();
            effect.SetEffect(true);
            score.SetAddScore(false);
        }
        listpipe.SetVal(-score.GetScoreVal() / 200 - 5);

       //check va  cham
        if (Player.GetCol())
        {
            Player.DoGround(g_screen);
            Player.SetCol(false);
        }

       /* bool falling = player.getfalling();*/
        Player.DoFalling(g_screen);
        Player.Show(g_screen);
        ground_x_ -= ground_val;
        if (ground_x_ <= -SCREEN_WIDTH)
        {
            ground_x_ = 0;
        }
        g_ground.SetRect(ground_x_, g_ground.GetRect().y);
        g_ground.Render(g_screen);

        //pause
        if (is_pause)
        {
            ButtonObject resume;
            resume.loadImage("image//resume.png", g_screen);
            resume.SetRect(450, 300);
           /* ButtonObject menuButton;
            menuButton.loadImage("image//menu.png", g_screen);
            menuButton.SetRect(600, 350);
            */
           /* menuButton.MouseEvent();*/
            
            //if (menuButton.GetIsPress())
            //{
            //    // game_over_time = false;
            //    is_pause = false;
            //    goto Menu;
            //}
            //if (menuButton.GetIsUse())
            //{
            //    is_pause = false;
            //    quite = true;

            //}
            resume.MouseEvent();  
            if (resume.GetIsPress())
            {
                is_pause = false;
                Player.SetVal(1);
                ground_val = 5;
                bg_val = 2;
                listpipe.SetVal(-5);
                is_ready = true;
            }
            if (resume.GetIsUse())
            {
                is_pause = false;
                quite = true;
            }
            resume.Show(g_screen);
           // menuButton.Show(g_screen);
        }
 
        score.InitScore(g_screen, 890, 920, 950,10);
        effect.Show(g_screen);
        score.ShowImg(g_screen);
        coin.Render(g_screen);
        if (is_ready)
        {
             ready_go.Render(g_screen);
        }
       
        
       
       
        SDL_RenderPresent(g_screen);

        int real_time_ = fps.get_ticks();
        int time_one_frame = 1000 / FRAMES_PER_SECOND;   // ms
        if (real_time_ < time_one_frame)
        {
            int delay_time = time_one_frame - real_time_;
            if(delay_time>=0)
                SDL_Delay(delay_time);
        }
        
        bool gameOver = Player.GetIsDie();
        cout << gameOver << endl;
        if (gameOver)
        {   
             //SDL_Delay(2000);
            //listpipe.SetStopMove(true);
            CommonFunction::LoadAudio("audio//die.wav");
            
            H_S.UpdateHightScore(score.GetScoreVal());
           // H_S.GetScore();
            int is_best = H_S.CheckScore(score.GetScoreVal());
            BaseObject The_Best;
           
            if (is_best == 0)
            {
                The_Best.loadImg("image//best_score_icon.png", g_screen);
            }
            if (is_best == 1)
            {
                The_Best.loadImg("image//hight_score_icon.png", g_screen);
            }
           
            bool game_over_time = true;
            BaseObject bg_game_over;
            bg_game_over.loadImg("image//bg.png", g_screen);
            BaseObject OverMenu;
            ButtonObject menuButton;
            ButtonObject replay;
            if (score.GetScoreVal() <= 20)
            {
               ret = OverMenu.loadImg("image//bronze.png", g_screen);
                   
            }
            if (score.GetScoreVal() > 20 && score.GetScoreVal() <= 50)
            {
              ret = OverMenu.loadImg("image//iron.png", g_screen);
            }
            if (score.GetScoreVal() > 50 && score.GetScoreVal() <= 100)
            {
                ret = OverMenu.loadImg("image//silver.png", g_screen);
            }
            if (score.GetScoreVal() > 100)
            {
                ret = OverMenu.loadImg("image//gold.png", g_screen);
            }
            while (game_over_time)
            {
                SDL_RenderClear(g_screen);
                menuButton.SetRect(600, 550);
                replay.SetRect(250, 550);
                menuButton.MouseEvent();
                if (menuButton.GetIsTouch())
                {
                    menuButton.loadImage("image//menu2.png", g_screen);
                }
                else
                {
                    menuButton.loadImage("image//menu.png", g_screen);
                }
                if (menuButton.GetIsPress())
                {
                    game_over_time = false;
                    goto Menu;

                }
                if (menuButton.GetIsUse())
                {
                    game_over_time = false;
                    quite = true;

                }
                replay.MouseEvent();
                if (replay.GetIsTouch())
                {
                    replay.loadImage("image//replay2.png", g_screen);
                }
                else
                {
                    replay.loadImage("image//replay.png", g_screen);
                }
                if (replay.GetIsPress())
                {
                    game_over_time = false;
                    goto start_game;
                }
                if (replay.GetIsUse())
                {
                    game_over_time = false;
                    quite = true;

                }
                OverMenu.SetRect((SCREEN_WIDTH - OverMenu.GetRect().w) / 2, (SCREEN_HEIGHT - OverMenu.GetRect().h) / 2);
                The_Best.SetRect((SCREEN_WIDTH - The_Best.GetRect().w) / 2, (SCREEN_HEIGHT - The_Best.GetRect().h) / 2);
                bg_game_over.SetRect(0, 0);
                score.InitScore(g_screen, 570, 600, 630, 400);
                bg_game_over.Render(g_screen);
                OverMenu.Render(g_screen);

                menuButton.Show(g_screen);
                replay.Show(g_screen);
                score.ShowImg(g_screen);
                The_Best.Render(g_screen);

                SDL_RenderPresent(g_screen);
                
               // quite = true;
            }
        } 
        
    }
  
    close();
    return 0;
}


















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and sele5ct the .sln file
