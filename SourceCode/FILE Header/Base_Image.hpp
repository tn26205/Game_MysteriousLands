#ifndef BASE_IMAGE_H_
#define BASE_IMAGE_H_

#include "Game.hpp"

class BaseImage
{
public:
    BaseImage();
    ~BaseImage();
    void SetRect(const int& x, const int& y) //ham set kich thuoc cho rect
    {
        rect.x = x;
        rect.y = y;
    }
    SDL_Rect GetRect() const {return rect;} // Ham lay ra rect cua tam anh
    SDL_Texture* GetImage() const {return p_image;}

    bool LoadImage(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();

protected: // protected cho phep truy cap cac lop ke thua con provited thi khong
    SDL_Texture* p_image;   // bien chuyen luu hinh anh
    SDL_Rect rect;          // bien chuyen luu kich thuoc


};

#endif // BASE_IMAGE_H_
