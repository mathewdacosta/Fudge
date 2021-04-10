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

#include "Font.h"

#include <iostream>

Font::Font(SDL_Renderer* renderer, std::string path, int pt, int index) :
    m_renderer(renderer),
    m_size_pt(pt)
{
    m_font = TTF_OpenFontIndex(path.c_str(), pt, index);
    if (!m_font)
    {
        std::cout << "Loading of font '" << path << "' failed. Error: " << TTF_GetError() << std::endl;
        m_font = nullptr;
    }
}

Font::~Font()
{
    if (m_font != nullptr)
    {
        TTF_CloseFont(m_font);
        m_font = nullptr;
    }
}

SDL_Rect Font::CalculateDestRect(std::string text, Vector2D& position, TextAlignHorizontal x_align, TextAlignVertical y_align) const
{
    int sizeX, sizeY = 0;

    TTF_SizeUTF8(m_font, text.c_str(), &sizeX, &sizeY);

    const int offsetX = sizeX * static_cast<int> (x_align) / 2.0f;
    const int offsetY = sizeY * static_cast<int> (y_align) / 2.0f;
    
    const SDL_Rect rect = {
        position.x - offsetX,
        position.y - offsetY,
        sizeX,
        sizeY
    };

    return rect;
}

void Font::DrawToRenderer(SDL_Surface* text_surface, SDL_Rect* dest_rect) const
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
    SDL_RenderCopy(m_renderer, texture, nullptr, dest_rect);
    SDL_DestroyTexture(texture);
}

void Font::DrawSolid(std::string text, Vector2D position, SDL_Color color, TextAlignHorizontal x_align, TextAlignVertical y_align) const
{
    if (m_font == nullptr)
    {
        std::cout << "Font is not loaded - can't render solid text!" << std::endl;
        return;
    }
    
    SDL_Rect destRect = CalculateDestRect(text, position, x_align, y_align);
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(m_font, text.c_str(), color);
    DrawToRenderer(textSurface, &destRect);
    SDL_FreeSurface(textSurface);
}

void Font::DrawShaded(std::string text, Vector2D position, SDL_Color fg_color, SDL_Color bg_color, TextAlignHorizontal x_align, TextAlignVertical y_align) const
{
    if (m_font == nullptr)
    {
        std::cout << "Font is not loaded - can't render shaded text!" << std::endl;
        return;
    }
    
    SDL_Rect destRect = CalculateDestRect(text, position, x_align, y_align);
    SDL_Surface* textSurface = TTF_RenderUTF8_Shaded(m_font, text.c_str(), fg_color, bg_color);
    DrawToRenderer(textSurface, &destRect);
    SDL_FreeSurface(textSurface);
}

void Font::DrawBlended(std::string text, Vector2D position, SDL_Color color, TextAlignHorizontal x_align, TextAlignVertical y_align) const
{
    if (m_font == nullptr)
    {
        std::cout << "Font is not loaded - can't render blended text!" << std::endl;
        return;
    }
    
    SDL_Rect destRect = CalculateDestRect(text, position, x_align, y_align);
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended(m_font, text.c_str(), color);
    DrawToRenderer(textSurface, &destRect);
    SDL_FreeSurface(textSurface);
}
