# Bài 1 

Dự án điều khiển LED bằng nút nhấn sử dụng thư viện **OneButton** trên nền tảng **PlatformIO**.

## Tính năng
- **Nhấn 1 lần:** Bật / Tắt LED.
- **Nhấn 2 lần liên tục:** Chuyển sang chế độ nháy LED (Chu kỳ 500ms).


##  Kết nối phần cứng
- **Nút nhấn:** Chân D2 <-> GND
- **LED:** Chân D13 <-> GND (qua điện trở 220Ω).

##  Nền tảng & Thư viện
- **IDE / Environment:** VS Code + PlatformIO
- **Library:** [OneButton](https://github.com/mathertel/OneButton)

# Bài 2
Dự án điều khiển 2 LED (1 LED tích hợp + 1 LED mở rộng) bằng duy nhất 1 nút nhấn thông qua thư viện **OneButton** trên nền tảng **PlatformIO**.

##  Tính năng 

- **Double Click (Nhấn kép):** Chuyển đổi chọn mục tiêu điều khiển giữa **LED 1** và **LED 2**.
- **Single Click (Nhấn đơn):** Bật / Tắt LED hiện tại đang được chọn.
- **Press & Hold (Giữ nút):** Bật / Tắt chế độ nhấp nháy 200ms đối với LED đang chọn.
- **Non-blocking Code:** Sử dụng `millis()` xử lý nhấp nháy độc lập cho từng LED, nút nhấn phản hồi tức thì.

## Sơ đồ kết nối phần cứng

| Linh kiện | Chân vi điều khiển (GPIO) | Ghi chú |
| :--- | :--- | :--- |
| **Nút nhấn (Button)** | GPIO 2 | Nối với GND (Dùng Pull-up nội) |
| **LED 1** | GPIO 13 | LED tích hợp (Built-in) |
| **LED 2** | GPIO 4 | LED cắm ngoài qua trở 220Ω xuống GND |

##  Cài đặt & Sử dụng

1. Mở dự án trong **VS Code** có cài sẵn extension **PlatformIO**.
2. Kết nối bo mạch Arduino/ESP32 qua cổng USB.
3. Nhấn nút **Upload** (Mũi tên `➔` ở thanh công cụ phía dưới) để nạp code.
