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
#include "Font.h"

class TextBox
{
private:
    Font* m_font;
    std::string m_text;
    Vector2D m_position;
    SDL_Color m_text_color;
    SDL_Color m_bg_color;
    bool m_draw_bg;
    TextAlignHorizontal m_align_x;
    TextAlignVertical m_align_y;

public:
    TextBox(Font* font, std::string text = "", Vector2D position = { 0, 0 }, SDL_Color text_color = TextColor::WHITE, SDL_Color bg_color = TextColor::BLACK, bool draw_bg = false, TextAlignHorizontal align_x = TextAlignHorizontal::LEFT, TextAlignVertical align_y = TextAlignVertical::TOP);
    ~TextBox();

    Font* GetFont() const;
    std::string GetText() const;
    Vector2D GetPosition() const;
    SDL_Color GetTextColor() const;
    SDL_Color GetBgColor() const;
    bool IsDrawBg() const;
    TextAlignHorizontal GetAlignX() const;
    TextAlignVertical GetAlignY() const;
    
    void SetFont(Font* font);
    void SetText(std::string text);
    void SetPosition(Vector2D position);
    void SetTextColor(SDL_Color text_color);
    void SetBgColor(SDL_Color bg_color);
    void SetDrawBg(bool draw_bg);
    void SetAlignX(TextAlignHorizontal align_x);
    void SetAlignY(TextAlignVertical align_y);
    
    void Draw() const;
    SDL_Rect GetBoundingBox();
};
