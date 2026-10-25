CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Thư mục chứa mã nguồn và header
SRC_DIR = src
INC_DIR = include

# Danh sách các file nguồn .cpp (bao gồm cả main.cpp nếu bạn để ở src, hoặc điều chỉnh đường dẫn nếu ở tests)
# Ở đây giả định main.cpp đặt trong src/ hoặc bạn có thể thay đổi đường dẫn cho phù hợp
SRCS = tests/main.cpp $(SRC_DIR)/AVLTree.cpp $(SRC_DIR)/menu.cpp

# Tên file thực thi sau khi build
TARGET = library_app

# Quy tắc mặc định khi gõ lệnh 'make'
all: $(TARGET)

$(TARGET): $(SRCS)
 $(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Dọn dẹp các file rác hoặc file build cũ
clean:
 rm -f $(TARGET)

# Chạy chương trình nhanh sau khi build
run: all
 ./$(TARGET)

