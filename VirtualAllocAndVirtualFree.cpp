#include <windows.h>
#include <iostream>

class MemoryManager {
public:
    // Hàm cấp phát bộ nhớ
    LPVOID allocate(SIZE_T size) {
        LPVOID lpvBase = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
        if (lpvBase == NULL) {
            std::cout << "Memory allocation failed\n";
            return NULL;
        }
        return lpvBase;
    }

    // Hàm giải phóng bộ nhớ
    BOOL deallocate(LPVOID lpvBase) {
        if (VirtualFree(lpvBase, 0, MEM_RELEASE) == 0) {
            std::cout << "Memory deallocation failed\n";
            return FALSE;
        }
        return TRUE;
    }
};

int main() {
    MemoryManager mm;

    // Cấp phát bộ nhớ cho mảng 10 phần tử
    int* arr = (int*)mm.allocate(10 * sizeof(int));

    // Kiểm tra nếu việc cấp phát bộ nhớ thành công
    if (arr != NULL) {
        // Sử dụng mảng
        for (int i = 0; i < 10; i++) {
            arr[i] = i;
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Giải phóng bộ nhớ
        mm.deallocate(arr);
    }

    return 0;
}
