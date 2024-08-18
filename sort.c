#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int scr_width = 800;
  int scr_height = 600;
  char *text = "fuck all that WinAPI shit fr";

  InitWindow(scr_width, scr_height, "sorting algorithms");

  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(PURPLE);
    DrawText(text, 5, 5, 22, BLACK);
    //DrawLine(5, 27, 300, 27, BLACK);
    EndDrawing();
  }

  return 0;
}
