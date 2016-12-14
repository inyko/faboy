#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8
#define NUM_CHARS (sizeof("a") - 1)
#define Y_MIN 8
#define X_MAX (WIDTH - 16)
#define Y_MAX (HEIGHT - 8)

void check_player_buttons(){
  if (arduboy.pressed(RIGHT_BUTTON) && (player_x < X_MAX)) player_x++;
  if (arduboy.pressed(LEFT_BUTTON) && (player_x > 0)) player_x--;
  if (arduboy.pressed(DOWN_BUTTON) && (player_y < Y_MAX)) player_y++;
  if (arduboy.pressed(UP_BUTTON) && (player_y > Y_MIN)) player_y--;
  if (arduboy.pressed(B_BUTTON)){
    if (countdown <= 0){
      if (audio_enabled) tune.tone(300, 80);
      bx[shot_count] = player_x+16;
      by[shot_count] = player_y+1;
      shot_count++;
      if(shot_count > 16) shot_count= 0;
      countdown = 37;
    }
  }
  if (countdown != 0){
    countdown--;
  }
  if (arduboy.pressed(A_BUTTON) && bomb_num != 0 && bomb_countdown == 0){
    if (audio_enabled)tune.tone(80,1800);
    which_led = 2;
    led_countdown = 140;
    bomb_countdown = 140;
    bomb_rad = 1;
    bomb_x = player_x+8;
    bomb_y = player_y+4;
    timeGo = false;
    bomb_num--;
  }

  if (bomb_countdown != 0){
      bomb_countdown--;
  }
  else{
    timeGo = true;
  }
}

void check_pause_combo(){
  if(arduboy.pressed(RIGHT_BUTTON) && arduboy.pressed(LEFT_BUTTON)
  && arduboy.pressed(UP_BUTTON) && arduboy.pressed(DOWN_BUTTON)){
    if (pause_countdown <= 0){
      if (gamePaused == false){
        if (audio_enabled)tune.tone(800, 80);
        gamePaused = true;
        pause_countdown = 30;
      }
      else{
        if (audio_enabled)tune.tone(700, 80);
        gamePaused = false;
        pause_countdown = 30;
      }
    }
  }
  if (pause_countdown > 0)  pause_countdown--;
}

void check_player_bullets(){
  for (int i = 0; i <= 16; i++){
    if (bx[i] != NULL && by[i] != NULL){
      for (int e = 0; e <= max_enemies; e++){
        if ((bx[i] >= enemy_arr[e].x && bx[i] <= enemy_arr[e].x+enemy_arr[e].width
        && by[i] >= enemy_arr[e].y && by[i] <= enemy_arr[e].y+enemy_arr[e].height)
        ||(bx[i]+8 >= enemy_arr[e].x && bx[i]+8 <= enemy_arr[e].x+enemy_arr[e].width
        && by[i]+8 >= enemy_arr[e].y && by[i]+8 <= enemy_arr[e].y+enemy_arr[e].height)){
          enemy_arr[e].HP--;
          which_led = 2;
          led_countdown = 15;
          if (audio_enabled)tune.tone(100, 80);
          bx[i] = NULL;
          by[i] = NULL;
        }
      }
      if (bx[i] > X_MAX + 8){
        bx[i] = NULL;
        by[i] = NULL;
      }
      else{
        arduboy.drawBitmap(bx[i],by[i],shot,8,8,WHITE);
        if (!gamePaused)bx[i]++;
      }
    }
  }
}

void check_player_coll_items(){
  for (int i = 0; i<=5;i++){
    if((player_x >= item_arr[i].x && player_x <= item_arr[i].x+8
    && player_y >= item_arr[i].y && player_y <= item_arr[i].y+8)
    ||(player_x >= item_arr[i].x && player_x <= item_arr[i].x+8
    && player_y+8 >= item_arr[i].y && player_y+8 <= item_arr[i].y+8)
    ||(player_x +16 >= item_arr[i].x && player_x +16 <= item_arr[i].x+8
    && player_y >= item_arr[i].y && player_y <= item_arr[i].y+8)
    ||(player_x +16 >= item_arr[i].x && player_x +16 <= item_arr[i].x+8
    && player_y+8 >= item_arr[i].y && player_y+8 <= item_arr[i].y+8)){
      if(item_arr[i].itemType == true && item_arr[i].isItem){
        which_led = 3;
        led_countdown = 15;
        if (audio_enabled)tune.tone(500, 80);
        bomb_num++;
        if(bomb_num > 9) bomb_num = 9;
      }
      else if (item_arr[i].itemType == false && item_arr[i].isItem){
        which_led = 3;
        led_countdown = 15;
        if (audio_enabled)tune.tone(600, 80);
        player_HP++;
        if (player_HP >9) player_HP = 9;
      }
      item_arr[i].isItem = false;
    }
  }
}

void player_death_stuff(){
  if (!score_recorded) {
    write_High_Score();
    score_recorded = true;
  }
  if (death_countdown <= 180 && death_countdown > 165){
    arduboy.drawBitmap(player_x,player_y,shipexplode,16,8,WHITE);
    if (audio_enabled)tune.tone(60, 80);
    arduboy.setRGBled(255,0,0);
  }
  if (death_countdown <= 150 && death_countdown > 135){
    arduboy.drawBitmap(player_x,player_y,shipexplode2,16,8,WHITE);
    if (audio_enabled)tune.tone(50, 80);
    arduboy.setRGBled(200,0,0);
  }
  if (death_countdown <= 135 && death_countdown > 120){
    arduboy.drawBitmap(player_x,player_y,shipexplode3,16,8,WHITE);
    if (audio_enabled)tune.tone(40, 80);
    arduboy.setRGBled(150,0,0);
  }
  if (death_countdown <= 120 && death_countdown > 60){
    arduboy.drawBitmap(player_x,player_y,shipexplode4,16,8,WHITE);
    if (audio_enabled)tune.tone(30, 80);
    arduboy.setRGBled(100,0,0);
  }
  if (death_countdown != 60) death_countdown--;
  if (death_countdown == 60){
    arduboy.setRGBled(0,0,0);
    arduboy.setCursor((WIDTH/2) - ((sizeof("Game Over") - 1) * CHAR_WIDTH /2)
    , (HEIGHT/2) - (CHAR_HEIGHT / 2));
    arduboy.print("Game Over");
    arduboy.setCursor((WIDTH/2) - ((sizeof("Press fire") - 1) * CHAR_WIDTH /2)
    , (HEIGHT/2) - (CHAR_HEIGHT / 2) + 10);
    arduboy.print("Press fire");
    if (death_countdown == 60 && (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON))){
      if (audio_enabled)tune.tone(800, 80);
      reset_default_values();
    }
  }
}

void check_player_HP(){
  if (player_HP <= 0){
    player_is_alive = false;
    if (death_countdown == 0){
      death_countdown = 180;
    }
    player_death_stuff();
  }
}



void check_player_invincibility(){
  if (player_inv_countdown > 0 ){
    player_inv_countdown--;
    player_HP = player_last_HP;
  }
}

void player_animation(){
  if (player_inv_countdown != 0){
    if (framecount<15){
      arduboy.drawBitmap(player_x,player_y,shipwhole,16,8,WHITE);
      player_last_spr = true;
    }
    else if ((framecount>=30 && framecount<45))  {
      arduboy.drawBitmap(player_x,player_y,shipwhole1,16,8,WHITE);
      player_last_spr = false;
    }
    else if ((framecount >=15 && framecount<30) || (framecount >=45)){
      //do nothing, blank sprite.
    }
  }
  else{
    if (framecount<15 || (framecount>=30 && framecount<45)){
      arduboy.drawBitmap(player_x,player_y,shipwhole,16,8,WHITE);
      player_last_spr = true;
    }
    
    else if ((framecount>=15 && framecount<30) || framecount>=45)  {
      arduboy.drawBitmap(player_x,player_y,shipwhole1,16,8,WHITE);
      player_last_spr = false;
    }
  }
  framecount++;
  if (framecount > 59){framecount =0;}
  if (bomb_rad != 0 && bomb_rad <= 140){
    arduboy.drawCircle(bomb_x, bomb_y, bomb_rad, WHITE);
    bomb_rad++;
  }
}

void player_draw_pause(){
  if (player_last_spr){
    arduboy.drawBitmap(player_x,player_y,shipwhole,16,8,WHITE);
  }
  else{
    arduboy.drawBitmap(player_x,player_y,shipwhole1,16,8,WHITE);
  }
  check_player_bullets();
  if (bomb_rad != 0 && bomb_rad <= 140){
    arduboy.drawCircle(bomb_x, bomb_y, bomb_rad, WHITE);
  }
}

void player_update(){
  if (player_is_alive ==false){
    check_player_HP();
    return;
  }
  check_player_invincibility();
  check_player_HP();
  check_player_buttons();
  check_player_bullets();
  check_player_coll_items();
  player_animation();
}


