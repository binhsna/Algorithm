#include <iostream> 
using namespace std;

int N = 7; /* So phan tu cua heap */
void max_heap(int A[], int i) {
    int largest; /* Chi so cua phan tu lon nhat trong bo ba: node hien tai
                         con bên trái, và con bên phai cua nó */
    int left = 2 * i; /* Vi trí cua con bên trái */
    int right = 2 * i + 1; /* Vi trí cua con bên phai */
    if (left <= N and A[left] > A[i]) /* N là so phan tu trong mang, bien toàn cuc */
        largest = left;
    else
        largest = i;
    if (right <= N and A[right] > A[largest])
        largest = right;
    if (largest != i) {
        swap(A[i], A[largest]); /* Thuc hien doi cho hai phan tu neu gia tri cua node cha nho hon node con */
        max_heap(A, largest); /* Goi de quy node tai vi tri moi */
    }
}

void run_maxheap(int A[]) { /* Ap dung ham max_heap cho tat ca cac node tru node lá */
    for (int i = N / 2; i >= 1; i--) {
        max_heap(A, i);
    }
}

int main() {
    int A[N+1] = {-1,1,4,3,7,8,9,10}; /* Mang chua 8 phan tu, voi phan tu 
                                                       cua heap bat dau tu vi tri 1 toi N
                                                       phan tu dau tien cua mang chi co tac
                                                       dung lam lap day mang, giá tri bat ki */
    printf("\n\tGia tri cua mang sau khi ap dung hàm max_heap\n");
    for (int i = 0; i < N+1; i++) { /* In ra gia tri cua mang sau khi sap xep voi ham max_heap */
        printf("\t%d ", A[i]);
    }

    return 0;
}
