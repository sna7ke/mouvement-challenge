#include "include/raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define MAX_SPEED 50
#define SPRINT 100


typedef struct box {
	Vector2 Position;
	Vector2 Velocity;
	bool Sprinted;
}box;


int main(void)
{
   InitWindow(WIDTH,HEIGHT,"challenge");
   box player = {{WIDTH/2,HEIGHT/2},{0,0},false};
   Vector2 Force={0,0};
   Vector2 Motion={0,0};
   float Acceleration=10.0f;
   float Maximum=50.0f;
   SetTargetFPS(60);
   
   while(!WindowShouldClose()) {
   	 	Force.x=0;
   		Force.y=0;
   		
   	if (IsKeyDown(KEY_D)&& player.Velocity.x<Maximum){
   			Force.x=Acceleration;
	   }
	else if(IsKeyDown(KEY_A)&& player.Velocity.x>-Maximum) {
			Force.x=-Acceleration;
	}
	else if(IsKeyUp(KEY_A)&&IsKeyUp(KEY_D)&&!player.Sprinted) 
		{
			if (player.Velocity.x>0){
				Force.x=-10.0f;
			}
			else if(player.Velocity.x<0) {
				Force.x=10.0f;
			}
		}
	
	
	if(IsKeyDown(KEY_W)&& player.Velocity.y>-Maximum) {
			Force.y=-Acceleration;
	}
	else if(IsKeyDown(KEY_S)&& player.Velocity.y<Maximum) {
			Force.y=Acceleration;
	}
	
	else if(IsKeyUp(KEY_S)&&IsKeyUp(KEY_W)&&!player.Sprinted){
		
		if(player.Velocity.y>0){
			Force.y=-10.0f;
		}
		if(player.Velocity.y<0){
			Force.y=10.0f;
		}
	}
	
	if (IsKeyPressed(KEY_F)&&(!player.Sprinted)) {
		
		player.Sprinted=true;
		Acceleration=50.0f;
		Maximum=SPRINT;
		
	}
	if(Acceleration>10.0f){
		Acceleration+=-10.0f;
	} 
	else {
		Acceleration=10.0f;
		player.Sprinted=false;
		Maximum=MAX_SPEED;
	}
	
	
	
	player.Velocity.x+=Force.x;
	player.Velocity.y+=Force.y;
	
	Motion.x=(float) GetFrameTime() * player.Velocity.x;
	Motion.y=(float) GetFrameTime() * player.Velocity.y;
	
	player.Position.y+=Motion.y;
	player.Position.x+=Motion.x;
	
   	
	BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(player.Position.x,player.Position.y,30,30,RED);
	EndDrawing();
		
   }
   
}

