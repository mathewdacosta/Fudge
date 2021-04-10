/**
 *  This file is part of Fudge, a lightweight wrapper for SDL_ttf. For more info, see https://github.com/mathewdacosta/Fudge.
 *
 *  Copyright (c) 2021 Mathew Dacosta
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#pragma once

#include <string>
#include <SDL_ttf.h>

#include "Common.h"
#include "Font.h"

enum class TextAlignHorizontal
{
    LEFT = 0,
    CENTER = 1,
    RIGHT = 2
};

enum class TextAlignVertical
{
    TOP = 0,
    CENTER = 1,
    BOTTOM = 2
};

namespace TextColor
{
    const SDL_Color WHITE = { 0xFF, 0xFF, 0xFF, 0xFF };
    const SDL_Color BLACK = { 0x00, 0x00, 0x00, 0xFF };
}

/// <summary> A TTF font with a given size. </summary>
class Font
{
private:
    SDL_Renderer* m_renderer;
    TTF_Font* m_font;
    int m_size_pt;

    void DrawToRenderer(SDL_Surface* text_surface, SDL_Rect* destRect) const;

public:
    Font(SDL_Renderer* renderer, std::string path, int pt = 16, int index = 0);
    ~Font();

    bool IsLoaded() const { return m_font != nullptr; }
    int GetSize() const { return m_size_pt; }

    SDL_Rect CalculateDestRect(std::string text, Vector2D& position, TextAlignHorizontal x_align, TextAlignVertical y_align) const;
    
    void DrawSolid(std::string text, Vector2D position, SDL_Color color = TextColor::WHITE, TextAlignHorizontal x_align = TextAlignHorizontal::LEFT, TextAlignVertical y_align = TextAlignVertical::TOP) const;
    void DrawShaded(std::string text, Vector2D position, SDL_Color fg_color = TextColor::WHITE, SDL_Color bg_color = TextColor::BLACK, TextAlignHorizontal x_align = TextAlignHorizontal::LEFT, TextAlignVertical y_align = TextAlignVertical::TOP) const;
    void DrawBlended(std::string text, Vector2D position, SDL_Color color = TextColor::WHITE, TextAlignHorizontal x_align = TextAlignHorizontal::LEFT, TextAlignVertical y_align = TextAlignVertical::TOP) const;
};
