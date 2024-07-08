#include <iostream> 
using namespace std;

int n = 7; /* So phan tu cua heap */
void MaxHeap(int H[], int i) {
    int max; /* Chi so cua phan tu lon nhat trong bo ba: node hien tai
                         con bên trái, và con bên phai cua nó */
    int Lchild = 2 * i; /* Vi trí cua con bên trái */
    int Rchild = 2 * i + 1; /* Vi trí cua con bên phai */
    if (Lchild <= n and H[Lchild] > H[i]) /* N là so phan tu trong mang, bien toàn cuc */
        max = Lchild;
    else
        max = i;
    if (Rchild <= n and H[Rchild] > H[max])
        max = Rchild;
    if (max != i) {
        swap(H[i], H[max]); /* Thuc hien doi cho hai phan tu neu gia tri cua node cha nho hon node con */
        MaxHeap(H, max); /* Goi de quy node tai vi tri moi */
    }
}

void TaoMaxHeap(int H[]) { /* Ap dung ham MaxHeap cho tat ca cac node tru node lá */
    for (int i = n / 2; i >= 1; i--) {
        MaxHeap(H, i);
    }
}

int main() {
    int H[n+1] = {-1,4,5,6,7,8,9,10}; /* Mang chua 8 phan tu, voi phan tu 
                                                       cua heap bat dau tu vi tri 1 toi N
                                                       phan tu dau tien cua mang chi co tac
                                                       dung lam lap day mang, giá tri bat ki */
    TaoMaxHeap(H);
    cout<<"\nGia tri cua mang sau khi ap dung ham MaxHeap\n";
    for (int i = 1; i < n+1; i++) { /* In ra gia tri cua mang sau khi sap xep voi ham Maxheap */
        cout<<" "<<H[i];
    }

    return 0;
}
