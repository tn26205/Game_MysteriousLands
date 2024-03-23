#include "Base_Image.hpp"

BaseImage::BaseImage()
{
    p_image = NULL;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;

}

BaseImage::~BaseImage()
{
    Free();
}

bool BaseImage::LoadImage(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;    // bien kqua

    SDL_Surface* load_surface = IMG_Load(path.c_str());    //Ham load anh tra ra surface
    if(load_surface != NULL)    //Kiem tra xem co loi hay khong
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface -> format, COLOR_KEY_R,COLOR_KEY_G,COLOR_KEY_B));
        // Dung COLOR_KEY_ de xoa nen cho doi tuong. tuy nhien can chu y ve thong so cua mau sao cho khop
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface); // Chuyen surface ve texture
        if(new_texture != NULL){
            rect.w = load_surface->w;
            rect.h = load_surface->h;
            //toan bo thong so cua image dang nam trong new_texture
            // khi load thanh cong thi phai gan ca thong so cho doi tuong BaseIamge
        }

        SDL_FreeSurface(load_surface); //vi toan bo surface duoc chuyen sang new_texture nen ta se xoa surface di
    }

    p_image = new_texture;

    return p_image != NULL;     //Neu p_image khac NULL thi se tra ve 1 con khong thi se tra ve 0
    // sau khi goi ham LoadImage nay thi da co thong tin ve p_image va rect (trong protected cua class)
}

void BaseImage::Render(SDL_Renderer* des, const SDL_Rect* clip /* =NULL */)
{
    SDL_Rect renderquad = {rect.x, rect.y, rect.w, rect.h};     //Bao gom vi tri va kich thuoc tam anh

    SDL_RenderCopy(des, p_image, clip, &renderquad); // day toan bo thong so cua p_image len des voi kich thuoc va vi tri nam trong renderquad
}

void BaseImage::Free() // giai phong cac doi tuong
{
    if(p_image != NULL)
    {
        SDL_DestroyTexture(p_image); // pha huy cua so
        p_image = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}
