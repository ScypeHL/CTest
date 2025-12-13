#include "../Header/utils.h"

bool IsColliding(Mouse mouse, Entity _button)
{
    if(mouse.x >= _button.rect.x && mouse.y >= _button.rect.y && mouse.x <= _button.rect.x + _button.rect.w && mouse.y <= _button.rect.y + _button.rect.h) {return 1;}
    else {return 0;}
}
