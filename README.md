# Fudge

A lightweight text box library for SDL, using [SDL_ttf](http://www.libsdl.org/projects/SDL_ttf) (which in turn is a SDL-friendly wrapper for the [FreeType](https://www.freetype.org/) text rendering library).

## Usage

```cpp
#include "Font.h"
#include "TextBox.h"

/* SDL_Renderer* renderer = ...; */

// Load font (Lato, 16pt, font index 2)
Font* font = new Font(renderer, "Fonts/Lato.ttf", 16, 2);
if (!font->IsLoaded()) return;

// Create text box
TextBox* text_1p = new TextBox(font, "Singleplayer", { 256, 220 }, TextColor::WHITE, TextColor::BLACK, false, TextAlignHorizontal::LEFT);
TextBox* text_2p = new TextBox(font, "Multiplayer", { 256, 240 }, TextColor::WHITE, TextColor::BLACK, true, TextAlignHorizontal::RIGHT);

/* int mouse_x, mouse_y = ...; */

// Check mouse hover
SDL_Rect bounding_box = text_1p->GetBoundingBox();
if (mouse_x > bounding_box.x && mouse_x < bounding_box.x + bounding_box.w &&
    mouse_y > bounding_box.y && mouse_y < bounding_box.y + bounding_box.h)
{
    // Change text params
    text_1p->SetText("> Singleplayer");
    text_1p->SetDrawBg(true);
}

// Draw the text!
text_1p->Draw();
```

## Source code and license

The source code for Fudge can be found here: https://github.com/mathewdacosta/Fudge

Fudge is released under the MIT license, which can be found at the root of the source repository.

As of 11th April 2021, SDL_ttf is available under the [zlib license](https://github.com/libsdl-org/SDL_ttf/blob/9a7ef3fb640a1f086d9b02954c3b4bbfb3578871/COPYING.txt),
and FreeType is available under [either the FreeType License or GNU GPLv2](https://gitlab.freedesktop.org/freetype/freetype/-/blob/f9350be1e45baa1c29f7551274982262f8e769ce/LICENSE.TXT).
