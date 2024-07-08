#include <iostream> 
using namespace std;

int n = 7; /* So phan tu cua mang H */
void MinHeap(int H[], int i) {
    int min; // Chi so cua phan tu nho nhat trong bo ba: nut i, 2*i va 2*i+1
    int Lchild = 2 * i; /* Vi trí cua con bên trái */
    int Rchild = 2 * i + 1; /* Vi trí cua con bên phai */
    if (Lchild <= n and H[Lchild] < H[i]) /* N là so phan tu trong mang, bien toàn cuc */
        min = Lchild;
    else
        min = i;
    if (Rchild <= n and H[Rchild] < H[min])
        min = Rchild;
    if (min != i) {
        swap(H[i], H[min]); // Doi cho neu nut cha > nut con
        MinHeap(H, min); // Goi de quy node tai vi tri moi 
    }
}

void TaoMinHeap(int H[]) { /* Ap dung ham MinHeap cho tat ca cac node tru node lá */
    for (int i = n / 2; i >= 1; i--) {
        MinHeap(H, i);
    }
}

int main() {
    int H[n+1] = {-1,9,10,7,5,8,4,2}; /* Mang chua 8 phan tu, voi phan tu 
                                                       cua heap bat dau tu vi tri 1 toi N
                                                       phan tu dau tien cua mang chi co tac
                                                       dung lam lap day mang, giá tri bat ki */
    TaoMinHeap(H);
    cout<<"\nGia tri cua mang sau khi ap dung ham MinHeap\n";
    for (int i = 1; i < n+1; i++) { /* In ra gia tri cua mang sau khi sap xep voi ham MinHeap */
        cout<<" "<<H[i];
    }

    return 0;
}
