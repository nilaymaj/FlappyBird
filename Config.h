#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_SHOW_TIME 3.0
#define SPLASH_BACKGROUND_FILEPATH "resources/res/SplashBackground.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "resources/res/sky.png"
#define MAIN_MENU_TITLE_FILEPATH "resources/res/title.png"
#define MAIN_MENU_PLAYBUTTON_FILEPATH "resources/res/PlayButton.png"

#define GAME_BACKGROUND_FILEPATH "resources/res/sky.png"

#define GAME_OVER_BACKGROUND_FILEPATH "resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "resources/res/Game-Over-Body.png"

#define PIPE_UP_FILEPATH "resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "resources/res/PipeDown.png"
#define BASE_PIPE_SPAWN_FREQUENCY 1.5f

#define BASE_GAME_SPEED 300.f

#define LAND_FILEPATH "resources/res/land.png"

#define PIPE_GAP_HEIGHT 250.f
#define PIPE_GAP_VERT_MARGIN 150.f

#define BIRD_LEFT_MARGIN SCREEN_WIDTH/4.f

#define BIRD1_FILEPATH "resources/res/bird-01.png"
#define BIRD2_FILEPATH "resources/res/bird-02.png"
#define BIRD3_FILEPATH "resources/res/bird-03.png"
#define BIRD4_FILEPATH "resources/res/bird-04.png"

#define BIRD_ANIMATION_SPEED 0.4f
#define BIRD_JUMP_Y_SPEED 700.f
#define BIRD_GRAVITY 2250.f

#define FLASH_SPEED 2250.f

#define SCORE_LINE_FILEPATH "resources/res/InvisibleScoringPipe.png"
#define FLAPPY_FONT_FILEPATH "resources/fonts/FlappyFont.ttf"

#define GAME_OVER_APPEAR_TIME 1.5f
#define HIGH_SCORE_FILEPATH "resources/highscore.txt"

#define PLATINUM_SCORE 100
#define GOLD_SCORE 50
#define SILVER_SCORE 25

#define PLATINUM_MEDAL_FILEPATH "resources/res/Platinum-Medal.png"
#define GOLD_MEDAL_FILEPATH "resources/res/Gold-Medal.png"
#define SILVER_MEDAL_FILEPATH "resources/res/Silver-Medal.png"
#define BRONZE_MEDAL_FILEPATH "resources/res/Bronze-Medal.png"

#define HIT_SOUND_FILEPATH "resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "resources/audio/Point.wav"
#define FLAP_SOUND_FILEPATH "resources/audio/Wing.wav"

enum PlayState {
    Ready, Playing, Crashed
};
