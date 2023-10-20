#include <windows.h>
#include <iostream>

int main() {
    MEMORYSTATUSEX statex;
    char bytesUnit[] = "GB";
    const int bytesUnitChange = 1024*1024*1024;
    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    std::cout << "Co " << statex.dwMemoryLoad << " % bo nho dang duoc su dung.\n";
    std::cout << "Co tong cong " << statex.ullTotalPhys/bytesUnitChange << bytesUnit <<"   bo nho vat ly.\n";
    std::cout << "Con lai " << statex.ullAvailPhys/bytesUnitChange << bytesUnit<<"   trong bo nho vat ly.\n";
    std::cout << "Co tong cong " << statex.ullTotalPageFile/bytesUnitChange << bytesUnit<< "  trong tep trang.\n";
    std::cout << "Con lai " << statex.ullAvailPageFile/bytesUnitChange << bytesUnit<<"  trong tep trang.\n";
    std::cout << "Co tong cong " << statex.ullTotalVirtual/bytesUnitChange  <<bytesUnit<< "  trong bo nho ao.\n";
    std::cout << "Con lai " << statex.ullAvailVirtual/bytesUnitChange  << bytesUnit<<" trong bo nho ao.\n";

    return 0;
}
