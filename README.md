# GAME MYSTERIOUS_LANDS
Họ và tên: Lê Thị Thế Ngọc
Lớp: K68J
Trường Đại học Công Nghệ

[ToC]

### Ý tưởng: Xây dựng theo luật chơi của game Nonogram
#### Ban đầu:
>Cho nhân vật di chuyển -> gặp vật cản -> chơi các map của nonogram. 
#### Độ hoàn thiện về ý tưởng trong quá trình xây dựng game:
> Dựa trên luật chơi của Nonogram kết hợp với thư viện SDL để tạo source code không dựa trên source code khác, chỉ học đồ họa cần dùng cho game.

>Các map của game: 
> - [ ] Trước khi chơi game tạo nhiều ruơng
> - [X] Mỗi rương được random một số map cố định -> Người chơi di chuyển đến và chơi. 
> - [ ] Nếu chơi qua một rương thì rương sẽ được mở khóa
> - [X] Nếu không hoàn thiện hết các map của rương thì rương thì sẽ bị khóa
> - [ ] Trong khi chơi các rương không phân biệt thứ tự (Ví dụ chơi rương 1 nhưng không qua hết các map thì rương 1 bị khóa nhưng vẫn có thể sang chơi các rương 2,3...)

> Khi va chạm với rương và chơi các map
> - [X] Luật chơi tương tự Nonogram.
> - [X] Lấy ảnh dạng pixel để khi ấn vào các ô sẽ có màu thay vì ô đen trắng như game cổ điển đồng thời sẽ hiển thị ảnh khi kết thúc map --> Gây hứng thú cho người chơi.
> - [X] Mỗi map sẽ được khởi tạo 3 mạng. Nếu chọn sai một ô thì sẽ mất một mạng.
> - [X] Tạo sự kiện giữ và kéo chuột để thuận tiện cho người chơi thay vì phải ấn từng ô một.
> - [X] Các map được random mà không theo thứ tự cố định để nếu chơi thua muốn chơi lại thì sẽ không gây nhàm chán
> - [X] Các ô sai sẽ được hiển thị khác với các ô còn 
> - [X] 

## Luật chơi và cấu trúc game(source code):
- Khi nhân vật di chuyển (bằng các phím mũi tên ⬅➡⬆ ⬇ va chạm với rương sẽ bắt đầu chơi game logic.
 :pushpin:  *isNonogram = true*
![image](https://hackmd.io/_uploads/H1ZXqdtbC.png)

![Screenshot 2024-04-27 020307](https://hackmd.io/_uploads/HyADoutWR.png)
- Nhiệm vụ của người chơi là mở một hình ảnh được ẩn sau những ô màu trắng bằng cách tư duy logic. Người chơi sẽ xác định xem ô đó có được tô màu hay không dựa trên gợi ý từ các số ở mỗi cột và hàng.

- Chìa khóa để giải đố là các con số: chúng sẽ cho biết có bao nhiêu ô liền kề cần được tô màu. Khi bạn thấy có nhiều số nằm cạnh một hàm hoặc cột, chúng tượng trưng cho những cụm ô màu khác nhau. Điều quan trọng là luôn có ít nhất một ô trống giữa các cụm này. Ngoài ra , thứ tự số gợi ý thể hiện trình tự bạn phải theo khi tô màu các cụm. Các hàng và cột có số gợi ý được xây dựng bằng cách đếm các ô liên tiếp dựa trên map truyền vào và dùng SDL_TTF để render ra màn hình

    📌 Hàm *Sugget(), renderArrRow* và *renderArrCol* trong GameNonogram.cpp
    
- Nếu xác định ô đó là ô được tô màu thì ấn/kéo chuột trái, nếu muốn đánh dấu ô đó chắc chắn là X thì ấn/kéo chuột phải.

    📌 + Xử lí sự kiện chuột hàm *handleEvents()* trong game.cpp
            + *handleEventNgramClickLeft()* và *handleEventNgramClickRight()* trong gameNonogram.cpp
            + Hiển thị màu của ô trong *Nonogram()*
- Khi xác định đúng ô nào là ô được tô màu thì sẽ hiện màu của ô đó. Màu 1 ô sẽ là một phần của map(bức ảnh bí mật)

 ![Screenshot 2024-04-27 025732](https://hackmd.io/_uploads/Syev0qKZR.png)

- Nếu xác định ô nào là x thì sẽ hiện ô nền trắng X xám lên . Tất cả các ô X sẽ là màu nền của bức ảnh bí mật. ![x_black](https://hackmd.io/_uploads/ryvCEoFZC.png)

- Nếu xác định sai ô:
    - Ô được tô màu nhưng chọn X sẽ hiện ![red](https://hackmd.io/_uploads/BktjActWA.png)

    - Ô X nhưng lại chọn tô màu sẽ hiện ![x_red](https://hackmd.io/_uploads/H1F6A5Kb0.png)

- Khi click vào một ô thì sẽ đánh dấu ô đó đã được click (mảng *clicked* trong game.cpp)

- Về map: được tạo dựa trên các ảnh pixel, kích thước 15x15 (225 ô) . Các ảnh có thể hoàn toàn tự vẽ trên web https://www.pixilart.com/. Hiện tại đang có 20 map ứng với 20 bức ảnh và được random ngẫu nhiên ở mỗi lần chơi sao cho trước khi thua game thì không bị trùng map => Tạo hứng thú cho người chơi thay vì các map được load cố định và người chơi sẽ phải chơi đi chơi lại các ván.

📌 map được đọc từ file vào mapn[15][15] trong game.cpp

![Screenshot 2024-04-27 045206](https://hackmd.io/_uploads/rkp4fotWA.png)

![image](https://hackmd.io/_uploads/Syd7fjKWR.png)


- Khi chơi hết 3 mạng sẽ thua
![Screenshot 2024-04-27 021911](https://hackmd.io/_uploads/Sk4-xFK-C.png)

- Khi click hết 225 ô mà vẫn còn mạng thì thắng 1 map, được cộng 5 điểm, sau đó hiện nút continue, nếu click vào continue thì sẽ chơi map tiếp theo.
:pushpin: isContinue = true -> hàm *ContinuePlay()* trong game.cpp

![image](https://hackmd.io/_uploads/S1oKWsKbC.png)

- Nút exit để ra bên ngoài 

## Kỹ năng lập trình:
- Sử dụng các thư viện của SDL (bao gồm image,ttf,mixer)
- Mảng, vector
- Con trỏ
- Tách file, giải phóng bộ nhớ
- rand(), sinh số ngãu nhiên : random map
- Vòng lặp
- string: tên map,ảnh
- Đọc
## Nguồn tham khảo:
SDL: https://lazyfoo.net/tutorials/SDL/index.php

Image: 
- ảnh cho map https://www.pixilart.com/ (trang web tạo ảnh miễn phí bằng pixel)
- ảnh khác: trên https://www.freepik.com/ và tự chỉnh sửa bằng Adobe Illustrator
  
Âm thanh: https://pixabay.com/vi/sound-effects/search/incorrect/

> Game có thể chưa được hoàn thiện cần được cải thiện nhung đây là dự án mình tự làm nên khá hài lòng về nó.
> Game có thể được nâng cấp thêm nhiều map...

 Link demo:

