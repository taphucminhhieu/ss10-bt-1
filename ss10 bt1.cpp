#include <stdio.h>
#include <string.h>

#define MAX_VE 100
#define MAX_VE_PER_ORDER 4

struct VeBan {
    int maVe;
    char tenKhuVuc[20];
    float giaGoc;
    int isEarlyBird;
};

int datVeConcert(struct VeBan dsVe[], int soLuong, struct VeBan veMoi);
void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong);

int main() {
    struct VeBan dsVe[MAX_VE];
    int soLuong = 0;
    
    printf("=== H? TH?NG Ð?T VÉ CONCERT TICKETBOX ===\n\n");

    struct VeBan ve1 = {101, "VIP", 2000000.0f, 1};
    struct VeBan ve2 = {102, "Zone A", 1200000.0f, 0};
    struct VeBan ve3 = {103, "GA", 800000.0f, 0};
    struct VeBan ve4 = {104, "GA", 800000.0f, 1};
    struct VeBan ve5 = {105, "VIP", 2000000.0f, 0};

    soLuong = datVeConcert(dsVe, soLuong, ve1);
    soLuong = datVeConcert(dsVe, soLuong, ve2);
    soLuong = datVeConcert(dsVe, soLuong, ve3);
    soLuong = datVeConcert(dsVe, soLuong, ve4);
    soLuong = datVeConcert(dsVe, soLuong, ve5);

    printf("\n>>> K?T QU? KI?M TRA GI? HÀNG TRONG MAIN <<<\n");
    hienThiDanhSachVe(dsVe, soLuong);

    return 0;
}

int datVeConcert(struct VeBan dsVe[], int soLuong, struct VeBan veMoi) {
    if (soLuong >= MAX_VE) {
        printf("[L?I]: M?ng luu tr? vé c?a h? th?ng dã d?y!\n");
        return soLuong;
    }

    if (soLuong >= MAX_VE_PER_ORDER) {
        printf("[L?I]: Vu?t quá h?n ng?ch t?i da %d vé cho m?t l?n giao d?ch!\n", MAX_VE_PER_ORDER);
        return soLuong;
    }

    if (veMoi.isEarlyBird == 1) {
        veMoi.giaGoc = veMoi.giaGoc * 0.85f;
    }

    dsVe[soLuong] = veMoi;
    soLuong++;
    printf("[THÀNH CÔNG]: Ðã thêm vé %d (%s) vào don hàng.\n", veMoi.maVe, veMoi.tenKhuVuc);
    
    return soLuong;
}

void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong) {
    if (soLuong == 0) {
        printf("[THÔNG BÁO]: Hi?n chua có vé nào du?c d?t thành công trong h? th?ng!\n");
        return;
    }
    
    printf("--- DANH SÁCH VÉ ÐÃ Ð?T (%d vé) ---\n", soLuong);
    for (int i = 0; i < soLuong; i++) {
        printf("STT: %d | Mã vé: %d | Khu v?c: %s | Giá thanh toán: %.0f VND\n",
               i + 1, dsVe[i].maVe, dsVe[i].tenKhuVuc, dsVe[i].giaGoc);
    }
}
