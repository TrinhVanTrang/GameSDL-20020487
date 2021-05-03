1.Các đối tượng trong trò chơi 
-Bird là nhân vật chính của trò chơi.Bird có thể di chuyển lên xuống theo sự điều khiển của người chơi.

-Pipe là các đối tượng mà bird phải vượt qua trong suốt trò chơi.Pipe sẽ di chuyển liên tục về phía bên 
 phải. 1 Pipe sẽ có hai pipe nhỏ ở trên và ở dưới, hai pipe nhỏ này sẽ ngăn cách bởi 1 khoảng trắng .

-Ground là đối tượng nằm ở dưới cùng màn hình và cũng di chuyển liên tục về bên trái. -Ngoài ra còn có
 các đói tượng khác như Background, Score, Tree( trong phần cải tiến game),...

2.Mô tả lối chơi và cách vận hành game
-Dao diện Menu gồm hai lựa chọn "Start" và "Exit". Khi nhấn "Start" sẽ bắt đầu màn chơi, khi nhán "Exit" 
 sẽ thoát game. Ngoài ra dao diện Menu còn có lựa chọn "rate" để xem điểm cao được lưu lại.

-Trong suốt một màn chơi, người chơi sẽ điều khiển Bird bay lên bay xuông để tránh các Pipe đang di chuyển 
 tới. Bird sẽ bay lên khi nhấn phím "Space", và sẽ bay xuống khi nhả tay.Trong suốt màn chơi có thể nhấn 
 phím "x" để tạm dừng .

-Mỗi lần Bird vượt qua 1 Pipe thì score sẽ +1.

-Bird sẽ chết khi va chạm với các Pipe và Ground.Khi đó màn chơi sẽ kết thúc, hiển thị điểm của người chơi
 và dao diện GameOver.

-GameOver gồm điểm màn chơi vừa rồi, medal đánh giá dựa trên số điểm đó, hai lựa chọn "Menu" và "Replay". 
 Khi nhấn "Menu" sẽ quay về dao diện Menu, khi nhấn "Replay" sẽ bắt đầu màn chơi mới.

3.Trình tự phát triển game
-Xây dựng phiên bản sơ khai của game: 
+Di chuyển Bird theo sự điều khiển của người chơi 
+Các Pipe và Ground di chuyển liên tục sang trái +Các hàm xử lí va chạm, tính điểm ...

-Cải tiến đồ họa 
+Tạo hiệu ứng chuyển động khi di chuyển của Bird. 
+Tạo hiệu ứng chuyển động của Background 
+Tạo hiệu ứng khi đượ cộng điểm 
+Thêm các hiệu ứng âm thanh

-Xây dựng các dao diện 
+Xây dựng dao diện Menu, GameOver, ... 
+Thêm nhạc nền cho game

-Cải tiến game 
+Thay đổi cơ chế hoạt động của các Pipe: ngẫu nhiên xuất hiện các Tree từ trong các Pipe (?????) 
+Tạo một đối tượng BOSS để "phá đảo" game(?????) 
............

-Xây dựng các dao diện +Xây dựng dao diện Menu, GameOver, ... +Thêm nhạc nền cho game

-Cải tiến game +Thay đổi cơ chế hoạt động của các Pipe: ngẫu nhiên xuất hiện các Tree từ các Pipe (?????) +Tạo một đối tượng BOSS để "phá đảo" game(?????) ............