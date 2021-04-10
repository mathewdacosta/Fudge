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

#include "TextBox.h"

TextBox::TextBox(Font* font, std::string text, Vector2D position, SDL_Color text_color, SDL_Color bg_color, bool draw_bg, TextAlignHorizontal align_x, TextAlignVertical align_y) :
    m_font(font),
    m_text(text),
    m_position(position),
    m_text_color(text_color),
    m_bg_color(bg_color),
    m_draw_bg(draw_bg),
    m_align_x(align_x),
    m_align_y(align_y)
{
}

TextBox::~TextBox()
{
}

Font* TextBox::GetFont() const
{
    return m_font;
}

void TextBox::SetFont(Font* const font)
{
    m_font = font;
}

std::string TextBox::GetText() const
{
    return m_text;
}

void TextBox::SetText(std::string text)
{
    m_text = text;
}

Vector2D TextBox::GetPosition() const
{
    return m_position;
}

void TextBox::SetPosition(const Vector2D position)
{
    m_position = position;
}

SDL_Color TextBox::GetTextColor() const
{
    return m_text_color;
}

void TextBox::SetTextColor(const SDL_Color text_color)
{
    m_text_color = text_color;
}

SDL_Color TextBox::GetBgColor() const
{
    return m_bg_color;
}

void TextBox::SetBgColor(const SDL_Color bg_color)
{
    m_bg_color = bg_color;
}

bool TextBox::IsDrawBg() const
{
    return m_draw_bg;
}

void TextBox::SetDrawBg(const bool draw_bg)
{
    m_draw_bg = draw_bg;
}

TextAlignHorizontal TextBox::GetAlignX() const
{
    return m_align_x;
}

void TextBox::SetAlignX(const TextAlignHorizontal align_x)
{
    m_align_x = align_x;
}

TextAlignVertical TextBox::GetAlignY() const
{
    return m_align_y;
}

void TextBox::SetAlignY(const TextAlignVertical align_y)
{
    m_align_y = align_y;
}

void TextBox::Draw() const
{
    if (m_draw_bg)
        m_font->DrawShaded(m_text, m_position, m_text_color, m_bg_color, m_align_x, m_align_y);
    else
        m_font->DrawSolid(m_text, m_position, m_text_color, m_align_x, m_align_y);
}

SDL_Rect TextBox::GetBoundingBox()
{
    return m_font->CalculateDestRect(m_text, m_position, m_align_x, m_align_y);
}
