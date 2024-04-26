# GAME MYSTERIOUS_LANDS

### Ý tưởng: Xây dựng theo game Nonogram
##### Ban đầu:
>Cho nhân vật di chuyển -> gặp vật cản -> chơi các map của nonogram.   
##### Độ hoàn thiện về ý tưởng trong quá trình xây dựng game:
> Dựa trên luật chơi của Nonogram kết hợp với đồ họa để tạo source code không dựa trên source code khác, chỉ học đồ họa cần dùng cho game.

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
> - [X] Các ô sai sẽ được hiển thị khác với các ô còn lại
