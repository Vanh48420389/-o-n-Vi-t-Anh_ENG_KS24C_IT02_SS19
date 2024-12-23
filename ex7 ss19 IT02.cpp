#include <stdio.h>
#include <string.h>

struct sinhVien {
    int id;
    char name[100];
    int age;
    char phoneNumber[20];
};

void SinhVien(struct sinhVien sv[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Id: %d, Name: %s, Tuoi: %d, Sdt: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}

void deleteSinhVien(int id, struct sinhVien sv[], int *size) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (sv[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*size)--;
            printf("Da xoa sinh vien voi ID: %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
    }
}

int main() {
    struct sinhVien sv[5] = {
        {1, "Lionel Messi", 37, "01234567"},
        {2, "Neymar Junior", 32, "12378901"},
        {3, "Luis Suarez", 37, "34598712"},
        {4, "Zlatan Ibrahimovic", 43, "66666666"},
        {5, "Cristiano Ronaldo", 39, "12387645"}
    };
    int currentLength = 5;

    printf("Danh sach sinh vien ban dau:\n");
    SinhVien(sv, currentLength);

    int xoaSinhVien;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &xoaSinhVien);

    deleteSinhVien(xoaSinhVien, sv, &currentLength);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    SinhVien(sv, currentLength);

    return 0;
}

