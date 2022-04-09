// External_sort_RUN.cpp
#include <iostream>
#include <fstream>
using namespace std;
void import_file();
void export_file();
void reimport();
void run_merging();
void nature_merging();
void balanced_multiway_merging();
void distribute_file_run(int m);
void distribute_file_nature(int arr[], int z);
void distribute_file_balanced();
void merge_file_run(int m);
void merge_file_nature();
void merge_file_balanced();
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int m, n, arr[10000], length_run_f1, length_run_f2, run_f1[10000], run_f2[10000];
fstream f0, f1, f2;
int main()
{
    import_file();
    cout << "----------------------------" << endl << "File ban dau: ";
    export_file();
    cout << endl << "File co " << n << " phan tu!";
    cout << endl << "----------------------------";
    while (1) {
        int method;
        cout << "\nCac phuong phap thuc hien:\n1.Phuong phap tron RUN!\n2.Phuong phap tron tu nhien!\n3.Phuong phap tron da loi can bang!\nNhap 0 khi muon ket thuc chuong trinh!";
        cout << "\nMoi chon phuong phap thuc hien: ";
        cin >> method;
        if (method == 0) {
            cout << "\n----------------------------// Chuong trinh ket thuc! //----------------------------";
            break;
        }
        switch (method) {
            cin >> method;
        case 1: {
            cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron Run  //----------\n";
            reimport();
            run_merging();
            break;
        }
        case 2: {
            cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron tu nhien//  ----------\n";
            reimport();
            nature_merging();
            break;
        }
        case 3: {
            cout << "\n----------//  Duoi day la qua trinh thuc hien phuong phap tron da loi can bang  //----------\n";
            reimport();
            balanced_multiway_merging();
            break;
        }
        default:
            break;
        }
    }
}
void run_merging(){
    m = 1;
    int i = m;
    int count = 0;
    while (i < n) {
        count++;
        i = i * 2;
    }
    cout << "f0: File input, output\nf1: File tam thu nhat\nf2: File tam thu hai";
    cout << endl << "n: So luong phan tu co trong f0\nm: So phan tu duoc chia vao moi file tam sau moi lan chia!" << endl << "Qua trinh chia va tron file ke tiep se co gia tri m gap doi qua trinh lien truoc!" << endl << "Viec chia va tron file ket thuc khi m >= n!" << endl << "----------------------------";
    cout << endl << "File f0 co " << n << " phan tu thi co tat ca " << count << " lan tron." << endl << "----------------------------";
    count = 0;
    while (m < n) {
        cout << endl << "Ket qua 2 file tam sau khi chia lan thu " << count + 1 << " voi gia tri m = " << m << ".";
        distribute_file_run(m);
        merge_file_run(m);
        cout << endl << "File f0 sau khi tron file f1 va f2 lan thu " << count + 1 << " : ";
        export_file();
        count++;
        cout << endl << "----------------------------";
        m = m * 2;
        int maximum = max(m, n);
        if (maximum == m) cout << endl << "Voi m = " << m << " > n => Ket thuc viec chia file, dua ra output va ket thuc chuong trinh!";
    }
    cout << endl << "----------------------------" << endl;
    cout << "Ket qua cuoi cung sau khi qua trinh chia va tron file ket thuc:\nf0: ";
    export_file();
    cout << "\n----------//  Phuong phap tron Run ket thuc  //----------\n";
}
void nature_merging() {
    cout << "f0: File input, output\nf1: File tam thu nhat\nf2: File tam thu hai";
    cout << endl << "n: So luong phan tu co trong f0\nTan dung duoc tat ca cac RUN dai nhat co trong f0 trong khi chia du lieu\nViec chia va tron ket thuc khi trong f0 chi con duy nhat 1 RUN\n----------------------------";
    int distribute_numb = 0;
    while (n) {
        f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::in);
        char a[10000];
        int arr[10000], i = 0;
        while (f0 >> a) {
            arr[i] = atoi(a);
            i++;
        }
        f0.close();
        int count = 1, j = 0;
        for (j; j < i - 1; j++) {
            if (arr[j] > arr[j + 1])
                count++;
        }
        if (count == 1) {
            cout << "\nSo luong RUN con lai trong f0 = " << 1 << " => Ket thuc viec chia file, dua ra output va ket thuc chuong trinh!\n----------------------------";
            break;
        }
        cout << "\nKet qua 2 file tam sau khi chia lan thu " << distribute_numb + 1;
        distribute_file_nature(arr, i);
        merge_file_nature();
        cout << endl<<"File f0 sau khi tron file f1 va f2 lan thu "<<distribute_numb + 1<<" : ";
        export_file();
        cout << "\n----------------------------";
        distribute_numb++;
    }
    cout << endl << "Ket qua cuoi cung sau khi qua trinh chia va tron ket thuc:\nf0: ";
    export_file();
    cout << "\n----------//  Phuong phap tron tu nhien ket thuc  //----------\n";
}
void balanced_multiway_merging() {

}
void import_file() {
    int i, x;
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::out | ios::trunc);
    if (f0.is_open()) {
        cout << "Mo file thanh cong!\n" << "----------------------------" << endl;
        cout << "Chon so luong phan tu co trong file: ";
        cin >> n;
        cout << "Nhap cac phan tu co trong file:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            f0 << arr[i] << " ";
        }
        f0.close();
    }
    else
        cout << "Mo file khong thanh cong!";
}
void export_file() {
    int x;
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::in);
    int i = 0;
    char a[10000];
    while (f0 >> a) {
        cout << a << " ";
    }
    f0.close();
}
void reimport() {
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::out | ios::trunc);
    for (int i = 0; i < n; i++)
        f0 << arr[i] << " ";
    f0.close();
}
void distribute_file_run(int m) {
    int count, x = 0;
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::in);
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::out | ios::trunc);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::out | ios::trunc);
    char a[10000];
    int arr[10000], i = 0;
    while (f0 >> a) {
        arr[i] = atoi(a);
        i++;
    }
    cout << endl;
    for (int j = 0; j <= i; j++) {
        count = 0;
        for (x; x < i; x++) {
            f1 << arr[x] << " ";
            count++;
            if (count == m)
                break;
        }
        count = 0;
        x++;
        for (x; x < i; x++) {
            f2 << arr[x] << " ";
            count++;
            if (count == m)
                break;
        }
        x++;
        j = x;
    }
    f0.close();
    f1.close();
    f2.close();
    char b[10000], c[10000];
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::in);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::in);
    cout << "f1: ";
    while (f1 >> b) {
        cout << b << " ";
    }
    cout << endl << "f2: ";
    while (f2 >> c) {
        cout << c << " ";
    }
    f1.close();
    f2.close();
}
void distribute_file_nature(int arr[], int z) {
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::out | ios::trunc);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::out | ios::trunc);
    int i = 0;
    length_run_f1 = 0;
    length_run_f2 = 0;
    while (i < z) {
        int temp = 0;
        for (i; i < z; i++) {
            f1 << arr[i] << " ";
            temp++;
            if (arr[i] > arr[i + 1])
                break;
        }

        run_f1[length_run_f1] = temp;
        length_run_f1++;
        temp = 0;
        i++;
        for (i; i < z; i++) {
            f2 << arr[i] << " ";
            temp++;
            if (arr[i] > arr[i + 1])
                break;
        }
        if (temp != 0) {
            run_f2[length_run_f2] = temp;
            length_run_f2++;
        }
        i++;
    }
    f1.close();
    f2.close();
    char b[10000], c[10000];
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::in);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::in);
    cout << "\nf1: ";
    while (f1 >> b) {
        cout << b << " ";
    }
    cout << endl << "f2: ";
    while (f2 >> c) {
        cout << c << " ";
    }
    f1.close();
    f2.close();
}
void distribute_file_balanced() {

}
void merge_file_run(int m) {
    int count;
    int stop, x = 0, y = 0;
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::out);
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::in);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::in);
    char a[10000], b[10000];
    int c[10000], arr_f1[10000], arr_f2[10000], i = 0, j = 0;
    while (f1 >> a) {
        arr_f1[i] = atoi(a);
        i++;
    }
    while (f2 >> b) {
        arr_f2[j] = atoi(b);
        j++;
    }
    f1.close();
    f2.close();
    int num_c = 0;
    for (int temp = 0; temp <= i; temp++) {
        count = 0;
        for (x; x < i; x++) {
            c[num_c] = arr_f1[x];
            num_c++;
            count++;
            if (count == m)
                break;
        }
        x++;
        count = 0;
        for (y; y < j; y++) {
            c[num_c] = arr_f2[y];
            num_c++;
            count++;
            if (count == m)
                break;
        }
        y++;
        temp = x;
        merge_sort(c, 0, num_c - 1);
        for (int h = 0; h < num_c; h++)
            f0 << c[h] << " ";
        num_c = 0;
    }
    f0.close();
}
void merge_file_nature() {
    f0.open("C:\\Users\\leqh2\\Desktop\\f0.txt", ios::out);
    f1.open("C:\\Users\\leqh2\\Desktop\\f1.txt", ios::in);
    f2.open("C:\\Users\\leqh2\\Desktop\\f2.txt", ios::in);
    char a[10000], b[10000];
    int c[10000], arr_f1[10000], arr_f2[10000], length_f1 = 0, length_f2 = 0;
    while (f1 >> a) {
        arr_f1[length_f1] = atoi(a);
        length_f1++;
    }
    while (f2 >> b) {
        arr_f2[length_f2] = atoi(b);
        length_f2++;
    }
    f1.close();
    f2.close();
    int z = max(length_run_f1, length_run_f2);
    int i = 0, j = 0, count, numb_c = 0;
    for (int length = 0; length <= z; length++) {
        count = 0;
        for (i; i < length_f1; i++) {
            c[numb_c] = arr_f1[i];
            numb_c++;
            count++;
            if (count == run_f1[length])
                break;
        }
        i++;
        count = 0;
        for (j; j < length_f2; j++) {
            c[numb_c] = arr_f2[j];
            numb_c++;
            count++;
            if (count == run_f2[length])
                break;
        }
        j++;
        merge_sort(c, 0, numb_c - 1);
        for (int x = 0; x < numb_c; x++)
            f0 << c[x] << " ";
        numb_c = 0;
    }
    f0.close();
}
void merge_file_balanced() {

}
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[10000], R[10000];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}