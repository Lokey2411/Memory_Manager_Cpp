#include <windows.h>
#include <iostream>

int main() {
    // Cấp phát một khối bộ nhớ toàn cục
    HGLOBAL hMem = GlobalAlloc(GMEM_FIXED, 100 * sizeof(int));
    if (hMem == NULL) {
        std::cout << "Global memory allocation failed\n";
        return 1;
    }

    // Sử dụng bộ nhớ
    int* arr = (int*)hMem;
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Giải phóng bộ nhớ
    GlobalFree(hMem);
    system("pause");

    return 0;
}
